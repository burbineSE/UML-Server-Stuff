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
if (!isset($_SESSION['username'])) { //if not yet logged in
    header("Location: login.php?nologin=1"); // send to login page
    exit;
}

if ($_GET['route'] != 1) {
    header("Location: search_v2.php");
    exit;
}

if (isset($_POST['field'])) {
    #echo 'Top ';
    $isbn = $_POST['pass_val'];
    $conD = $_POST['conD'];
    $asking_p = $_POST['ask_price'];
    #$field = $_POST['field'];
    #echo 'Cond: '.$asking_p. ' |';
    //needed for checker functions
    $count_list = 0;
    $count_have = 0;

    $data = mysql_query("SELECT * FROM bookslice1  WHERE isbn = '" . $isbn . "'") or die('Error: ' . mysql_error());

    while ($result = mysql_fetch_array($data)) {
        $title = $result['title'];
        $edition = $result['edition'];
        $author = $result['author'];
        $sub_num = $result['subject_number'];
        $class_num = $result['class_number'];
        if ($asking_p == "") {
            $asking_p = $result['price'];
            #echo $asking_p;
        }
    }
    #echo 'Bot ';
    #echo $title.' '.$edition.' '.$author.' '.$sub_num.' '.$class_num;
    //here ends checker functions

    $data_b = mysql_query("INSERT INTO books_for_sale (isbn, seller, cond, asking_price, title, edition, author, subject_number, class_number) VALUES ('" . $isbn . "', '" . $_SESSION['username'] . "', '" . $conD . "', '" . $asking_p . "', '" . $title . "', '" . $edition . "', '" . $author . "', '" . $sub_num . "', '" . $class_num . "')") or die(mysql_error());
    header("Location: search_v2.php?addbook=1&title=" . $title . "&ap=" . $asking_p . "");
}
?>
