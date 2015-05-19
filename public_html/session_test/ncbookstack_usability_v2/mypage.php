<!DOCTYPE html>
<!-- 
File: home.php 
Author: cburbine
Course: 91.462 - GUI II Programming
Email: christopher_burbine@student.uml.edu
Description: A profile page for the currently logged in user. Hub 
for removing books from personal lists and changing password atm.
Possible add-ons: Link to search page, move change password stuff
to another page.
-->

<?php
include 'connect_test.php'; //connect the connection page
#include 'toptab.php';
if (empty($_SESSION)) { // if the session not yet started
    session_name('newLogin');
    session_set_cookie_params(2 * 7 * 24 * 60 * 60);
    session_start();
}

if (!isset($_SESSION['username'])) { //if not yet logged in
    header("Location: login.php?nologin=1"); // send to login page
    exit;
}
?>

<html>
    <head>
        <meta charset="UTF-8">
        <title>NC Bookstack - My Profile</title>
        <link rel="stylesheet" type="text/css" href="css/mainCSS.css">
	<?php $onhome = 1;
	      $notsearch = 1;
	      include 'toptab.php'; ?>
	<link rel="stylesheet" type="text/css" href="jquery-ui-1.10.4.custom/css/ui-lightness/jquery-ui-1.10.4.custom.min.css">
	<!--<script>
	  function setbookbox(){
	    var el = document.getElementById("bookbox");
	    if(el.checked)
	      document.getElementById("deletebut").disabled = false;
	    else
	      document.getElementById("deletebut").disbaled = true;
	  }
	</script>-->
	<script>
	  $(function() {
	    $( "#dialog-message" ).dialog({
	      modal: true,
	      buttons: {
                Ok: function() {
                  $( this ).dialog( "close" );
                }
	      }
	    });
	  });
	</script>
    </head>

    <body>
      <!--<script>
          function setbookbox(){
            var el = document.getElementById("bookbox");
            if(el.checked)
              document.getElementById("deletebut").disabled = false;
	    else
              document.getElementById("deletebut").disabled = true;
	  }
	  function setbookboxCT(){
	    var elCT = document.getElementById("bookboxCT");
	    if(elCT.checked)
	      document.getElementById("deletebut").disabled = false;
	    else
	      document.getElementById("deletebut").disabled = true;
	  }
        </script>-->
      <?php if($_GET['mess'] == 1){ ?>
      <div id="dialog-message" title="Download complete">
	<p>
	  <span class="ui-icon ui-icon-circle-check" style="float:left; margin:0 7px 50px 0;"></span>
	  Your trade request has been sent.
	</p>
      </div>
      <?php } ?>
      <?php 
	 $user = $_SESSION['username'];
	 if($_GET['wel'] == 1){
         echo '<h1>Welcome ';
	 echo $user;
	 echo '</h1>';
	 } else {
	 echo '<h1>My Profile</h1>';
	 }
	 ?>
        <!--<a href="logout.php">Logout </a> |
        <a href="pw_change_form.php"><input type="button" value="Change Password" /></a>
        <a href="search_v2.php"> Search for a book </a><br>-->

        <?php
           //If user is signed in, populate page with user data
        if ($_SESSION['id']) {
            
            $user = $_SESSION['username'];
            
            //Get data on books being sold by user
            #$sale_data = mysql_query("SELECT * FROM books_for_sale WHERE seller LIKE'%$user%'") or die('Error: ' . mysql_error());
            
            //Create list of books being sold by user. 
            //List is in a form which allows for books to be deleted from the list.
            echo '<form method="post" value="Delete" action="remove_book_v2.php">';
            echo '<input id="deletebut" type="submit" name="delete" value="Delete Current Selection(s)" id="delKey"><br>';
            echo '<div class="saleBooks"><h3><strong>My Books for Sale</strong></h3>';
            
            #while ($result = mysql_fetch_array($sale_data)) {
                $isbn = $result['isbn'];
                //All asking prices will display as 0, user cannot change asking prices yet
                #$asking_price = $result['asking_price'];
                #echo '<span class="askPrice"><strong>Asking Price</strong>: $' . $asking_price . '</span><br>';
                
                //Display information for each book
                $slice_data = mysql_query("SELECT * FROM books_for_sale WHERE seller = '".$user."'") or die('Error: ' . mysql_error());
                while ($result_inner = mysql_fetch_array($slice_data)) {
                    echo '<input id="bookbox" type="checkbox" name="pass_val[]" value="BFS: ' . $result_inner['isbn'] . '" onchange="setbookbox();">';
                    echo '<div class="bookEntrySelling">';
		    echo '<strong>Asking Price</strong>: $'.$result_inner['asking_price'];
	            echo '<br>';
	            echo '<strong>Condition</strong>: '.$result_inner['cond'];
	            echo '<br>';
                    echo '<strong>Title</strong>: ' . $result_inner['title'];
                    echo '<br>';
                    echo '<strong>Edition</strong>: ' . $result_inner['edition'];
                    echo '<br>';
                    echo '<strong>Author(s)</strong>: ' . $result_inner['author'];
                    echo '<br>';
                    echo '<strong>Class Number</strong>: ' . $result_inner['subject_number'] . '.' . $result_inner['class_number'];
                    echo '<br>';
                    echo '<strong>ISBN</strong>: ' . $result_inner['isbn'];
                    echo '<br><br>';
                    echo '</div>';
                }
                echo '<br>';
            #}
            echo '</div>';

            //Get data on user transactions
            $currtran_data = mysql_query("SELECT * FROM current_transactions WHERE seller = '$user' OR buyer = '$user'") or die("CURRTRAN: Error: " . mysql_error());
            
            echo '<div class="wantedBooks"><h3><strong>My Current Transactions</strong></h3>';
            while ($result = mysql_fetch_array($currtran_data)) {
                echo '<input id="bookboxCT" type="checkbox" name="pass_val[]" value="CT: ' . $result['isbn'] . '" onchange="setbookboxCT();" >';
	        echo '<select name="transremove">
			<option value="transcan">Transaction Canceled</option>
			<option value="transfin">Transaction Completed</option>
	              </select>';
	 
                echo '<div class="bookEntry">';
                echo '<strong>Trade Date</strong>: ' . $result['tradedate'];
	        
	        $tdateparts = explode(" ", $result['tradedate']);
	        #$tdate = explode("/", $tdateparts[0]);
	        #echo $tdate[2];
	        $todaytd = date("n/j/Y");
	        #echo $todaytd;
	        if(strtotime($tdateparts[0]) < strtotime($todaytd)){
	          #echo "Here";
                  echo " <strong style='color:red;'>(Trade Date Expired)</strong>";
                }
                echo '<br>';

                if ($_SESSION['username'] == $result['seller']) {
                    echo '<strong>Buyer</strong>: ' . $result['buyer'];
                    $other = $result['buyer'];
                } else if ($_SESSION['username'] == $result['buyer']) {
                    echo '<strong>Seller</strong>: ' . $result['seller'];
                    $other = $result['seller'];
                }
                echo '<br>';
	        echo '<strong>Title</strong>: '.$result['title'];
	        echo '<br>';
	        echo '<strong>Asking Price</strong>: $'.$result['asking_price'];
	        echo '<br><br>';
                
                echo '</div>';
            }
            echo '</div>';
            echo '</form>';
        }
        ?>

    </body>
</html> 
