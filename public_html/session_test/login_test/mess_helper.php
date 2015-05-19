<?php
include 'connect_test.php';

if(empty($_SESSION)){ // if the session not yet started
  session_name('newLogin');
  session_set_cookie_params(2*7*24*60*60);
  session_start();
}

if(!isset($_SESSION['username'])) { //if not yet logged in
  header("Location: login.php");// send to login page
  exit;
}

if(!isset($_POST['submit'])) { // if the form not yet submitted
  header("Location: message_form.php?set=0");
  exit;
}

#echo $_GET['seller'];

$to = $_POST['to'];
$title = $_POST['title'];
$date = $_POST['date'];
$time = $_POST['time'];

#echo $to . " " . $title . " " . $date . " " . $time;

$date_parts = explode("/", $date);
$month = $date_parts[0];
$day   = $date_parts[1];
$year  = $date_parts[2];

#echo $month ."-". $day ."-". $year;

$time_parts1 = explode(" ", $time);
$time_parts2 = explode(":", $time_parts1[0]);

$hour = $time_parts2[0];
$min  = $time_parts2[1];
$ampm = $time_parts1[1];

#echo $hour ."/". $min ."/". $ampm;

$today = date("m/d/Y g:i A");
$t_parts1 = explode(" ", $today);
$date_parts = explode("/", $t_parts1[0]);
$time_parts = explode(":", $t_parts1[1]);

$t_month = $date_parts[0];
$t_day   = $date_parts[1];
$t_year  = $date_parts[2];

$t_hour  = $time_parts[0];
$t_min   = $time_parts[1];

$t_ampm  = $t_parts1[2];

#echo $t_month ."-". $t_day ."-". $t_year."<br>";
#echo $t_hour  ."-". $t_min."<br>";
#echo $t_ampm;

$t_date = $t_month."/".$t_day."/".$t_year;

#$t_ampm = 'PM';

if($year < $t_year){
  #echo $year ."  ". $t_year;
  header('Location: message_form.php?date=false');
} else if ($month < $t_month){
  #echo $month ."  ". $t_month;
  header('Location: message_form.php?date=false');
} else if ($day < $t_day) {
  #echo $day ."  ". $t_day;
  header('Location: message_form.php?date=false');
} else if($t_date == $date){
  header('Location: message_form.php?date=same');
} else {
  echo "out: time date ok";

}

?>
