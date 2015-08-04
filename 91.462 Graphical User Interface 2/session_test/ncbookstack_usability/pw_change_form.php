<!DOCTYPE html>
<html>
    <head>
        <?php
        include 'connect_test.php'; //connect the connection page

        if (empty($_SESSION)) { // if the session not yet started
            session_name('newLogin');
            session_set_cookie_params(2 * 7 * 24 * 60 * 60);
            session_start();
        }

        if (!isset($_SESSION['username'])) { //if not yet logged in
            header("Location: login.php"); // send to login page
            exit;
        }
        ?>
        <meta charset="UTF-8">
        <title>NC Bookstack - A used book store for UML students</title>

        <link rel="stylesheet" type="text/css" href="css/mainCSS.css">
	<script src="//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
    <script src="http://ajax.aspnetcdn.com/ajax/jquery.validate/1.9/jquery.validate.min.js" type="text/javascript"></script>
    <script src="http://ajax.aspnetcdn.com/ajax/jquery.validate/1.9/additional-methods.min.js" type="text/javascript"></script>
    <script type="text/javascript">
      $(document).ready(function() {
      $('#changepw').validate({
      rules: {
      old_password: {
      required: true
      },
      new_password: {
      required: true,
      rangelength: [5, 15]
      },
      re_new_password: {
      required: true,
      equalTo: "#new_password"
      }
      },
      messages: {
      old_password: {
      required: "* Please enter your old password."
      },
      new_password: {
      required: "* Please enter your new password.",
      rangelength: "* Password must be between 5 and 15 characters."
      },
      re_new_password: {
      required: "* Please re-enter your new password.",
      equalTo: "* Password mismatch."
      }
      }
      });
      });
    </script>
    </head>
    <body>
        <form name="changepw" id="changepw" action="change_pswrd_v2.php" method="post">
            <table>
                <tr>
                    <td>
                        Enter old password:
                    </td>
                    <td>
                        <input type="password" name="old_password" id="old_password"/>
			<?php
			   if(isset($_GET["pwold"]) && $_GET["pwold"] == 0){
			     echo "<strong>* Invalid password.</strong>";
			   }
			   ?>
                    </td>
                </tr>
                <tr>
                    <td>
                        Enter new password:
                    </td>
                    <td>
                        <input type="password" name="new_password" id="new_password"/>
                    </td>
                </tr>
                <tr>
                    <td>
                        Re-enter new password:
                    </td>
                    <td>
                        <input type="password" name="re_new_password" id="re_new_password"/>
			<?php
                           if(isset($_GET["pwmm"]) && $_GET["pwmm"] == 1){
                             echo "<strong>* Password mismatch</strong>";
                           }
                           ?>
		    </td>
                </tr>
            </table>
            <input type = "submit" name="submit" value="Change Password" />
            <a href="http://weblab.cs.uml.edu/~cburbine/session_test/ncbookstack_usability/home.php">
                <input type="button" value="Cancel" />
            </a>
        </form>
    </body>
</html>
