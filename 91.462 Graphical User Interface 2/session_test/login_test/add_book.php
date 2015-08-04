<?php 
include 'connect_test.php'; //connect the connection page

if(empty($_SESSION)){ // if the session not yet started
  session_name('newLogin');
  session_set_cookie_params(2*7*24*60*60);
  session_start();
}

#if(!isset($_POST['submit'])) { // if the form not yet submitted
  #header("Location: search.php");
  #exit;
#}

if(isset($_POST['field'])){      
#echo $_SESSION['username'];
$user = $_SESSION['username'];
$isbn = $_POST['pass_val'];
$field = $_POST['field'];
#echo $isbn;
$count_list = 0;
$count_have = 0;

$data = mysql_query("SELECT * FROM wanted_books WHERE buyer LIKE '%$user%'")or die ('Error: '.mysql_error());

while($result = mysql_fetch_array($data)){
  if($result['isbn'] == $isbn){
    $count_list++;
  } 
}
$data = mysql_query("SELECT * FROM books_for_sale WHERE seller LIKE '%$user%'")or die('Error: '.mysql_error());
      
while($result = mysql_fetch_array($data)){
  if($result['isbn'] == $isbn){
    $count_have++;
  }
}

if($field == 'wanted_books'){
if($count_list > 0){
  echo '<p>Book already on wanted list.</p>';
  echo '<button onclick="history.go(-1);">Back </button>';
}else if($count_have > 0) {
  echo '<p>You already own that book.</p>';
  echo '<button onclick="history.go(-1);">Back </button>';
}else {
  echo 'Book not on wanted list.';
}
}
 
#if($feild == 'books_for_sale'){
#if($count_list > 0){
  #echo '<p>Book on wanted list.</p>';
  #echo '<button onclick="history.go(-1);">Back </button>';
#}
#}else if($count_have > 0) {
  #echo '<p>Book already on selling list.</p>';
  #echo '<button onclick="history.go(-1);">Back </button>';
#}
#}else {
 #echo 'Last option';
#}
#}
#}
?>
