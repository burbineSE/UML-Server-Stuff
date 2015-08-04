<!DOCTYPE html>
<!-- 
File: search_v2.php
Author: cburbine
Course: 91.462 - GUI II Programming
Email: christopher_burbine@student.uml.edu
Description: This page will allow the user to 
search for books and display search results.
-->
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
<html>
    <head>
        <title>NC Bookstack - Book Search</title>
        <meta charset="UTF-8">

        <?php
        $onsearch == 1;
        include 'toptab.php';
        ?>

        <!-- jQuery UI theme roller css -->
        <link rel="stylesheet" type="text/css" href="jquery-ui-1.10.4.custom/css/ui-lightness/jquery-ui-1.10.4.custom.min.css">
        <!-- css for formatting book data entries -->
        <link rel="stylesheet" type="text/css" href="css/bookData.css">
        <link rel="stylesheet" type="text/css" href="css/mainCSS.css">

        <!-- jQuery and jQuery UI libraries -->
        <script src="js/jquery-1.11.0.min.js"></script>
        <script src="jquery-ui-1.10.4.custom/js/jquery-ui-1.10.4.custom.min.js"></script>

        <!-- 
        Javascript for adding search functionality, adding auto-complete to search, 
        and adding accordian widget to search results.
        -->
        <script src="js/search.js"></script>
        <script src="js/autoComplete.js"></script>
        <script src="js/searchAccordian.js"></script>
        <script>
            $(function() {
                $("#dialog-message").dialog({
                    modal: true,
                    buttons: {
                        OK: function() {
                            $(this).dialog("close");
                        }
                    }
                });
            });
        </script>
        <?php
        //$onsearch == 1;
        //include 'toptab.php'; 
        ?>
    </head>
    <body>
        <?php
        if ($_GET['addbook'] == 1) {
            $title = $_GET['title'];
            $ap = $_GET['ap'];
            echo '<div id="dialog-message" title="Book Added">
	<p>
	  <span class="ui-icon ui-icon-circle-check" style="float:left; margin:o 7px 50px 0;"></span>
	  A copy of <i>' . $title . '</i> has been added to your books for sale list at an asking price of $' . $ap . '.
	</p>
      </div>';
        }
        ?>
        <!--<a href="login.php">Return to Main Page</a><br><br>-->

        <!-- 
        form for searching
        Submitting will refresh page with data being sent via post method.
        -->
        <br><br>
        <form id="serachfrm" name="search" method="post" action="search_v2.php">
            <span class="serachspan" style="font-size:125%;">Search for:</span> 
            <!--Search value -->
            <input type="text" name="find" id="find"> 
            <span class="serachspan" style="font-size:125%;">in</span>
            <!--Category to search in-->
            <select name="field" id="searchCriteria">
                <option value="title">Title</option>
                <option value="author">Author</option>
                <option value="subject_number">Subject</option>
                <option value="class_number">Class</option>
                <option value="isbn">ISBN</option>
            </select>
            <input id="searchfrm" type="submit" name="search" value="Search" />
        </form>

        <?php
        //following search method based off of code at
        //http://php.about.com/od/phpwithmysql/ss/php_search.htm
        //Display search results if find and field index exist
        if (isset($_POST['find']) && isset($_POST['field'])) {

            $find = $_POST['find'];
            $field = $_POST['field'];

            //Connect to database
            mysql_connect("localhost", "cburbine", "cb2788") or die(mysql_error());
            mysql_select_db("cburbine") or die(mysql_error());

            $find = strip_tags($find);
            $find = trim($find);

            //mySQL query returning search results from table
            $data = mysql_query("SELECT * FROM bookslice1 WHERE $field LIKE'%$find%'");

            //Displaying search results
            echo '<p id="serachres"><b>Searched for:</b> ' . $find . '<b> in category </b>' . $field . '</p>';

            echo '<h2>Found: </h2>';

            //Conditional statments to warn user in
            //case search value or category are blank.
            if ($find == "") {
                echo '<p>Please enter a value to search for</p>';
                exit();
            }
            if ($field == "") {
                echo '<p>Please select a category to search in</p>';
                exit();
            }

            //Only display results if there are any
            if (mysql_num_rows($data) > 0) {

                echo '<div id="searchAccordian">';

                while ($result = mysql_fetch_array($data)) {

                    echo '<h3><span class="bookDetail">Title: ' . $result['title'] . '</span></h3>';
                    echo '<div>';

                    echo '<img class="bookimg" src="data:image/jpeg;base64,' . base64_encode($result['image']) . '" />';
                    echo '<div class="bookEntry">';
                    echo '<span class="bookDetail">Edition number: ' . $result['edition'] . '</span>';
                    echo '<span class="bookDetail">Author(s): ' . $result['author'] . '</span>';
                    echo '<span class="bookDetail">Price: $' . $result['price'] . '</span>';
                    echo '<span class="bookDetail">Subject number: ' . $result['subject_number'] . '</span>';
                    echo '<span class="bookDetail">Class number: ' . $result['class_number'] . '</span>';
                    echo '<span class="bookDetail">ISBN number: ' . $result['isbn'] . '</span>';
                    $thisisbn = $result['isbn'];

                    echo '<form method="post" value="Add" action="add_route_v2.php?route=1">';
                    //value passer for adder function main differnce between this code 
                    //and normal serach code
                    echo '<input type="hidden" name="pass_val" value="' . $result['isbn'] . '">';
                    echo '<br>';
                    echo 'Asking Price: $<input type="text" name="ask_price">';
                    echo '<br>Condition: ';
                    ?>
                    <select name="conD">
                        <option value="New">New</option>
                        <option value="Good">Good</option>
                        <option value="Used">Used</option>
                        <option value="Bad">Bad</option>
                        <option value="Very Bad">Very Bad</option>
                    </select><br>
                    <?php
                    echo '<input type="submit" name="field" value="Add to My Books for Sale" id="addKey">';
                    echo '<br><br>';
                    echo '</form>';
                    echo '</div>';
                    ?>
                    <div class="sellerAccordian">
                        <h3>Users selling this book</h3>
                        <div>
                            <table class="sellerList" cellspacing="10">  
                                <!--<tr>
                                    <td>Username</td><td>Asking Price</td><td>Condition</td>
                                <tr>-->
                                <tr>
                                    <?php
                                    $sellerdata = mysql_query("SELECT * FROM books_for_sale WHERE isbn = '" . $thisisbn . "'") or die("Error: " . mysql_error());
                                    $writetop = 0;
                                    if (mysql_num_rows($sellerdata) == 0) {
                                        echo "No users currently selling this book.";
                                    } else {
                                        while ($result_bfs = mysql_fetch_array($sellerdata)) {
                                            if ($result_bfs['seller'] == $_SESSION['username'] && mysql_num_rows($sellerdata) == 1) {
                                                #echo "HERE";
                                                echo "No users currently selling this book.";
                                            } else if (mysql_num_rows($sellerdata) == 0) {
                                                echo "No users currently selling this book.";
                                            } else {
                                                if ($writetop == 0) {
                                                    echo '<tr><td>Username</td><td>Asking Price</td><td>Condition</td><tr>';
                                                    $writetop++;
                                                }
                                                if (!($result_bfs['seller'] == $_SESSION['username'])) {
                                                    echo '<tr><td>' . $result_bfs['seller'] . '</td><td>$' . $result_bfs['asking_price'] . '</td><td>' . $result_bfs['cond'] . '</td>';

                                                    $thisseller = $result_bfs['seller'];
                                                    echo '<td>
                                         <form action="message_form.php">
					   <input type="submit" value="Request Trade">
                                           <input type="hidden" name="isbn" value="' . $thisisbn . '">
                                           <input type="hidden" name="seller" value="' . $thisseller . '">
                                         </form>
                                         </td> <tr>';
                                                }
                                            }
                                        }
                                    }
                                    ?>
                                <tr>
                                <!--<tr>
                                    <td>Chris Burbine</td><td>$98.00</td><td>Almost New</td>
                                    <td>
                                        <form action="message_form.php"><input type="submit" value="Buy">
                                            <input type="hidden" name="isbn" value="0072848235">
                                            <input type="hidden" name="seller" value="cburbine">
                                        </form>
                                    </td>
                                <tr>
                                <tr>
                                    <td>Mike Cooper</td><td>$82.00</td><td>Good</td>
                                    <td>
                                        <form action="message_form.php"><input type="submit" value="Buy">
                                            <input type="hidden" name="isbn" value="0072848235">
                                            <input type="hidden" name="seller" value="cburbine">
                                        </form>
                                    </td>
                                <tr>
                                <tr>
                                    <td>Tim Leblanc</td><td>$76.00</td><td>Used</td>
                                    <td>
                                        <form action="message_form.php"><input type="submit" value="Buy">
                                            <input type="hidden" name="isbn" value="0072848235">
                                            <input type="hidden" name="seller" value="cburbine">
                                        </form>
                                    </td>
                                <tr>
                                <tr>
                                    <td>Matt O'leary</td><td>$85.00</td><td>Good</td>
                                    <td>
                                        <form action="message_form.php"><input type="submit" value="Buy">
                                            <input type="hidden" name="isbn" value="0072848235">
                                            <input type="hidden" name="seller" value="cburbine">
                                        </form>
                                    </td>
                                <tr>-->
                            </table>
                        </div>
                    </div>
                    <?php
                    echo '</div>';
                }

                echo '</div>';
            } else {
                //If no results, display following message
                echo '<p>Request not found</p>';
            }
        } else {
            
        }
        ?>

    </body>
</html>
