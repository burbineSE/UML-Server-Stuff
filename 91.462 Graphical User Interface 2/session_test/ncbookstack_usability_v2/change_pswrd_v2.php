<!-- 
File: change_pswrd_v2.php
Author: cburbine
Course: 91.462 - GUI II Programming
Email: christopher_burbine@student.uml.edu
Description: Updates password in tz_members table based on user
input.
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
if (!isset($_POST['submit'])) { // if the form not yet submitted
    header("Location: pw_change_form.php");
    exit;
    echo 'Name not set.  ';
}

//gets data fomr user table for the pass word var
$test_query = "SELECT * FROM tz_members WHERE usr = '" . $_SESSION['username'] . "'";
$query_result = mysql_query($test_query) or die(mysql_error());
while ($row_query = mysql_fetch_array($query_result)) {
    //if new password matches re-new password and is non-empty
    //if ($_POST['new_password'] == $_POST['re_new_password'] && $_POST['new_password'] != '') {
    if ($row_query['pass'] == $_POST['old_password'] && $_POST['old_password'] != '') {
        // if old pass word matched logged pass word and is non-empty
        //if ($row_query['pass'] == $_POST['old_password'] && $_POST['old_password'] != '') {
	if ($_POST['new_password'] == $_POST['re_new_password'] && $_POST['new_password'] != '') {
            //update pass word
            $change_query = "UPDATE tz_members SET pass = '" . $_POST['new_password'] . "' WHERE usr = '" . $_SESSION['username'] . "'";
            $change_result = mysql_query($change_query) or die(mysql_error());
            header('Location: mypage.php?pwnew=1');
	    exit;
        } else {
            ;echo 'Invalid Password<br>';
            //back button if there is an issue
            ;echo '<button onclick="history.go(-1);">Back </button>';
	    header("Location: pw_change_form.php?pwmm=1");
	    exit;
        }
    } else {
        ;echo 'Passwords to not match.<br>';
        ;echo '<button onclick="history.go(-1);">Back </button>';
	header("Location: pw_change_form.php?pwold=0");
	exit;
    }
}

//echo '<p>End.</p>';
?>
