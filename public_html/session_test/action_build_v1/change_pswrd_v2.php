<?php
include 'connect_test.php'; //connect the connection page

if(empty($_SESSION)){ // if the session not yet started
  session_name('newLogin');
  session_set_cookie_params(2*7*24*60*60);  
  session_start();
}
if(!isset($_POST['submit'])) { // if the form not yet submitted
  header("Location: home.php");
  exit;
  echo 'Name not set.  ';
}

$test_query = "SELECT * FROM tz_members WHERE usr = '".$_SESSION['username']."'";
$query_result = mysql_query($test_query)or die(mysql_error());
while($row_query = mysql_fetch_array($query_result)) {
  if($_POST['new_password'] == $_POST['re_new_password'] && $_POST['new_password'] != ''){
    if($row_query['pass'] == $_POST['old_password'] && $_POST['old_password'] != ''){
      $change_query = "UPDATE tz_members SET pass = '".$_POST['new_password']."' WHERE usr = '".$_SESSION['username']."'";
      $change_result = mysql_query($change_query)or die(mysql_error());
      header('Location: home.php');

    } else {
      echo 'Invalid Password<br>';
      echo '<button onclick="history.go(-1);">Back </button>';
    }
  } else {
    echo 'Passwords to not match.<br>';
    echo '<button onclick="history.go(-1);">Back </button>';
  }
}

//echo '<p>End.</p>';
?>
