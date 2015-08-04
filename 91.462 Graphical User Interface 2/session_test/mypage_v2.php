<?php include 'tab_template.php'; ?>
 <div id="main">
    <div class="container">
      <h1>My Profile</h1>
    </div>
    <div class="container">
      <?php
        if($_SESSION['id']){
           $user = $_SESSION['usr'];
           #echo $_SESSION['usr'];
           $data = mysql_query("SELECT * FROM tz_members WHERE usr LIKE'%$user%'")or die('Error: '.mysql_error());
           if(!$data){
             echo 'Could not run: '.mysql_error();
             exit;
           }
           while($result = mysql_fetch_array($data)){
             echo '<p><strong>Username</strong>: '   .$result['usr'].  '</p>';
             echo '<p><strong>Email</strong>: '      .$result['email'].'</p>';
           }
        echo '<div class="container">';
        echo '<h3><strong>Books for Sale</strong></h3>';
        $book_data = mysql_query("SELECT * FROM books_for_sale WHERE seller LIKE'%$user%'")or die('Error: '.mysql_error());

        if(!$book_data){
           echo 'Could not run: '.mysql_error();
           exit;
        }
        while($result = mysql_fetch_array($book_data)){
         $isbn = $result['isbn'];
         $asking_price = $result['asking_price'];
         echo '<div class="container">';
         echo '<strong>Asking Price</strong>: $'. $asking_price. '<br>';
         $slice_data = mysql_query("SELECT * FROM bookslice1 WHERE isbn LIKE'%$isbn%'")or die('Error: '.mysql_error());
         while($result_inner = mysql_fetch_array($slice_data)){
            echo '<strong>Title</strong>: '.$result_inner['title'];
            echo '<br>';
            echo '<strong>Edition</strong>: '.$result_inner['edition'];
            echo '<br>';
            echo '<strong>Author(s)</strong>: '.$result_inner['author'];
            echo '<br>';
            echo '<strong>Class Number</strong>: '.$result_inner['subject_number'].'.'.$result_inner['class_number'];
            echo '<br>';
            echo '<strong>ISBN</strong>: '.$result_inner['isbn'];
            echo '<br>';
            }
            echo '</div>';
        }
        echo '</div>';

	 echo '<div class="container">';
         echo '<h3><strong>Wanted Books</strong></h3>';
         $wanted_data = mysql_query("SELECT * FROM wanted_books WHERE buyer LIKE'%$user%'")or die ('Error: '.mysql_error());
        #echo $wanted_data;

        if(!$wanted_data){
          echo 'Could not run: '.mysql_error();
        }
        while($result = mysql_fetch_array($wanted_data)){
          $isbn2 = $result['isbn'];
          #echo $isbn2;
          echo '<div class="container">';
          $slice_data = mysql_query("SELECT * FROM bookslice1 WHERE isbn LIKE'%$isbn2%'")or die('Error slice: '.mysql_error());
          #echo 'here';
          #echo $slice_data.'<br>';
          while($result_inner = mysql_fetch_array($slice_data)){
            echo '<strong>Title</strong>: '.$result_inner['title'];
            echo '<br>';
            echo '<strong>Edition</strong>: '.$result_inner['edition'];
            echo '<br>';
            echo '<strong>Author(s)</strong>: '.$result_inner['author'];
            echo '<br>';
            echo '<strong>Class Number</strong>: '.$result_inner['subject_number'].'.'.$result_inner['class_number'];
            echo '<br>';
            echo '<strong>ISBN</strong>: '.$result_inner['isbn'];
            echo '<br>';
          }
          echo '</div>';
        }
        echo '</div>';
        } else {
             echo '<h2>Please, <a href="demo.php">login</a> and come back later!</h2>';
        }
        ?>
        </div>

</body>
</html>
