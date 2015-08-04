<!-- 
File: add_route_v2.php
Author: cburbine
Course: 91.462 - GUI II Programming
Email: christopher_burbine@student.uml.edu
Description: Adder file for search page. Adds book to appropriate
list. Results can bee seen on home.php.
-->

<?php

include 'connect_test.php'; //connect the connection page

if (empty($_SESSION)) { // if the session not yet started
    session_name('newLogin');
    session_set_cookie_params(2 * 7 * 24 * 60 * 60);
    session_start();
}

#if (!isset($_POST['submit'])) { // if the form not yet submitted
 #   header("Location: search.php");
  #  exit;
#}

if($_GET['route'] != 1){
  header("Location: search_v2.php");
  exit;
}

if (isset($_POST['field'])) {
    $isbn = $_POST['pass_val'];
    $field = $_POST['field'];
    
    //needed for checker functions
    $count_list = 0;
    $count_have = 0;

    //here begins some checker functions, not used in this build
    //will be used in the future
    $data = mysql_query("SELECT * FROM wanted_books WHERE buyer LIKE '%$user%'") or die('Error: ' . mysql_error());

    while ($result = mysql_fetch_array($data)) {
        if ($result['isbn'] == $isbn) {
            $count_list++;
            echo $count_list;
        }
    }
    $data = mysql_query("SELECT * FROM books_for_sale WHERE seller LIKE '%$user%'") or die('Error: ' . mysql_error());

    while ($result = mysql_fetch_array($data)) {
        if ($result['isbn'] == $isbn) {
            $count_have++;
            echo $count_have;
        }
    }
    //here ends checker functions
    
    //checks if the field selected was wanted_books 
    if ($field == 'wanted_books') {
        //if wanted_books it inserts the isbn and currently login user name into the wanted_books table
        $data_w = mysql_query("INSERT INTO wanted_books (isbn, buyer) VALUES ('" . $isbn . "', '" . $_SESSION['username'] . "')") or die(mysql_error());
        header("Location: search_v2.php");
    // checks if the field selected was books_for_sale
    } else if ($field == 'books_for_sale') {
        //if books_for_sale it inserts the isbn and currently login user name into the books_for_sale table
        $data_b = mysql_query("INSERT INTO books_for_sale (isbn, seller) VALUES ('" . $isbn . "', '" . $_SESSION['username'] . "')") or die(mysql_error());
        header("Location: search_v2.php");
    }
}
?>
