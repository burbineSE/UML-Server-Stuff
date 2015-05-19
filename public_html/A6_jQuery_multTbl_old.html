<!DOCTYPE html>
<!--
    File: http://weblab.cs.uml.edu/~cburbine/A6_jQuery_multTbl.html
    Christopher Burbine, UMass Lowell Compter Science Student, christopher_burbine@student.uml.edu
    91.461 GUI Programming I, Assignment 6: Using the jQuery Validation Plugin with Your Dynamic Table
    Created on November 2, 2013 at 3:06 PM
    Modifications made November 7, 2013 at 12:44 PM; Moded after the submition, forgot to credit Pro. Heines for getParameter

    The HTML doc for assignment 6, builds a dynamic table from user input
    Checks input for errors before submitting using jQuery
  -->
<html>
  <head>
    <title>A6: jQuery Dynamic Table</title>
    <meta charset=UTF-8>
    <link href="A6_styles.css" type="text/css" rel="stylesheet">
    <script src="//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
    <script src="jquery-validation-1.11.1/dist/jquery.validate.min.js" type="text/javascript"></script>
    <script src="jquery-validation-1.11.1/dist/additional-methods.min.js" type="text/javascript"></script>
    <script>
            var frm;
            var topNF = 'topNumFirst';
            var topNL = 'topNumLast';
            var sideNF = 'sideNumFirst';
            var sideNL = 'sideNumLast';

            $(document).ready(function() {

                //an attempt at comparing the first a last values entered 
                //realized that timing of things could not do what I wanted it to as this is loaded before the body
                /*$.validator.addMethod('lessThanEqual', function(value, element, param) {
                 return this.optional(element) || parseInt(value) <= parseInt($(param).val());
                 }, "The value {0} must be less than {1}");*/

                $('#frm').validate({
                    //All of the rules check for empty inputs, isNaN, greater than 99 or less than 0 and white space.
                    //Halts the submit if any of these trip
                    rules: {
                        topNumFirst: {
                            nowhitespace: true,
                            required: true,
                            number: true,
                            range: [0, 99]
                                    //lessThanEqual: $('#topNumLast').val()
                        },
                        topNumLast: {
                            nowhitespace: true,
                            required: true,
                            number: true,
                            range: [0, 99]
                        },
                        sideNumFirst: {
                            nowhitespace: true,
                            required: true,
                            number: true,
                            range: [0, 99]
                        },
                        sideNumLast: {
                            nowhitespace: true,
                            required: true,
                            number: true,
                            range: [0, 99]
                        }
                    }, // rules end
                    messages: {
                        topNumFirst: {
                            nowhitespace: "* Please remove all white space.",
                            required: "* Please enter you first multiplier.",
                            number: "* Make sure your first multiplier is a number.",
                            range: "* Make sure your first multiplier is between 0 and 99."
                        },
                        topNumLast: {
                            nowhitespace: "* Please remove all white space.",
                            required: "* Please enter you last multiplier.",
                            number: "* Make sure your last multiplier is a number.",
                            range: "* Make sure your last multiplier is between 0 and 99."
                        },
                        sideNumFirst: {
                            nowhitespace: "* Please remove all white space.",
                            required: "* Please enter you first multiplicand.",
                            number: "* Make sure your first multiplicand is a number.",
                            range: "* Make sure your first multiplicand is between 0 and 99."
                        },
                        sideNumLast: {
                            nowhitespace: "* Please remove all white space.",
                            required: "* Please enter you last multiplicand.",
                            number: "* Make sure your last multiplicand is a number.",
                            range: "* Make sure your last multiplicand is between 0 and 99."
                        }
                    }//messages end
                }); //validate end

                //console.log($('#topNumFirst').val());
            }); // end ready

             /** This function gets the value of a named parameter and returns a single
             *  string value or null if the named parameter does not exist.
             *
             *  If there is more than one parameter with the same name in the location.search
             *  string, this function returns only the first one.  If you know that there
             *  will be more than one parameter with the same name, use the getMultiParameter
             *  function below instead of this one.
             *
             *  Author:  Jesse M. Heines, UMass Lowell Computer Science, heines@cs.uml.edu
             *  Revised: by JMH on January 31, 2002 at 11:56 AM
             *  Parameters:
             *     (1)  strName  the name of the parameter to extract
             *  Return Value:
             *     string  value of specified parameter or null if the parameter does not exist
             */

            function getParameter(strName) {
                // extract the address part starting at the "?"
                var strSearch = "" + location.search;

                // find the location of the field name you're looking for
                var intStart = strSearch.indexOf(strName + "=");

                // make sure that field name is not part of a larger field name,
                // that is, a substring of a larger field name
                var boolOK = (intStart > 0) &&
                        (strSearch.charAt(intStart - 1) == "?" ||
                                strSearch.charAt(intStart - 1) == "&")

                // if the field is not found or is part of a larger field name, 
                // return null
                if (!boolOK) {
                    return null;

                    // else extract the field's value and return it
                } else {
                    // extract from the start of the value to the end of the entire
                    // search string and append an ampersand to the end of the 
                    // extract value string
                    var strValue =
                            strSearch.substr(intStart + strName.length + 1) + "&";

                    // find the position of the first ampersand in the value string
                    // and return the substring ending at the first ampersand
                    return strValue.substr(0, strValue.indexOf("&"));
                }
            }

            function checkParas() {
                //if the first number is larger than the second then the values are swapped
                //could not find a way to to this error check in jQuery
                var swap;
                var checker = frm.topNumLast.value - frm.topNumFirst.value;
                if (checker < 0) {
                    swap = frm.topNumLast.value;
                    if(swap == '' || swap > 99 || frm.topNumFirst.value > 99){
                       //console.log('There!');
                       doNothing();
                    } else{
                        frm.topNumLast.value = frm.topNumFirst.value;
                        frm.topNumFirst.value = swap;
                    }
                }
                checker = frm.sideNumLast.value - frm.sideNumFirst.value;
                if (checker < 0) {
                    swap = frm.sideNumLast.value;
                    if(swap == '' || swap > 99 || frm.sideNumFirst.value > 99){
                       //console.log('There!');
                       doNothing();
                    } else {
                        frm.sideNumLast.value = frm.sideNumFirst.value;
                        frm.sideNumFirst.value = swap;
                    }
                }
                //return false;
            }

            function printTbl() {
                var topLine = new Array();
                var sideLine = new Array();

                //lines below replaces the values of any undefined values
                //mainly here for the first load when nothing has been entered yet
                var n = getParameter(topNF);
                if (n !== null) {
                    var tN1 = parseInt(n);
                }
                if (tN1 == undefined) {
                    tN1 = 0;
                }

                n = getParameter(topNL);
                if (n !== null) {
                    var tN2 = parseInt(n);
                }
                if (tN2 == undefined) {
                    tN2 = 10;
                }

                n = getParameter(sideNF);
                if (n !== null) {
                    var sN1 = parseInt(n);
                }
                if (sN1 == undefined) {
                    sN1 = 0;
                }

                n = getParameter(sideNL);
                if (n !== null) {
                    var sN2 = parseInt(n, 10);
                }
                if (sN2 == undefined) {
                    sN2 = 10;
                }

                topLine[0] = tN1;
                var sub = tN2;
                var diff = tN2 - tN1;
                topLine[diff] = tN2;
                --diff;

                for (; diff > 0; --diff) {
                    sub = sub - 1;
                    topLine[diff] = sub;
                }

                sideLine[0] = sN1;
                sub = sN2;
                diff = sN2 - sN1;
                sideLine[diff] = sN2;
                --diff;

                for (; diff > 0; --diff) {
                    sub = sub - 1;
                    sideLine[diff] = sub;
                }

                var tabArray = new Array(sideLine.length);
                for (i = 0; i < sideLine.length; i++) {
                    tabArray[i] = new Array(topLine.length);
                }

                var tL;
                var sL;

                for (i = 0; i < sideLine.length; ++i) {
                    for (j = 0; j < topLine.length; ++j) {
                        tL = topLine[j];
                        sL = sideLine[i];
                        tabArray[i][j] = sL * tL;
                    }
                }
                /*Table build method taken from 
                 * (http://www.webdeveloper.com/forum/showthread.php?174117-Create-dynamic-table-with-javascript)
                 * created by user Kor. Modified to accommodate the outside row and column.*/
                var root = document.getElementById('mydiv');
                var tab = document.getElementById('tab');
                if (tab !== null) {
                    root.removeChild(tab);
                }
                //console.log(tab);
                var tab = document.createElement('table');
                tab.setAttribute("id", "tab");

                var tabBd = document.createElement('tbody');
                var row, cell;

                //First set creates the top row with the list of multipliers, startong with a blank space. 
                row = document.createElement('tr');
                cell = document.createElement('td');
                cell.appendChild(document.createTextNode(''));
                row.appendChild(cell);
                for (i = 0; i < topLine.length; i++) {
                    cell = document.createElement('td');
                    cell.appendChild(document.createTextNode(topLine[i]));
                    row.appendChild(cell);
                }
                tabBd.appendChild(row);

                //Next set creates the remaining rows, placing an element from the multiplicand array at the head of each row
                for (i = 0; i < sideLine.length; i++) {
                    //document.write("Here!");
                    row = document.createElement('tr');

                    cell = document.createElement('td');
                    cell.appendChild(document.createTextNode(sideLine[i]));
                    row.appendChild(cell);
                    for (j = 0; j < topLine.length; ++j) {
                        cell = document.createElement('td');
                        cell.appendChild(document.createTextNode(tabArray[i][j]));
                        row.appendChild(cell);
                    }
                    //document.write("<br>");
                    tabBd.appendChild(row);
                }
                tab.appendChild(tabBd);
                root.appendChild(tab);
            }

            function init() {
                frm = document.getElementById("frm");
            }
    </script>
  </head>
  <body onload="init();
                printTbl();
                document.getElementById('topNumFirst').focus();">
    <h1><strong>A6: </strong>Dynamic jQuery Multiplication Table</h1>
    <p><a href="http://www.cs.uml.edu/~cburbine/A3_index_Assign.html">Return to assignments page</a></p>
    <p>Please enter four numbers between 0 and 99, where the first multiplier is smaller than the last and the first multiplicand is smaller than the last.</p>
    <form name="frm" id="frm" method="GET" onsubmit="return checkParas();">
      <label class="inputLb">First Multiplier:</label><input type="text" name="topNumFirst" id="topNumFirst" tabindex="1" value="0"><br>
      <label class="inputLb">Last  Multiplier:</label><input type="text" name="topNumLast" id="topNumLast" tabindex="2" value="10"><br>
      <label class="inputLb">First Multiplicand:</label> <input type="text" name="sideNumFirst" id="sideNumFirst" tabindex="3" value="0"><br>
      <label class="inputLb">Last  Multiplicand:</label> <input type="text" name="sideNumLast" id="sideNumLast" tabindex="4" value="10"><br>
      <input id="subButton" type="submit" value="Build!" tabindex="5">
    </form>
    <div id="mydiv"></div>
    <p><a href="http://www.cs.uml.edu/~cburbine/A3_index_Assign.html">Return to assignments page</a></p>
  </body>
</html>
