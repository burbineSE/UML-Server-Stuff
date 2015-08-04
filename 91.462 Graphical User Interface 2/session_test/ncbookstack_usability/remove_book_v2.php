<!-- 
File: remove_book_v2.php
Author: cburbine
Course: 91.462 - GUI II Programming
Email: christopher_burbine@student.uml.edu
Description: Removes book from appropriate list when called.
Can only remove on book at a time atm.
-->
<?php

include 'connect_test.php'; //connect the connection page

if (empty($_SESSION)) { // if the session not yet started
    session_name('newLogin');
    session_set_cookie_params(2 * 7 * 24 * 60 * 60);
    session_start();
}

$isbn = $_POST['pass_val'];
$isbn2 = $_POST['pass_valCT'];

//if we are working with wanted list
if ($isbn == '') {
    #$delete_data = mysql_query("DELETE FROM wanted_books WHERE isbn='$isbn2' LIMIT 1")or die('Error: ' . mysql_error());
    $delete_data = mysql_query("DELETE FROM current_transactions WHERE isbn='$isbn2' LIMIT 1")or die('Error: ' . mysql_error());
    header('Location: home.php');
//if we are dealing with selling list
} else if ($isbn2 == '') {
    $delete_data = mysql_query("DELETE FROM books_for_sale WHERE isbn='$isbn' LIMIT 1")or die('Error: ' . mysql_error());
    header('Location: home.php');
} else {
    header('Location: home.php');
}
?>
