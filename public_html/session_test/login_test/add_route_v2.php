<?php 
include 'connect_test.php'; //connect the connection page

if(empty($_SESSION)){ // if the session not yet started
  session_name('newLogin');
  session_set_cookie_params(2*7*24*60*60);
  session_start();
}

echo 'Here1. ';

if(isset($_POST['field'])){
  $isbn = $_POST['pass_val'];
  $field = $_POST['field'];
  $count_list = 0;
  $count_have = 0;
  
  
  $data = mysql_query("SELECT * FROM wanted_books WHERE buyer LIKE '%$user%'")or die ('Error: '.mysql_error());

  while($result = mysql_fetch_array($data)){
    if($result['isbn'] == $isbn){
      $count_list++;
      echo $count_list;
    }
  }
  $data = mysql_query("SELECT * FROM books_for_sale WHERE seller LIKE '%$user%'")or die('Error: '.mysql_error());

  while($result = mysql_fetch_array($data)){
    if($result['isbn'] == $isbn){
      $count_have++;
      echo $count_have;
    }
  }

  if($field == 'wanted_books'){
     $data_w = mysql_query("INSERT INTO wanted_books (isbn, buyer) VALUES ('".$isbn."', '".$_SESSION['username']."')")or die (mysql_error());
     header("Location: search.php");
  }else if ($field == 'books_for_sale'){
      $data_b = mysql_query("INSERT INTO books_for_sale (isbn, seller) VALUES ('".$isbn."', '".$_SESSION['username']."')")or die (mysql_error());
    header("Location: search.php");
    }
  }
?>
