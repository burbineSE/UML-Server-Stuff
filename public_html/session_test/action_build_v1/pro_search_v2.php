<!DOCTYPE html>
<html>
  <head>
    <script src="js/jquery-1.11.0.min.js"></script>
    <script src="jquery-ui-1.10.4.custom/js/jquery-ui-1.10.4.custom.min.js"></script>
    <script src="search.js"></script>
    <script src="autoComplete.js"></script>
    <script src="searchAccordian.js"></script>
  </head>
  <body>
    <?php 
       include 'connect_test.php'; //connect the connection page
       include 'search.php';
       
       if (isset($_POST['searching']) && isset($_POST['find']) && isset($_POST['field'])) {
       
       $searching = $_POST['searching'];
       $find = $_POST['find'];
       $field = $_POST['field'];    
       
       if ($searching == "yes") {
       echo '<h2>Found: </h2><p>';
       if ($find == "") {
       echo '<p>Search field empty';
       exit();
       }
       if ($field == "") {
       echo 'Please select what to search by';
       exit();
       }
       $find = strtoupper($find);
       $find = strip_tags($find);
       $find = trim($find);
       
       $data = mysql_query
       ("SELECT * FROM bookslice1 WHERE $field LIKE'%$find%'");
       
       echo '<b>Searched for:</b> ' . $find . '<b> in category </b>' . $field;
       echo '<br><br>';
       if(mysql_num_rows($data) > 0){
    while ($result = mysql_fetch_array($data)) {
    $isbn = $result['isbn'];
    echo '<form method="post" value="Add" action="add_route_v2.php">';
      echo 'Title: ' . $result['title'];
      echo '<br>';
      echo 'Author(s): ' . $result['author'];
      echo '<br>';
      echo 'Price: $' . $result['price'];
      echo '<br>';
      echo 'Subject number: ' . $result['subject_number'];
      echo '<br>';
      echo 'Class number: ' . $result['class_number'];
      echo '<br>';
      echo 'ISBN number: ' . $result['isbn'];
      echo '<br>';
      #added an echo to display the blob image
      echo '<img src="data:image/jpeg;base64,' . base64_encode($result['image']) . '" />';
      echo '<br>';
      echo '<input type="hidden" name="pass_val" value="'.$isbn.'">';
      echo 'Add to: ';
      ?>
    <select name="field" id="serachCriteria">
      <option value=""></option>
      <option value="books_for_sale">Books for Sale</option>
      <option value="wanted_books">Wanted Books</option>
    </select>
    <?php
       echo '<input type="submit" name="add" value="Submit" id="addKey">';
       echo '<br><br>';
       echo '</form>';
       }
       $anymatches = mysql_num_rows($data);
       if ($anymatches == 0) {
       echo 'Request not found<br><br>';
       }
       }
       }
       }
       ?>
  </body>
</html>
