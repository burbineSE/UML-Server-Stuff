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

if (empty($_SESSION)) { // if the session not yet started
    session_name('newLogin');
    session_set_cookie_params(2 * 7 * 24 * 60 * 60);
    session_start();
}

if (!isset($_SESSION['username'])) { //if not yet logged in
    header("Location: login.php"); // send to login page
    exit;
}
?>
<html>
    <head>
        <meta charset="UTF-8">
        <title>NC Bookstack - A used book store for UML students</title>
        
        <link rel="stylesheet" type="text/css" href="css/mainCSS.css">
    </head>
    <body>
        <h1>Welcome <?php echo $_SESSION['username']; ?></h1>
        <a href="logout.php">Logout </a> | 
        <!-- Password change input boxes, should either be placed on a separate
            page to the home/user page or hidden with JavaScript.
        -->
        <!--<h4>Password Change Form</h4>
        <form action="change_pswrd_v2.php" method="post">
            <table>
                <tr>
                    <td>
                        Enter old password: 
                    </td>
                    <td>
                        <input type="password" name="old_password" />
                    </td>
                </tr>
                <tr>
                    <td>
                        Enter new password: 
                    </td>
                    <td>
                        <input type="password" name="new_password" />
                    </td>
                </tr>
                <tr>
                    <td>
                        Re-enter new password: 
                    </td>
                    <td>
                        <input type="password" name="re_new_password" />
                    </td>
                </tr>
            </table>
            <input type = "submit" name="submit" value="Change Password" />
        </form>-->
	<a href="pw_change_form.php"> Change Password </a> |
        
        <a href="search_v2.php"> Search for a book </a><br>

        <?php
        echo '<br>';
        if ($_SESSION['id']) {
            $user = $_SESSION['username'];
            $sale_data = mysql_query("SELECT * FROM books_for_sale WHERE seller LIKE'%$user%'") or die('Error: ' . mysql_error());
            //creates a form which holds all entiries of bother wanted list and selling list
            //needed for item remove function(s)
            echo '<form method="post" value="Delete" action="remove_book_v2.php">';
            echo '<input type="submit" name="delete" value="Delete Selected Book from List" id="delKey"><br>';
            echo '<div class="saleBooks"><h3><strong>Books for Sale</strong></h3>';
            while ($result = mysql_fetch_array($sale_data)) {
                $isbn = $result['isbn'];
                //atm the adding functions do not set asking price will be updated later
                $asking_price = $result['asking_price'];
                echo '<span class="askPrice"><strong>Asking Price</strong>: $' . $asking_price . '</span><br>';
                $slice_data = mysql_query("SELECT * FROM bookslice1 WHERE isbn LIKE'%$isbn%'") or die('Error: ' . mysql_error());
                while ($result_inner = mysql_fetch_array($slice_data)) {
                    //echo '<div class="bookEntry">';
		    echo '<input type="radio" name="pass_val" value="' . $result_inner['isbn'] . '">';
		    echo '<div class="bookEntrySelling">';
                    echo '<strong>Title</strong>: ' . $result_inner['title'];
                    echo '<br>';
                    echo '<strong>Edition</strong>: ' . $result_inner['edition'];
                    echo '<br>';
                    echo '<strong>Author(s)</strong>: ' . $result_inner['author'];
                    echo '<br>';
                    echo '<strong>Class Number</strong>: ' . $result_inner['subject_number'] . '.' . $result_inner['class_number'];
                    echo '<br>';
                    echo '<strong>ISBN</strong>: ' . $result_inner['isbn'];
                    echo '<br>';
                    //radio button for remove funtion, passes isbn to function
                    //echo '<input type="radio" name="pass_val" value="' . $result_inner['isbn'] . '">';
                    echo '</div>';
                }
                echo '<br>';
            }
	    echo '</div>';
           #echo '<div class="wantedBooks"><h3><strong>Wanted Books</strong></h3>';
            #$wanted_data = mysql_query("SELECT * FROM wanted_books WHERE buyer LIKE '%$user%'") or die('Error: ' . mysql_error());

            #while ($result = mysql_fetch_array($wanted_data)) {
             #   $isbn2 = $result['isbn'];
              #  $slice_data = mysql_query("SELECT * FROM bookslice1 WHERE isbn LIKE'%$isbn2%'") or die('Error slice: ' . mysql_error());
               # while ($result_inner = mysql_fetch_array($slice_data)) {
                    //echo '<div class="bookEntry">';
		#    echo '<input type="radio" name="pass_val_W" value="' . $result_inner['isbn'] . '">';
		 #   echo '<div class="bookEntry">';
                  #  echo '<strong>Title</strong>: ' . $result_inner['title'];
                   # echo '<br>';
                    #echo '<strong>Edition</strong>: ' . $result_inner['edition'];
                    #echo '<br>';
                    #echo '<strong>Author(s)</strong>: ' . $result_inner['author'];
                    #echo '<br>';
                    #echo '<strong>Class Number</strong>: ' . $result_inner['subject_number'] . '.' . $result_inner['class_number'];
                   # echo '<br>';
                   # echo '<strong>ISBN</strong>: ' . $result_inner['isbn'];
                   # echo '<br>';
                    //radio button for remove funtion, passes isbn to function; major differnce with
                    //buttons above is that the name is different, changed so removal function can tell 
                    //the difference between books on the wanted list and books on the selling list
                    //echo '<input type="radio" name="pass_val_W" value="' . $result_inner['isbn'] . '">';
          #          echo '</div>';
           #     }
            #    echo'<br>';
            #}
	    #echo '</div>';
	   
	   echo '<div class="wantedBooks"><h3><strong>Current Transactions</strong></h3>';
	   $currtran_data = mysql_query("SELECT * FROM current_transactions WHERE seller = '$user' OR buyer = '$user'")or die("CURRTRAN: Error: ".mysql_error());
	   while ($result = mysql_fetch_array($currtran_data)){
	     echo '<input type="radio" name="pass_valCT" value="' . $result['isbn'] . '">';
	     echo '<div class="bookEntry">';
	     echo '<strong>Trade Date</strong>: '.$result['tradedate'];
	     echo '<br>';
	     if($_SESSION['username'] == $result['seller']){
	      echo '<strong>Buyer</strong>: ' .$result['buyer'];
	      $other = $result['buyer'];
	     } 
	     else if($_SESSION['username'] == $result['buyer']){
	       echo '<strong>Seller</strong>: ' .$result['seller'];
	       $other = $result['seller'];
	     }
	     echo '<br>';
	     $ct_isbn = $result['isbn'];
	     $ct_slice_data = mysql_query("SELECT * FROM bookslice1 WHERE isbn = '$ct_isbn'") or die('Error slice: ' . mysql_error());
	   
	     while($result_inner = mysql_fetch_array($ct_slice_data)){
	       echo '<strong>Title</strong>: ' . $result_inner['title'];
	     }
	     echo '<br>';
	     $ct_sale_data = mysql_query("SELECT * FROM books_for_sale WHERE isbn = '$ct_isbn' AND (seller = '$user' OR seller = '$other')") or die('Error: ' . mysql_error());
	      while($result_inner = mysql_fetch_array($ct_sale_data)){
	        echo '<strong>Asking Price</strong>: ' . $result_inner['asking_price'];
	      }
	     echo '</div>';
	   }
	   echo '</div>';
        }
        ?>
    </form>
</body>
</html> 
