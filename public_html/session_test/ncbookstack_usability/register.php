<!DOCTYPE html>
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
?>
<html>
  <head>
    <title>Sign Up</title>
    <meta charset="UTF-8">
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
           }
         });
       });
      function init() {
        register = document.getElementById("register");
      }
    </script>
  </head>
  <body onload="init(); 
		document.getElementById('username').focus();">
    <?php
       #echo "Return: ".$_GET["name"]."<br>";
       #if(isset($_GET["name"]) && $_GET["name"] == 'false'){
         #echo "Here.<br>";
        # echo "<p><strong>* Username already in use.</strong></p>";
       #}
       if(isset($_GET["set"]) && $_GET["set"] == 0){
          echo "<p><strong>* Form Unsubmitted.</strong></p>";
       }
       ?>
    <form name="register" id="register" method="post" action="reg_helper.php">
      Username: <input type="text" name="username" id="username"/>
      <?php
        #echo "Return: ".$_GET["name"]."<br>";
        if(isset($_GET["name"]) && $_GET["name"] == 'false'){
          #echo "Here.<br>";
          echo "<strong>* Username already in use.</strong>";
         } ?><br>
      Email: <input type="email" name="email" id="email"/><br>
      Password: <input type="password" name="pswrd" id="pswrd"/><br>
      Re-enter Password: <input type="password" name="repswrd" id="repswrd"/><br>
      <input type="hidden" name="reg-ing" value="yes" />
      <input type="submit" name="submit" value="Sign Up" /><br>
    </form>
  </body>
</html>
