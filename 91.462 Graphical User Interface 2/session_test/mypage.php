<?php
define('INCLUDE_CHECK', true);

require 'connect.php';
require 'functions.php';

session_name('tzLogin');
session_set_cookie_params(2*7*24*60*60);
session_start();
if ($_SESSION['id'] && !isset($_COOKIE['tzRemember']) && !$_SESSION['rememberMe']) {
    // If you are logged in, but you don't have the tzRemember cookie (browser restart)
    // and you have not checked the rememberMe checkbox:

    $_SESSION = array();
    session_destroy();

    // Destroy the session
}


if (isset($_GET['logoff'])) {
    $_SESSION = array();
    session_destroy();

    header("Location: mypage.php");
    exit;
}

if ($_POST['submit'] == 'Login') {
    // Checking whether the Login form has been submitted

    $err = array();
    // Will hold our errors


    if (!$_POST['username'] || !$_POST['password'])
        $err[] = 'All the fields must be filled in!';

    if (!count($err)) {
        $_POST['username'] = mysql_real_escape_string($_POST['username']);
        $_POST['password'] = mysql_real_escape_string($_POST['password']);
        $_POST['rememberMe'] = (int) $_POST['rememberMe'];

        // Escaping all input data

        $row = mysql_fetch_assoc(mysql_query("SELECT id,usr FROM tz_members WHERE usr='{$_POST['username']}' AND pass='" . md5($_POST['password']) . "'"));

        if ($row['usr']) {
            // If everything is OK login

            $_SESSION['usr'] = $row['usr'];
            $_SESSION['id'] = $row['id'];
            $_SESSION['rememberMe'] = $_POST['rememberMe'];

            // Store some data in the session

            setcookie('tzRemember', $_POST['rememberMe']);
        } else
            $err[] = 'Wrong username and/or password!';
    }

    if ($err)
        $_SESSION['msg']['login-err'] = implode('<br />', $err);
    // Save the error messages in the session

    header("Location: mypage.php");
    exit;
}
else if ($_POST['submit'] == 'Register') {
    // If the Register form has been submitted

    $err = array();

    if (strlen($_POST['username']) < 4 || strlen($_POST['username']) > 32) {
        $err[] = 'Your username must be between 3 and 32 characters!';
    }

    if (preg_match('/[^a-z0-9\-\_\.]+/i', $_POST['username'])) {
        $err[] = 'Your username contains invalid characters!';
    }

    if (!checkEmail($_POST['email'])) {
        $err[] = 'Your email is not valid!';
    }

    if (!count($err)) {
        // If there are no errors

        $pass = substr(md5($_SERVER['REMOTE_ADDR'] . microtime() . rand(1, 100000)), 0, 6);
        // Generate a random password

        $_POST['email'] = mysql_real_escape_string($_POST['email']);
        $_POST['username'] = mysql_real_escape_string($_POST['username']);
        // Escape the input data


        mysql_query(" INSERT INTO tz_members(usr,pass,email,regIP,dt)
						VALUES(
											
															  '" . $_POST['username'] . "',
															       			      '" . md5($pass) . "',
																		      	   	      	  '" . $_POST['email'] . "',
																					       		       	   '" . $_SERVER['REMOTE_ADDR'] . "',
																								      				    NOW()
																												          
																													       )");

        if (mysql_affected_rows($link) == 1) {
            send_mail('demo-test@tutorialzine.com', $_POST['email'], 'Registration System Demo - Your New Password', 'Your password is: ' . $pass);

            $_SESSION['msg']['reg-success'] = 'We sent you an email with your new password!';
        } else
            $err[] = 'This username is already taken!';
    }

    if (count($err)) {
        $_SESSION['msg']['reg-err'] = implode('<br />', $err);
    }

    header("Location: mypage.php");
    exit;
}
$script = '';
if ($_SESSION['msg']) {
$script = '
	<script type="text/javascript">	
	  $(function(){
		$("div#panel").show();
		$("#toggle a").toggle();
	});
        </script>';
}
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>NC BookStack - My Profile</title>
<link rel="stylesheet" type="text/css" href="demo.css" media="screen" />
<link rel="stylesheet" type="text/css" href="login_panel/css/slide.css" media="screen" />

<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.3.2/jquery.min.js"></script>

        <!-- PNG FIX for IE6 -->
        <!-- http://24ways.org/2007/supersleight-transparent-png-in-ie6 -->
        <!--[if lte IE 6]>
            <script type="text/javascript" src="login_panel/js/pngfix/supersleight-min.js"></script>
        <![endif]-->

<script src="login_panel/js/slide.js" type="text/javascript"></script>
<?php echo $script; ?>
</head>

<body>

        <!-- Panel -->
        <div id="toppanel">
            <div id="panel">
                <div class="content clearfix">
                    <!--<div class="left">
                        <h1>NC BookStack</h1>
                        <h2></h2>		
                        <p class="grey">You are free to use this login and registration system in you sites!</p>
                    </div>-->


        <?php
        if (!$_SESSION['id']):
            ?>

                        <div class="left">
                            <!-- Login Form -->
                            <form class="clearfix" action="" method="post">
                                <h1>Login</h1>

    <?php
    if ($_SESSION['msg']['login-err']) {
        echo '<div class="err">' . $_SESSION['msg']['login-err'] . '</div>';
        unset($_SESSION['msg']['login-err']);
    }
    ?>

                                <label class="grey" for="username">Username:</label>
                                <input class="field" type="text" name="username" id="username" value="" size="23" />
                                <label class="grey" for="password">Password:</label>
                                <input class="field" type="password" name="password" id="password" size="23" />
                                <label><input name="rememberMe" id="rememberMe" type="checkbox" checked="checked" value="1" /> &nbsp;Remember me</label>
                                <div class="clear"></div>
                                <input type="submit" name="submit" value="Login" class="bt_login" />
                            </form>
                        </div>
                        <div class="left right">			
                            <!-- Register Form -->
                            <form action="" method="post">
                                <h1>Not a member yet? Sign Up!</h1>		

                                <?php
                                if ($_SESSION['msg']['reg-err']) {
                                    echo '<div class="err">' . $_SESSION['msg']['reg-err'] . '</div>';
                                    unset($_SESSION['msg']['reg-err']);
                                }

                                if ($_SESSION['msg']['reg-success']) {
                                    echo '<div class="success">' . $_SESSION['msg']['reg-success'] . '</div>';
                                    unset($_SESSION['msg']['reg-success']);
                                }
                                ?>

                                <label class="grey" for="username">Username:</label>
                                <input class="field" type="text" name="username" id="username" value="" size="23" />
                                <label class="grey" for="email">Email:</label>
                                <input class="field" type="text" name="email" id="email" size="23" />
                                <label>A password will be e-mailed to you.</label>
                                <input type="submit" name="submit" value="Register" class="bt_register" />
                            </form>
                        </div>

                                <?php
                            else:
                                ?>

                        <div class="left">

                            <h1>Welcome!</h1>

                            <p><a href="http://weblab.cs.uml.edu/~cburbine/session_test/home.php">Home</a> | 
			    <a href="http://weblab.cs.uml.edu/~cburbine/session_test/mypage.php">My Profile</a> | 
			    <a href="#">New Message</a></p>  
			    
                            <p>- - -</p>
                            <a href="?logoff">Log off</a>

                        </div>

                        <div class="left right">
                        </div>
			<script src="autoComp.js"></script>
			<div class="search">
			<h1>Search for</h1>
			<br>
			<form name="search" method="post" action="http://weblab.cs.uml.edu/~nwarren/search.php">
    		
    			<!--Search value -->
    			<input type="text" name="find" id="find"> in
    			<!--Category to search in-->
    			<select name="field" id="searchCriteria">
        		<option value="title">Title</option>
        		<option value="edition">Edition</option>
        		<option value="author">Author</option>
        		<option value="price">Price</option>
        		<option value="subject_number">Subject</option>
        		<option value="class_number">Class</option>
        		<option value="isbn">ISBN Number</option>
    			</select>
    			<input type="submit" name="search" value="Search" />
			</form>
			
			</div>

<?php
endif;
?>
                </div>
            </div> <!-- /login -->	

            <!-- The tab on top -->	
            <div class="tab">
                <ul class="login">
                    <li class="left">&nbsp;</li>
                    <li>Hello <?php echo $_SESSION['usr'] ? $_SESSION['usr'] : 'Guest'; ?>!</li>
                    <li class="sep">|</li>
                    <li id="toggle">
                        <a id="open" class="open" href="#"><?php echo $_SESSION['id'] ? 'Open Panel' : 'Log In | Register'; ?></a>
                        <a id="close" style="display: none;" class="close" href="#">Close Panel</a>    	    
                    </li>
                    <li class="right">&nbsp;</li>
                </ul> 
            </div> <!-- / top -->

        </div> <!--panel -->

  <div id="main">
    <div class="container">
      <h1>My Profile</h1>
    </div>
    <div class="container">
      <?php
        if($_SESSION['id']){
	   $user = $_SESSION['usr'];
	   #echo $_SESSION['usr'];
	   $data = mysql_query("SELECT * FROM tz_members WHERE usr LIKE'%$user%'")or die('Error: '.mysql_error());	   
	   if(!$data){
	     echo 'Could not run: '.mysql_error();
	     exit;
	   }
	   while($result = mysql_fetch_array($data)){
	     echo '<p><strong>Username</strong>: '   .$result['usr'].  '</p>';
	     echo '<p><strong>Email</strong>: '      .$result['email'].'</p>';
	     
	   }
	echo '<div class="container">';
	echo '<h3><strong>Books for Sale</strong></h3>';
	$book_data = mysql_query("SELECT * FROM books_for_sale WHERE seller LIKE'%$user%'")or die('Error: '.mysql_error());

	if(!$book_data){
           echo 'Could not run: '.mysql_error();
           exit;
        }
	while($result = mysql_fetch_array($book_data)){
	 $isbn = $result['isbn'];
	 $asking_price = $result['asking_price'];
	 echo '<div class="container">';
	 echo '<strong>Asking Price</strong>: $'. $asking_price. '<br>';
	 $slice_data = mysql_query("SELECT * FROM bookslice1 WHERE isbn LIKE'%$isbn%'")or die('Error: '.mysql_error());
	 while($result_inner = mysql_fetch_array($slice_data)){
            echo '<strong>Title</strong>: '.$result_inner['title'];
            echo '<br>';
            echo '<strong>Edition</strong>: '.$result_inner['edition'];
            echo '<br>';
            echo '<strong>Author(s)</strong>: '.$result_inner['author'];
            echo '<br>';
            echo '<strong>Class Number</strong>: '.$result_inner['subject_number'].'.'.$result_inner['class_number'];
            echo '<br>';
            echo '<strong>ISBN</strong>: '.$result_inner['isbn'];
            echo '<br>';
	    }
	    echo '</div>';
	}
	echo '</div>';

	echo '<div class="container">';
	echo '<h3><strong>Wanted Books</strong></h3>';
	$wanted_data = mysql_query("SELECT * FROM wanted_books WHERE buyer LIKE '%$user%'")or die ('Error: '.mysql_error());
	#echo $wanted_data;
	
	if(!$wanted_data){
	  echo 'Could not run: '.mysql_error();
	}
	
	while($result = mysql_fetch_array($wanted_data)){
	  $isbn2 = $result['isbn'];
	  #echo $isbn2;
	  echo '<div class="container">';
	  $slice_data = mysql_query("SELECT * FROM bookslice1 WHERE isbn LIKE'%$isbn2%'")or die('Error slice: '.mysql_error());
	  #echo 'here';
	  #echo $slice_data.'<br>';
	  while($result_inner = mysql_fetch_array($slice_data)){
            echo '<strong>Title</strong>: '.$result_inner['title'];
            echo '<br>';
            echo '<strong>Edition</strong>: '.$result_inner['edition'];
            echo '<br>';
            echo '<strong>Author(s)</strong>: '.$result_inner['author'];
            echo '<br>';
            echo '<strong>Class Number</strong>: '.$result_inner['subject_number'].'.'.$result_inner['class_number'];
            echo '<br>';
            echo '<strong>ISBN</strong>: '.$result_inner['isbn'];
            echo '<br>';
	  }
	  echo '</div>';
	}
	echo '</div>';
	} else {
             echo '<h2>Please, <a href="demo.php">login</a> and come back later!</h2>';
        }
        ?>
	</div>

</body>
</html>
      
          
