<!DOCTYPE html>
<!-- 
File: free_search.php
Author: cburbine
Course: 91.462 - GUI II Programming
Email: christopher_burbine@student.uml.edu
Description: Search used by home.php when a user 
in not logged in. 
-->
<?php
include 'connect_test.php'; //connect the connection page

if (empty($_SESSION)) { // if the session not yet started
    session_name('newLogin');
    session_set_cookie_params(2 * 7 * 24 * 60 * 60);
    session_start();
}
?>
<html>
    <head>
        <title>NC Bookstack - Book Search</title>
        <meta charset="UTF-8">
        <?php
        $onsearch == 1;
        include 'toptab_nologin.php';
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

    </head>
    <body>

        <!-- 
        form for searching
        Submitting will refresh page with data being sent via post method.
        -->
        <br><br>
        <form id="searchfrm" name="search" method="post" action="free_search.php">
            <span class="serachspan" >Search for:</span>
            <!--Search value -->
            <input type="text" name="find" id="find"> 
            <span class="serachspan" style="font-size:125%;">in</span>
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

            $find = strip_tags($find);
            $find = trim($find);

            //mySQL query returning search results from table
            $data = mysql_query("SELECT * FROM bookslice1 WHERE $field LIKE'%$find%'");

            //Displaying search results
            echo '<p id="searchres"><b>Searched for:</b> ' . $find . '<b> in category </b>' . $field . '</p>';

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
                    echo '</div>';
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
