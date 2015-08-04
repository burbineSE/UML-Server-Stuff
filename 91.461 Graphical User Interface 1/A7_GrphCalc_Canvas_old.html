<!DOCTYPE html>
<!--
    File: http://weblab.cs.uml.edu/~cburbine/A7_GrphCalc_Canvas_old.html
    Christopher Burbine, UMass Lowell Compter Science Student, christopher_burbine@student.uml.edu
    91.461 GUI Programming I, Assignment 7: Creating a Graphing Calculator Using the HTML Canvas
    Created on November 17 1:56 PM
    Re-Created on November 20 5:07 PM due to unknown error

    Used the HTML Canvas method to create a graphing calculator. 
    Basic calculator created in class while the xy axis lines as well as 
    styling were added later.
-->
<html>
  <head>
    <title>A7: HTML Canvas Graphing Calculator</title>
    <meta charset="utf-8">
    <link href="A7_styles.css" rel="stylesheet">
    <script src="http://cdnjs.cloudflare.com/ajax/libs/mathjs/0.15.0/math.min.js"></script>
    <script src="http://ajax.googleapis.com/ajax/libs/jquery/2.0.2/jquery.min.js"></script>
  </head>
  <body>
    <h1><strong>A7: </strong>Creating a Graphing Calculator Using the HTML Canvas</h1>
    <p><a href="http://www.cs.uml.edu/~cburbine/A3_index_Assign.html">Return to assignments page</a></p>
    <p>Please enter the curve that you would like to plot. Add t to your equation animate the graph. Only use x and t in your equation.</p>
    <form name="frm" id="frm" method="GET">
      <label class="curveLabel">Curve:</label><input id="inputField" value="sin(x)*x"><br>
    </form>
    <canvas id="myCanvas" width="575" height="575"></canvas>

    <script>
            //disables enter and y key for input, prevents page from refreshing and breaking
            $(document).keypress(
                    function(event) {
                        if (event.which == '13' || event.which == '121') {
                            event.preventDefault();
                        }
                    });
            var canvas = document.getElementById('myCanvas'),
                    c = canvas.getContext('2d'),
                    //n = number of line segmants
                    n = 100,
                    xmin = -10,
                    xmax = 10,
                    ymin = -10,
                    ymax = 10,
                    math = mathjs(),
                    expr = '',
                    scope = {x: 0, t: 0},
                    tree,
                    time = 0,
                    timeInc = 0.1,
                    tickUnits = 1,
                    //axis stylings
                    axisColor = '#457EFF',
                    lineFont = '8pt Arial Black',
                    tickSize = 15,
                    //relationships of the graph
                    rangex = xmax - xmin,
                    rangey = ymax - ymin,
                    unitx = canvas.width / rangex,
                    unity = canvas.height / rangey,
                    centery = Math.round(Math.abs(ymin / rangey) * canvas.height),
                    centerx = Math.round(Math.abs(xmin / rangex) * canvas.width),
                    iteration = (xmax - xmin) / 1000,
                    scalex = canvas.width / rangex,
                    scaley = canvas.height / rangey;

            //Most of the techniques for building the lines of this graph come from Eric Rowell 
            //at (http://www.html5canvastutorials.com/labs/html5-canvas-graphing-an-equation/). 
            //I than modified them to fit the structure we created in class.
            function drawXaxis() {
                var cXa = canvas.getContext('2d');
                cXa.save();
                cXa.beginPath();
                cXa.moveTo(0, centery);
                cXa.lineTo(canvas.width, centery);
                cXa.strokeStyle = axisColor;
                cXa.lineWidth = 3;
                cXa.stroke();

                //draw tick marks
                var xPosInc = tickUnits * unitx;
                //console.log(xPosInc);
                //console.log(unitx);
                var xpos, unit;
                cXa.font = lineFont;
                cXa.fillStyle = 'white';
                cXa.textAlign = 'center';
                cXa.textBaseline = 'top';

                //draw left tick marks
                //console.log(xPosInc);
                xpos = centerx - xPosInc;
                //console.log(xpos);
                unit = -1 * tickUnits;
                //console.log(unit);
                while (xpos > 0) {
                    cXa.moveTo(xpos, centery - tickSize / 2);
                    cXa.lineTo(xpos, centery + tickSize / 2);
                    cXa.stroke();
                    cXa.fillText(unit, xpos, centery + tickSize / 2 + 3);
                    unit -= tickUnits;
                    xpos = Math.round(xpos - xPosInc);
                }
                //draw right tick marks
                xpos = centerx + xPosInc;
                unit = tickUnits;
                while (xpos < canvas.width) {
                    cXa.moveTo(xpos, centery - tickSize / 2);
                    cXa.lineTo(xpos, centery + tickSize / 2);
                    cXa.stroke();
                    cXa.fillText(unit, xpos, centery + tickSize / 2 + 3);

                    unit += tickUnits;
                    xpos = Math.round(xpos + xPosInc);
                }
                cXa.fillText("(x)", 560, 265);
                cXa.restore();
            }
            function drawYaxis() {
                var cYa = canvas.getContext('2d');
                cYa.save();
                cYa.beginPath();
                cYa.moveTo(centerx, 0);
                cYa.lineTo(centerx, canvas.height);
                cYa.strokeStyle = axisColor;
                cYa.lineWidth = 3;
                cYa.stroke();

                //draw tick marks
                var yPosInc = tickUnits * unity;
                var ypos, unit;
                cYa.font = lineFont;
                cYa.fillStyle = 'white';
                cYa.textAlign = 'right';
                cYa.textBaseline = 'middle';

                //draw top tick marks
                ypos = centery - yPosInc;
                unit = tickUnits;
                while (ypos > 0) {
                    cYa.moveTo(centerx - tickSize / 2, ypos);
                    cYa.lineTo(centerx + tickSize / 2, ypos);
                    cYa.stroke();
                    cYa.fillText(unit, centerx - tickSize / 2 - 3, ypos);
                    unit += tickUnits;
                    ypos = Math.round(ypos - yPosInc);
                }


                //draw bottom tick marks
                ypos = centery + yPosInc;
                unit = -1 * tickUnits;
                while (ypos < canvas.height) {
                    //console.log('here');
                    cYa.moveTo(centerx - tickSize / 2, ypos);
                    cYa.lineTo(centerx + tickSize / 2, ypos);
                    cYa.stroke();
                    cYa.fillText(unit, centerx - tickSize / 2 - 3, ypos);
                    unit -= tickUnits;
                    ypos = Math.round(ypos + yPosInc);
                }
                cYa.fillText("(y)", 310, 10);
                cYa.restore();
            }

            // Curve plotting functions we created in class
            // Listen for fragment value changes.
            window.addEventListener('hashchange', initExprFromHash);

            function setExpr(newExpr) {
                expr = newExpr;
                tree = math.parse(expr, scope);
            }
            function initExprFromHash() {
                var hash = getHashValue();
                if (hash) {
                    setExpr = hash;
                } else {
                    setExpr('sin(x)*x');
                    setHashFromExpr();
                }
                //console.log("'"+hash+"'");
            }
            function setHashFromExpr() {
                setHashValue(expr);
            }
            function drawCurve() {
                var xPixel, //x cord for graph 
                        yPixel, //y cord for graph
                        i, //used for loop below
                        percentX, percentY,
                        mathX, mathY;

                //clear canvas at each call
                c.clearRect(0, 0, canvas.width, canvas.height);

                //axis drawing functions called each time the curve changes so 
                //they wond simply go away when a new curve is created
                drawXaxis();
                drawYaxis();

                c.beginPath();

                //some styling for the curve, unsure how to get this into css
                c.lineWidth = 7;
                //separator styling for positive and negative numbers provided by
                //(http://victorblog.com/html5-canvas-gradient-creator/)
                //then modded to fit to colors instead of three
                var grd = c.createLinearGradient(287, 193, 287, 383);
                //gradient.addColorStop("0", "red");
                //gradient.addColorStop("0.5", "yellow");
                //gradient.addColorStop("0.75", "green");
                //gradient.addColorStop("0.95", "blue");

                grd.addColorStop(0.000, 'rgba(0, 255, 0, 1.000)');
                grd.addColorStop(0.500, 'rgba(0, 255, 0, 1.000)');
                grd.addColorStop(0.501, 'rgba(255, 0, 0, 1.000)');
                grd.addColorStop(1.000, 'rgba(255, 0, 0, 1.000)');
                c.strokeStyle = grd;
                //c.fillStyle = grd;
                //c.fillRect(0, 0, 300.000, 200.000);

                for (i = 0; i < n; i++) {
                    percentX = i / (n - 1);
                    mathX = percentX * (xmax - xmin) + xmin;

                    mathY = evalMathExpr(mathX);

                    percentY = (mathY - ymin) / (ymax - ymin);

                    //flip percentY to match canvas cordinates
                    percentY = 1 - percentY;

                    //console.log(mathX);
                    //console.log(precentX);
                    //console.log(percentY);

                    xPixel = percentX * canvas.width;
                    yPixel = percentY * canvas.height;
                    c.lineTo(xPixel, yPixel);
                }
                c.stroke();
            }
            function evalMathExpr(mathX) {
                scope.x = mathX;
                scope.t = time;
                return tree.eval();
            }
            function initTextFeild() {
                // Make a jQuery selection to access the input DOM element.
                var input = $('#inputField');

                // Set the initial text value programmatically using jQuery.
                input.val(expr);

                // Listen for changes using jQuery.
                input.keyup(function(event) {
                    expr = input.val();
                    //var text = input.val();
                    tree = math.parse(expr, scope);
                    //console.log(text);
                    drawCurve();
                });
            }
            function startAnimation() {
                //setInterval(render, 20);
                (function animloop() {
                    requestAnimationFrame(animloop);
                    render();
                }());
            }
            function render() {
                //console.log('hello');
                //incremnt time
                time += timeInc;

                //redraw
                drawCurve();
            }
            // Gets the fragment identifier value.
            function getHashValue() {
                return location.hash.substr(1);
            }

            // Sets the fragment identifier value.
            function setHashValue(value) {
                return location.hash = value;
            }

            initExprFromHash();
            drawCurve();
            initTextFeild();
            startAnimation();
        </script>        
    </body>
</html>
