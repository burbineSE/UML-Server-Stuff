<?php
include 'connect_test.php'; //connect the connection page

if(empty($_SESSION)){ // if the session not yet started
  session_name('newLogin');
  session_set_cookie_params(2*7*24*60*60);
  session_start();
}
if(!isset($_POST['submit'])) { // if the form not yet submitted
   header("Location: login.php");
   exit; 
}

//check if the username entered is in the database.
$test_query = "SELECT * FROM tz_members WHERE usr = '".$_POST[username]."'";
$query_result = mysql_query($test_query);

if(mysql_num_rows($query_result) == 0){
  echo "The username you entered is invalid.";
}else {
  //if exists, then extract the password.
  while($row_query = mysql_fetch_array($query_result)){
    // check if passwords are equal
    if($row_query['pass']==$_POST['password']){
      $_SESSION['username'] = $row_query['usr'];
      $_SESSION['id'] = $row_query['id'];
      header("Location: home.php");
      exit;
      //echo "If statement reached."; 
    }else { //if not
      echo "Invalid Password"; 
    }
  }
}
?>
