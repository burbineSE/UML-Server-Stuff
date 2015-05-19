<?php
include 'connect_test.php'; //connect the connection page

if(empty($_SESSION)){ // if the session not yet started
  session_name('newLogin');
  session_set_cookie_params(2*7*24*60*60);
  session_start();
}

$isbn  = $_POST['pass_val'];
$isbn2 = $_POST['pass_val_W'];

if($isbn == ''){
$delete_data = mysql_query("DELETE FROM wanted_books WHERE isbn='$isbn2' LIMIT 1");
header('Location: home.php');
}else if($isbn2 == ''){
$delete_data = mysql_query("DELETE FROM books_for_sale WHERE isbn='$isbn' LIMIT 1");
header('Location: home.php');
} else {
header('Location: home.php');
}
?>
