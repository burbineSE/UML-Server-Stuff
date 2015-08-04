<?php
include 'connect_test.php'; //connect the connection page

if(empty($_SESSION)){ // if the session not yet started
  session_name('newLogin');
  session_set_cookie_params(2*7*24*60*60);
  session_start();
}

#if(!isset($_POST['submit'])) { // if the form not yet submitted
 #  header("Location: home.php");
  # exit;
#}

echo 'Here.';
$isbn = $_POST['pass_val_W'];
echo $isbn;
#echo ' Here. ';
#mysql_query("DELETE FROM wanted_books WHERE isbn = $isbn LIMIT 1");
#$data = mysql_query("SELECT * FROM wanted_books WHERE isbn = '0470501960'")or die(mysql_error());
#echo $data;
while($result = mysql_fetch_assoc($data)){
 echo ' '.$result['isbn'];
}
#mysql_query("COMMIT", $link);
#echo $delete_data;
#if(!$delete_data){
 # die(mysql_error());
#}
#echo 'Here1. ';
#$stmt = mysql_prepare($query);
#echo 'Here2. ';
#mysql_stmt_bind_param($stmt, "s", $isbn);
#mysql_execute($stmt);
#header('Location: home.php');
?>
