<?php 
include 'connect_test.php';

if(empty($_SESSION)){ // if the session not yet started
  session_name('newLogin');
  session_set_cookie_params(2*7*24*60*60);
  session_start();
}

if(isset($_SESSION['username'])) { //if not yet logged in
  header("Location: logout.php");// send to login page
  exit;
}

if(!isset($_POST['submit'])) { // if the form not yet submitted
  header("Location: register.php?set=0");
  exit;
}

#echo 'Here-reg. ';

$user = $_POST['username'];
$email = $_POST['email'];
$pswrd = $_POST['pswrd'];

#echo ' ' . $user . ' '; 
#echo $email;
#echo $pswrd;

$query = mysql_query("SELECT usr FROM tz_members") or die ('NAMECHECK: Error: '.mysql_error());
$name_check = 0;

while($result = mysql_fetch_array($query)){
  #echo ' WHILE ';
  #echo ' ' . $result['usr'] . ' ';
  if($result['usr'] == $user){
    $name_check++;
    #echo 'IN ';
  }
}

#echo 'Name check: ' . $name_check;

if($name_check > 0){
  header('Location: register.php?name=false');
} else {
  $add_usr = mysql_query("INSERT INTO tz_members (usr, pass, email, regIP, dt) VALUES ('". $user ."', '". $pswrd  ."', '". $email  ."', '". $_SERVER['REMOTE_ADDR']."', '". date('Y-m-d') ."')")or die ('NAMEADD: Error: '.mysql_error());

  $test_query = "SELECT * FROM tz_members WHERE usr = '".$user."'";
  $query_result = mysql_query($test_query);
  while($row_query = mysql_fetch_array($query_result)){
     if($row_query['pass']==$pswrd){
       $_SESSION['username'] = $row_query['usr'];
       $_SESSION['id'] =  $row_query['id'];
       header("Location: home.php");
       exit;	 
     }
   }
}        

 
?>
