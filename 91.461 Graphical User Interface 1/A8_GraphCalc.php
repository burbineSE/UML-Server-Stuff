<!DOCTYPE html>
<!--
    File: http://weblab.cs.uml.edu/~cburbine/A8_GraphCalc.php
    Christopher Burbine, UMass Lowell Compter Science Student, christopher_burbine@student.uml.edu
    91.461 GUI Programming I, Assignment 8: Saving Graphing Formulae in a Server-Side Database
    Created on December 7 1:26 PM

    Builds off of A7's HTML and JavaScript and adds the ability to save formulas entered in the input box
    using PHP.
-->
<html>
    <head>
        <meta charset="utf-8">
        <title>A8: Formulae Saving Graphing Calculator</title>
        <link href="A7_styles.css" rel="stylesheet">
        <script src="http://cdnjs.cloudflare.com/ajax/libs/mathjs/0.15.0/math.min.js"></script>
        <script src="http://ajax.googleapis.com/ajax/libs/jquery/2.0.2/jquery.min.js"></script>
        <script src="A8_JS_GrphCalc.js"></script>
	<!--
	    txt version of my php process request file
	  -->
	<script src="A8_processRequest.txt"></script>
    </head>
    <body>
        <h1><strong>A8: </strong>Saving Graphing Formulae in a Server-Side Database</h1>
        <p><a href="http://www.cs.uml.edu/~cburbine/A8_processRequests.txt">Process Requests PHP file</a> | <a href="http://www.cs.uml.edu/~cburbine/userpass.txt">Constants for Process Request File</a> | <a href="http://www.cs.uml.edu/~cburbine/A3_index_Assign.html">Return to assignments page</a></p>
        <p>Please enter the curve that you would like to plot. Add t to your equation animate the graph. </p>
        <p>Save formulas using the "Save Curve" button. Only use x and t in your equation.</p>
        <div class="dataListMenu">
            <?php include 'A8_processRequests.php'; ?>
        </div>
        <canvas id="myCanvas" width="575" height="575"></canvas>
    </body>
</html>
