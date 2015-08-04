<!DOCTYPE html>
<html>
    <head>
        <title>NC Bookstack - Book Search</title>
        <meta charset="UTF-8">
        <!--
        file: search.php
        authors: cburbine, nwarren, schau
        course: 91.462 - GUI II Programming
        email: 
        christopher_burbine@student.uml.edu
        nicholas_warren@student.uml.edu
        sathaun_chau@student.uml.edu
        
        Description: This page will allow the user to search for books and display search results.
        -->

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
        <header>
        </header>
        
        <a href="login.php">Return to Main Page</a><br><br>

        <!-- 
        form for searching
        Submitting will refresh page with data being sent via post method.
        -->
        <form name="search" method="post" action="search_v2.php">
            Search for: 
            <!--Search value -->
            <input type="text" name="find" id="find"> in
            <!--Category to search in-->
            <select name="field" id="searchCriteria">
                <option value="title">Title</option>
                <option value="author">Author</option>
                <option value="subject_number">Subject</option>
                <option value="class_number">Class</option>
                <option value="isbn">ISBN Number</option>
            </select>
            <input type="submit" name="search" value="Search" />
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
            echo '<b>Searched for:</b> ' . $find . '<b> in category </b>' . $field;

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

                    echo '<img src="data:image/jpeg;base64,' . base64_encode($result['image']) . '" />';
                    echo '<div class="bookEntry">';
                    echo '<span class="bookDetail">Edition number: ' . $result['edition'] . '</span>';
                    echo '<span class="bookDetail">Author(s): ' . $result['author'] . '</span>';
                    echo '<span class="bookDetail">Price: $' . $result['price'] . '</span>';
                    echo '<span class="bookDetail">Subject number: ' . $result['subject_number'] . '</span>';
                    echo '<span class="bookDetail">Class number: ' . $result['class_number'] . '</span>';
                    echo '<span class="bookDetail">ISBN number: ' . $result['isbn'] . '</span>';

                    echo '<form method="post" value="Add" action="add_route_v2.php?route=1">';
                    //value passer for adder function main differnce between this code 
                    //and normal serach code
                    echo '<input type="hidden" name="pass_val" value="' . $result['isbn'] . '">';
                    echo 'Add to: ';
                    ?>
                    <select name="field" id="searchCriteria">
                        <option value="books_for_sale">Books for Sale</option>
                        <option value="wanted_books">Wanted Books</option>
                    </select>
                    <?php
                    echo '<input type="submit" name="add" value="Submit" id="addKey">';
                    echo '<br><br>';
                    echo '</form>';
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
