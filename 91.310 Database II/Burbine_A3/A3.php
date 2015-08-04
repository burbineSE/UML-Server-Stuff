<?php

$table = $_GET['table'];
$attr = $_GET['attr'];

mysqli_connect("localhost", "root", "root", "baseballtables") 
        or die(mysql_error());

if($table == "Player"){
    $table = "master";
    $sql_query = mysqli_query($link, "select * from $table where nameGiven like'%$attr%'");
} else if($table == "Team"){
    $table = "teams";
    $sql_query = mysqli_query($link, "select * from $table where name like'%$attr%'");
} else if ($table == "Manager") {
    $table = "managers";
    $sql_query = mysqli_query($link, "select * from $table, master where $table.playerID = master.playerID and master.nameGiven like'%$attr%'");
} else if ($table == "Player Award"){
    $table = "awardsplayers";
    $sql_query = mysqli_query($link, "select * from $table, master where $table.playerID = master.playerID and master.nameGiven like'%$attr%'");
} else if ($table == "Salary"){
    $table = "salaries";
    $sql_query = mysqli_query($link, "select * from $table, master where $table.playerID = master.playerID and master.nameGiven like'%$attr%'");
}

while($row = mysqli_fetch_assoc($sql_query)){
    $output[] = $row;
    print(json_encode($output));
    mysqli_close($link);
}

?>

