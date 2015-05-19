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
    header("location: mypage.php"); // send to home page
    exit;
}
?>
<html>
    <head>
        <meta charset="UTF-8">
        <title>NC Bookstack - A used book store for UML students</title>

        <?php
        $onlogin = 1;
        include 'toptab_nologin.php';
        ?>
        <link rel="stylesheet" type="text/css" href="css/mainCSS.css">
        <link rel="stylesheet" type="text/css" href="jquery-ui-1.10.4.custom/css/ui-lightness/jquery-ui-1.10.4.custom.min.css">
    </head>
    <body>
        <h3 class="loginTitle">Please enter a username and password</h3>
        <form action = "login_pro.php" method = "post">
            <table class="loginTable">
                <tr>
                    <td>
                        Username: 
                    </td> 
                    <td>
                        <input type="text" name="username" />

                    </td>
                </tr>
                <tr>
                    <td>
                        Password: 
                    </td>
                    <td>
                        <input type="password" name="password" />
                    </td>
                    <?php
                    if (isset($_GET["unpw"]) && $_GET["unpw"] == 0) {
                        ?>
                    <p style="text-align:center;"><strong style="text-align:center;" class="logerr">* Your username or password is invalid.</strong></p>
                    <?php
                }
                if (isset($_GET["nologin"]) && $_GET["nologin"] == 1) {
                    ?>
                    <p style="text-align:center;"><strong style="text-align:center;" class="logerr">* You must login first to view that page.</strong></p>
                    <?php
                }
                ?>

                </tr>

            </table>


            <div class="buttonholder">
                <input type="submit" name="submit" value="Login" />
            </div>
            <!-- regis button -->
        </form>
        <!--<p style="text-align:center;">Not a member? Sign up <a href="register.php">here</a>. </p>-->
    </body>
</html>
