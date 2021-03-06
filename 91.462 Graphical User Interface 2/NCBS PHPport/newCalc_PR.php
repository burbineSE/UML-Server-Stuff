
<?php

#File: http://weblab.cs.uml.edu/~cburbine/A8_processRequests.php
#Christopher Burbine, UMass Lowell Compter Science Student, christopher_burbine@student.uml.edu
#91.461 GUI Programming I, Assignment 8: Saving Graphing Formulae in a Server-Side Database
#Created on December 5 1:26 PM


require "userpass.php";
#echo "<h3>" . $_SERVER['REQUEST_URI'] . "</h3>"; #display page url

if (array_key_exists('equation', $_REQUEST)) {
    #echo "<p>Equation is present.</p>";
    $equation = $_REQUEST['equation'];
    #echo "<p>Your eqation is: $equation</p>";
    addEquToDB($equation);
} else {
    #echo "<p>No equation is present.</p>";
    displayEquInDB();
}

function addEquToDB($equation) {
    #echo "<p>Adding equation \"$equation\" to database.</p>";

    mysql_connect("localhost", DATABASE_USERNAME, DATABASE_PS) or die("<p>addEquToDB: Error connecting to database: " . mysql_error() . "</p>");

    echo "Add";				       
    mysql_select_db(DB_NAME) or die("<p>addEquToDB: Error selecting the database: " . mysql_error() . "</p>");

    $result = mysql_query("INSERT INTO equations VALUES ( NULL, NULL, '" . $equation . "')") or die("<p>addEquToDB: Error inserting into the database: " . mysql_error() . "</p>");

    //returns to main page after function is added; taken from: http://stackoverflow.com/questions/353803/redirect-to-specified-url-on-php-script-completion
    //did this so displayEQUInDB populates datalist
    ob_start();

    $url = 'http://weblab.cs.uml.edu/~cburbine/A8_GraphCalc.php';

    while (ob_get_status()) {
        ob_end_clean();
    }

    header("Location: $url");
}

function displayEquInDB() {
    #echo "<p>Displaying equations in database.</p>";

    mysql_connect("localhost", DATABASE_USERNAME, DATABASE_PS) or die("<p>displayEquInDB: Error connecting to database: " . mysql_error() . "</p>");

    #echo "Display";
    mysql_select_db(DB_NAME) or die("<p>displayEquInDB: Error selecting the database: " . mysql_error() . "</p>");

    $result = mysql_query("SELECT * FROM equations") or die("displayEquInDB: Error selecting data from database: " . mysql_error() . "</p>");

    #modification from Prof. Heines' processrequests v5 program
    #echo "<p>n colmus = " . mysql_num_fields($result) . "</p>";
    echo "<form name='frm' id='frm' method='GET'>";
    echo "<label class='curveLabel'>Curve:</label><input list='dataField' name='equation' id='equation' placeholder='Type Curve'>";
    echo "<datalist id='dataField'>";
    while ($row = mysql_fetch_row($result)) {
        for ($k = 0; $k < mysql_num_fields($result); $k++) {
            if ($k === 2) {
                echo "<option value='" . $row[$k] . "'>" . $row[$k] . "</option>";
            }
        }
    }
    echo "</datalist>";
    echo "<input type='submit' id='submitField' value='Save Curve'>";
    echo "</form>";
}
?>
