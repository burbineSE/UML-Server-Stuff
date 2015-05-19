<?php

//File: mess_helper.php
//Author: cburbine
//Course: 91.462 - GUI II Programming
//Email: christopher_burbine@student.uml.edu
//Description: Helper function for messaging system

include 'connect_test.php';

if (empty($_SESSION)) { // if the session not yet started
    session_name('newLogin');
    session_set_cookie_params(2 * 7 * 24 * 60 * 60);
    session_start();
}

if (!isset($_SESSION['username'])) { //if not yet logged in
    header("Location: login.php"); // send to login page
    exit;
}

if (!isset($_POST['submit'])) { // if the form not yet submitted
    header("Location: mypage.php?set=0");
    exit;
}

#echo $_GET['seller'];

$to = $_POST['to'];
$title = $_POST['title'];
$date = $_POST['date'];
$time = $_POST['time'];
$seller = $_GET['seller'];
$isbn = $_GET['isbn'];
$textm = $_POST['textm'];

if ($date == "" && $time == "empty") {
    header('Location: message_form.php?seller=' . $seller . '&isbn=' . $isbn . '&datetime=false');
    #echo "HERE";
    exit;
}
if ($date == "") {
    header('Location: message_form.php?seller=' . $seller . '&isbn=' . $isbn . '&date=false');
    #echo $time;
    #echo "fdfsdf ".$date." llll";
    #echo 'message_form.php?seller='.$seller.'&isbn='.$isbn.'&date='.$time.'';
    exit;
}
if ($time == "empty") {
    header('Location: message_form.php?seller=' . $seller . '&isbn=' . $isbn . '&time=false');
    exit;
}

echo $to . " " . $title . " " . $date . " " . $time . " " . $seller . " " . $isbn;

$date_parts = explode("/", $date);
$month = $date_parts[0];
$day = $date_parts[1];
$year = $date_parts[2];

#echo $month ."-". $day ."-". $year;

$time_parts1 = explode(" ", $time);
$time_parts2 = explode(":", $time_parts1[0]);

$hour = $time_parts2[0];
$min = $time_parts2[1];
$ampm = $time_parts1[1];

#echo $hour ."/". $min ."/". $ampm;

$today = date("m/d/Y g:i A");
$t_parts1 = explode(" ", $today);
$date_parts = explode("/", $t_parts1[0]);
$time_parts = explode(":", $t_parts1[1]);

$t_month = $date_parts[0];
$t_day = $date_parts[1];
$t_year = $date_parts[2];

$t_hour = $time_parts[0];
$t_min = $time_parts[1];

$t_ampm = $t_parts1[2];

#echo $t_month ."-". $t_day ."-". $t_year."<br>";
#echo $t_hour  ."-". $t_min."<br>";
echo $t_ampm;

$t_date = $t_month . "/" . $t_day . "/" . $t_year;

#echo "out: time date ok";
$s_data = mysql_query("SELECT * FROM tz_members WHERE usr = '" . $seller . "'") or die('S_DATA: Error: ' . mysql_error());
while ($result = mysql_fetch_array($s_data)) {
    $s_email = $result['email'];
    #echo $s_email;
}
$b_data = mysql_query("SELECT * FROM tz_members WHERE usr = '" . $_SESSION['username'] . "'") or die('D_DATA: Error: ' . mysql_error());
while ($result = mysql_fetch_array($b_data)) {
    $b_email = $result['email'];
    #echo $b_email;
}

$title = "NC BookStack Trade Request";

#echo "!!!".$textm."???";
if ($textm == '') {
    $textm = "User " . $_SESSION['username'] . " requests a trade meeting on " . $date . " at " . $time . ".";
    # echo $textm;
} else {
    $textm = $textm . "<br><br>(Meeting requested for " . $date . " at " . $time . ")";
    #echo $textm;
}

$b_email = "From: " . $_SESSION['username'] . " (" . $b_email . ")";

mail($s_email, $title, $textm, $b_email);

$t_timedate = $year . "-" . $month . "-" . $day . " " . $hour . ":" . $min;
#echo '<br>'.$t_timedate;

echo 'At end of else ';
echo $isbn . ' ';
$get_bfs = mysql_query("SELECT * FROM books_for_sale WHERE isbn = '" . $isbn . "'") or die('GET AP: Error: ' . mysql_error());

while ($result = mysql_fetch_array($get_bfs)) {
    $ap = $result['asking_price'];
    $ct_title = $result['title'];
}

echo ' Here|' . $ap . ' ' . $ct_title . '|Here';

#echo $month."/".$day."/".$year." ".$hour.":".$min." ".$ampm;
$t_data = mysql_query("INSERT INTO current_transactions (seller, buyer, isbn, tradedate, asking_price, title) VALUES ('" . $seller . "', '" . $_SESSION['username'] . "', '" . $isbn . "', '" . $month . "/" . $day . "/" . $year . " " . $hour . ":" . $min . " " . $ampm . "', '" . $ap . "','" . $ct_title . "')") or die('T_DATA: Error: ' . mysql_error());

header('Location: mypage.php?mess=1');
#echo $s_email." ".$title." ".$textm." ".$_SESSION['username']." ".$b_email;
#echo $title;
#echo $textm;
#echo $_SESSION['username'];
#}
?>
