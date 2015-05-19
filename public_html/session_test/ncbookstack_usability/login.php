<!DOCTYPE html>
<!-- 
File: login.php
Author: cburbine
Course: 91.462 - GUI II Programming
Email: christopher_burbine@student.uml.edu
Description: Login page for build, user redirects here if they try
to go to home.php.
-->
<?php
include 'connect_test.php'; //connect the connection page
if (empty($_SESSION)) { // if the session not yet started
    session_name('newLogin');
    session_set_cookie_params(2 * 7 * 24 * 60 * 60);
    session_start();
}

if (isset($_SESSION['username'])) { // if already login
    header("location: home.php"); // send to home page
    exit;
}
?>
<html>
    <head>
        <meta charset="UTF-8">
        <title>NC Bookstack - A used book store for UML students</title>
        
        <link rel="stylesheet" type="text/css" href="css/mainCSS.css">
    </head>
    <body>
        <h3 class="loginTitle">Please enter a username and password to log in.</h3>
        <form action = "login_pro.php" method = "post">
            <table class="loginTable">
                <tr>
                    <td>
                        Username: 
                    </td> 
                    <td>
                        <input type="text" name="username" />
			<?php
                           if(isset($_GET["unpw"]) && $_GET["unpw"] == 0){
                             echo "<strong>* Your username or password are invalid.</strong>";
                           }
                           ?>
                    </td>
                </tr>
                <tr>
                    <td>
                        Password: 
                    </td>
                    <td>
                        <input type="password" name="password" />
                    </td>
                </tr>
            </table>
            <input class="button" type="submit" name="submit" value="Login" />
	    <!-- regis button -->
        </form>
	<p>Not a member sign up <a href="register.php">here</a>. </p>
    </body>
</html>
