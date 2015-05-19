<!-- 
File: connect_test.php
Author: cburbine
Course: 91.462 - GUI II Programming
Email: christopher_burbine@student.uml.edu
Description: MySQL database connect file. Names removed. 
Used as a basic connection file. 
-->
<?php
$link = mysql_connect("localhost","cburbine","cb2788") or die(mysql_error()); 
mysql_select_db("cburbine", $link);
?> 
