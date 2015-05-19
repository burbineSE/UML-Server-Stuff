<!DOCTYPE html>
<!-- 
File: register.php
Author: cburbine
Course: 91.462 - GUI II Programming
Email: christopher_burbine@student.uml.edu
Description: Register form
-->
<?php
include 'connect_test.php';

if (empty($_SESSION)) { // if the session not yet started
    session_name('newLogin');
    session_set_cookie_params(2 * 7 * 24 * 60 * 60);
    session_start();
}

if (isset($_SESSION['username'])) { //if not yet logged in
    header("Location: logout.php"); // send to login page
    exit;
}
?>
<html>
    <head>
        <title>Sign Up</title>
        <meta charset="UTF-8">
        <link rel="stylesheet" type="text/css" href="css/mainCSS.css">
        <?php include 'toptab.php'; ?>
        <link rel="stylesheet" type="text/css" href="jquery-ui-1.10.4.custom/css/ui-lightness/jquery-ui-1.10.4.custom.min.css">

        <script src="//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
        <script src="http://ajax.aspnetcdn.com/ajax/jquery.validate/1.9/jquery.validate.min.js" type="text/javascript"></script>
        <script src="http://ajax.aspnetcdn.com/ajax/jquery.validate/1.9/additional-methods.min.js" type="text/javascript"></script>
        <script type="text/javascript">
            $(document).ready(function() {
                $('#register').validate({
                    rules: {
                        username: {
                            required: true
                        },
                        email: {
                            required: true,
                            email: true
                        },
                        pswrd: {
                            required: true,
                            rangelength: [5, 15]
                        },
                        repswrd: {
                            required: true,
                            equalTo: "#pswrd"
                        }
                    },
                    messages: {
                        username: {
                            required: "* Please enter your username."
                        },
                        email: {
                            required: "* Please enter your email.",
                            email: "* Email invalid."
                        },
                        pswrd: {
                            required: "* Please enter your password.",
                            rangelength: "* Password must be between 5 and 15 characters."
                        },
                        repswrd: {
                            required: "* Please re-enter your password.",
                            equalTo: "* Password mismatch."
                        }
                    },
                    errorElement: 'div',
                    wrapper: 'div',
                    errorPlacement: function(error, element) {
                        error.insertAfter(element);
                    }
                });
            });
            function init() {
                register = document.getElementById("register");
            }
        </script>
        <style>
            label{
                display: inline-block;
                float: left;
                clear: left;
                width: 300px;
                text-align: right;
            }
            input {
                display: inline-block;
                float: center;
            }
            div {
                text-align:center;
            }
        </style>
    </head>
    <body 
        <br><br>
            <?php
            #echo "Return: ".$_GET["name"]."<br>";
            #if(isset($_GET["name"]) && $_GET["name"] == 'false'){
            #echo "Here.<br>";
            # echo "<p><strong>* Username already in use.</strong></p>";
            #}
            if (isset($_GET["set"]) && $_GET["set"] == 0) {
                echo "<p><strong>* Form Unsubmitted.</strong></p>";
            }
            ?>
        <!--<div class="regcont">-->
        <form name="register" id="register" method="post" action="reg_helper.php">
            <label>Username:</label> <input  class="regput" type="text" name="username" id="username"/><br>
            <?php
            #echo "Return: ".$_GET["name"]."<br>";
            if (isset($_GET["name"]) && $_GET["name"] == 'false') {
                #echo "Here.<br>";
                echo "<strong>* Username already in use.</strong>";
            }
            ?>
            <label>Email:             </label><input class="regput" type="email" name="email" id="email"/><br>
            <label>Password:          </label><input class="regput" type="password" name="pswrd" id="pswrd"/><br>
            <label>Re-enter Password: </label><input class="regput" type="password" name="repswrd" id="repswrd"/><br><br>
            <input type="hidden" name="reg-ing" value="yes" />
            <div class="buttonholder">
                <input class="sub" type="submit" name="submit" value="Sign Up" /><br>
            </div>
        </form>
        <!--</div>-->
    </body>
</html>
