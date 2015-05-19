<!-- 
File: remove_book_v2.php
Author: cburbine
Course: 91.462 - GUI II Programming
Email: christopher_burbine@student.uml.edu
Description: Removes book from appropriate list when called.
Can only remove on book at a time atm.
-->
<?php

include 'connect_test.php'; //connect the connection page

if (empty($_SESSION)) { // if the session not yet started
    session_name('newLogin');
    session_set_cookie_params(2 * 7 * 24 * 60 * 60);
    session_start();
}
if (!isset($_SESSION['username'])) { //if not yet logged in
    header("Location: login.php?nologin=1"); // send to login page
    exit;
}

#echo 'Here ';
$pass_val = $_POST['pass_val'];
#echo $pass_val[1] ." |";
$removetype = $_POST['transremove'];
echo "!!! ".$removetype." !!!";

if($removetype == "transcan" || $removetype == ""){
  if(count($pass_val) > 0){
    #echo 'if';
    for($i = 0; $i < count($pass_val); $i++){
      $entry_parts = explode(" ", $pass_val[$i]);
      #echo "title: ".$entry_parts[0];
      #echo " isbn: ".$entry_parts[1];
      if($entry_parts[0] == 'BFS:'){
        #echo " books for sale";
        #echo $entry_parts[1];
        $delete_data = mysql_query("DELETE FROM books_for_sale WHERE isbn='$entry_parts[1]' LIMIT 1")or die('Error: '.mysql_error());
      } else if($entry_parts[0] == 'CT:'){
        #echo " curr trans";
        $delete_data = mysql_query("DELETE FROM current_transactions WHERE isbn='$entry_parts[1]' LIMIT 1")or die('Error: '.mysql_error());
      }
    }
    header('Location: mypage.php');
  } else {
    header('Location: mypage.php?select=0');
  }
} else if($removetype == "transfin"){
  #echo 'Here';
  if(count($pass_val) > 0){
    #echo 'if';
    for($i = 0; $i < count($pass_val); $i++){
      $entry_parts = explode(" ", $pass_val[$i]);
      #echo "title: ".$entry_parts[0];
      #echo " isbn: ".$entry_parts[1];
      if($entry_parts[0] == 'BFS:'){
        #echo " books for sale";
        #echo $entry_parts[1];
        $delete_data = mysql_query("DELETE FROM books_for_sale WHERE isbn='$entry_parts[1]' LIMIT 1")or die('Error: '.mysql_error());
      } else if($entry_parts[0] == 'CT:'){
        #echo " curr trans";
        $delete_data = mysql_query("DELETE FROM current_transactions WHERE isbn='$entry_parts[1]' LIMIT 1")or die('Error: '.mysql_error());
	$delete_data_BFS = mysql_query("DELETE FROM books_for_sale WHERE isbn='$entry_parts[1]' LIMIT 1")or die('Error: '.mysql_error());
      }
    }
    header('Location: mypage.php');
  } else {
    header('Location: mypage.php?select=0');
  }
}
?>
