<!-- 
File: logout.php
Author: cburbine
Course: 91.462 - GUI II Programming
Email: christopher_burbine@student.uml.edu
Description: Linked to on home.php. Kills current session logging
out the current user.
-->
<?php

session_name('newLogin');
session_set_cookie_params(2 * 7 * 24 * 60 * 60);
session_start();

unset($_SESSION['username']);
unset($_SESSION['id']);
session_destroy();

header("Location: login.php");
exit;
?>
