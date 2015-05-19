<!DOCTYPE html>
<html>
    <head><title>Example</title></head>
    <body>
        
        <?php
	$_boxValue = $_POST['boxes'];
       	$buyer = $_POST['user'];

        if (isset($_POST['boxes']) && !empty($_POST['boxes'])) {

            foreach ($_POST['boxes'] as $_boxValue) {
                echo '<p>ISBN '.$_boxValue.' selected.</p>';
	        echo '<p>Buyer: '.$buyer.'</p>';
                #$data = mysql_query("INSERT INTO wanted_books (isbn, buyer) VALUES ('".$_boxValue."', '".$buyer."')");
	        echo '<p> Query: '.$data.'</p>';
            }
            header("Location: http://weblab.cs.uml.edu/~cburbine/session_test/search.php");
        } else {
            echo 'No boxes were selected';
        }
        ?>
        
    </body>
</html>
