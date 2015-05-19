<?php
session_name('newLogin');
session_set_cookie_params(2*7*24*60*60);
session_start();

unset($_SESSION['username']);
unset($_SESSION['id']);
session_destroy();

header("Location: login.php");
exit;
?>
