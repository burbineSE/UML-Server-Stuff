<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">

    <!--
	File: http://weblab.cs.uml.edu/~cburbine/index.html
	Christopher Burbine, UMass Lowell Compter Science Student, christopher_burbine@student.uml.edu
	91.461 GUI Programming I, Assignment 3: Styling Your First Web Page With CSS
	Created on September 10, 2013 at 5:25 PM

	This file acts as a home page for the moment. Right now it is just a welcome pages for the other 
	pages, which will have its content and image(s) updated throughout the semester.    
      
      -->

    <title>Home</title>
    <link href="styles.css" type="text/css" rel="stylesheet">
  </head>
  
  <body>
   <!-- <div class="main">
      <h1><strong>Chris Burbine</strong><br>GUI Development</h1>
      <div class="main_list">
	<ul>
	  
	       List design taken from (http://www.w3schools.com/css/css_navbar.asp) and modified in shape and 
	       color for my home page. This can be seen on all pages currently.
	    
	  <li><a href="http://www.cs.uml.edu/~cburbine/PHPport">Home</a></li>
	  <li><a href="http://www.cs.uml.edu/~cburbine/PHPport/about.php">About Me</a></li>
	  <li><a href="http://www.cs.uml.edu/~cburbine/PHPport/GUI1.php">GUI 1</a></li>
	  <li><a href="http://www.cs.uml.edu/~cburbine/NCBS/home.php">GUI 2</a></li>
	</ul>
      </div>-->
      <?php include 'menu.php';?>
      
      <!--<h2>Welcome</h2>-->
     <br><br><p>Greetings and welcome participant. Please fell free to peruse the many works I completed during my time as a student at UMass Lowell. </p>

      <!--
	  Basic image placement, at the moment the image is unaligned. Technique 
	  taken from w3schools page on the use of img (http://www.w3schools.com
	  /tags/tag_img.asp). Then modified with different sizing and a different 
	  image from (http://imgs.xkcd.com/comics/halting_problem.png).
	-->
      
      <img src="http://imgs.xkcd.com/comics/halting_problem.png" alt="WOTA_xkcd" height="275" width="425">
    </div>
  </body>
</html>
