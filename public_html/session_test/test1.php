<?php
define('INCLUDE_CHECK', true);

require 'connect.php';
require 'functions.php';

session_name('newLogin');
session_set_cookie_params(2*7*24*60*60);
session_start();

if (isset($_GET['logoff'])) {
    $_SESSION = array();
    session_destroy();

    header("Location: test1.php");
    exit;
}

if ($_POST['submit'] == 'Login') {
   //$err = array();

   // store session data
   $_SESSION['views']=1;
   setcookie
   
   header("Location: test1.php");
   exit;

}
?>

<html>
<body>

<?php
//retrieve session data
echo "Pageviews=". $_SESSION['views'];
?>

<input type="submit" name="submit" value="Login" class="bt_login" />
<a href="?logoff">Log off</a>

</body>
</html>
