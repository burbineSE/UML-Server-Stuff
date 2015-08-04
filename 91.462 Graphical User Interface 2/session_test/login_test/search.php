<!DOCTYPE html>
<?php
   include 'connect_test.php'; //connect the connection page

   if(empty($_SESSION)){ // if the session not yet started
     session_name('newLogin');
     session_set_cookie_params(2*7*24*60*60);
     session_start();
   }

   if(!isset($_SESSION['username'])) { //if not yet logged in
     header("Location: login.php");// send to login page
     exit;
   }

 ?>
<html>
    <head>
        <title>Search</title>
        <meta charset="UTF-8">
        <!--<meta name="viewport" content="width=device-width">

        <link rel="stylesheet" type="text/css" href="../jquery-ui-1.10.4.custom/css/ui-lightness/jquery-ui-1.10.4.custom.min.css">

        <script src="../js/jquery-1.11.0.min.js"></script>
        <script src="../jquery-ui-1.10.4.custom/js/jquery-ui-1.10.4.custom.min.js"></script>-->
	<script src="js/jquery-1.11.0.min.js"></script>
        <script src="jquery-ui-1.10.4.custom/js/jquery-ui-1.10.4.custom.min.js"></script>
        <script src="js/autoComplete.js"></script>
    </head>
    <body>
        <form name="search" method="post" action="pro_search_v2.php">
            Search for: <input type="text" name="find" /> in
            <select name="field">
                <option value="title">Title</option>
                <option value="author">Author</option>
                <option value="subject_number">Subject</option>
                <option value="class_number">Class</option>
                <option value="isbn">ISBN Number</option>
            </select>
            <input type="hidden" name="searching" value="yes" />
            <input type="submit" name="search" value="Search" />
        </form>
    </body>
</html>
