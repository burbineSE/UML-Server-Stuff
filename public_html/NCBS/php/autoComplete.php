<?php

//file: autoComplete.php
//authors: cburbine, nwarren, schau
//course: 91.462 - GUI II Programming
//email: 
//christopher_burbine@student.uml.edu
//nicholas_warren@student.uml.edu
//sathaun_chau@student.uml.edu
//
//Description: This script will return all data on all books in the bookinfo table.
//The data will be returns as a json object. This script should be called using
//jQuery.ajax(). Used in conjunction with autoComplete.js.
//Database access information
require 'database_info.php';

//Connect to database
mysql_connect("localhost", "cburbine", "cb2788") or die(mysql_error());
mysql_select_db("cburbine") or die(mysql_error());

//Retrieving all book information 
$table = mysql_query('SELECT * FROM bookslice1');

//Creating array to be returnd back in json format
$dataResult = array();

while ($rowData = mysql_fetch_array($table, MYSQL_ASSOC)) {

    //Assigning values to associative array
    $rowObject["index"] = $rowData["index"];
    $rowObject["title"] = $rowData["title"];
    $rowObject["edition"] = $rowData["edition"];
    $rowObject["author"] = $rowData["author"];
    $rowObject["price"] = $rowData["price"];
    $rowObject["subject_number"] = $rowData["subject_number"];
    $rowObject["class_number"] = $rowData["class_number"];
    $rowObject["isbn"] = $rowData["isbn"];

    //Pushing associative array into array to be returned as json
    array_push($dataResult, $rowObject);
}
echo '<p>before encode</p>';
//return results in json format, an ordered array of associative arrays
echo json_encode($dataResult);
?>