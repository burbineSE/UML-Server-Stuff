<!--
            File: http://weblab.cs.uml.edu/~cburbine/A5_multTbl.html
            Christopher Burbine, UMass Lowell Compter Science Student, christopher_burbine@student.uml.edu
            91.461 GUI Programming I, Assignment 5: Creating an Interactive Dynamic Table
            Created on October 25, 2013 at 1:21 PM
        
            The HTML doc for assignment 5, builds a dynamic table from user input
        -->

<!DOCTYPE html>
<html>
  <head>
    <title>A5: Dynamic Table</title>
    
    <link href="A5_styles.css" type="text/css" rel="stylesheet">
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <script>
            var frm;
            var topNF = 'topNumFirst';
            var topNL = 'topNumLast';
            var sideNF = 'sideNumFirst';
            var sideNL = 'sideNumLast';

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
	    // checkParas function checks input for any errors
            function checkParas() {
                frm.topNumFirst.value = frm.topNumFirst.value.trim();
                frm.topNumLast.value = frm.topNumLast.value.trim();
                frm.sideNumFirst.value = frm.sideNumFirst.value.trim();
                frm.sideNumLast.value = frm.sideNumLast.value.trim();

	        //if input is empty resets to 0 and 10
                if (frm.topNumFirst.value == "") {
                    frm.topNumFirst.value = 0;
                } else if (frm.topNumLast.value == "") {
                    frm.topNumLast.value = 10;
                } else if (frm.sideNumFirst.value == "") {
                    frm.sideNumFirst.value = 0;
                } else if (frm.sideNumLast.value == "") {
                    frm.sideNumLast.value = 10;
                } else {
	            //if input is NaN, resets values to 0 and 10 depending on its 
                    //position in the table, if the last number is NaN and the fist 
                    //number is not sets the last number to the first number + 1
                    if(isNaN(frm.topNumFirst.value) && isNaN(frm.topNumLast.value) && isNaN(frm.sideNumFirst.value) && isNaN(frm.sideNumLast.value)){
                        frm.topNumFirst.value = 0;
                        frm.topNumLast.value = 10;
                        frm.sideNumFirst.value = 0;
                        frm.sideNumLast.value = 10;
                    }
                    if(isNaN(frm.topNumFirst.value) && isNaN(frm.topNumLast.value)){
                        frm.topNumFirst.value = 0;
                        frm.topNumLast.value = 10;
                    }else if(isNaN(frm.sideNumFirst.value) && isNaN(frm.sideNumLast.value)){
                        frm.sideNumFirst.value = 0;
                        frm.sideNumLast.value = 10;
                    } else if (isNaN(frm.topNumFirst.value)) {
                        frm.topNumFirst.value = 0;
                    } else if (isNaN(frm.topNumLast.value)) {
                        frm.topNumLast.value = frm.topNumFirst.value + 1;
                    } else if (isNaN(frm.sideNumFirst.value)) {
                        frm.sideNumFirst.value = 0;
                    } else if (isNaN(frm.sideNumLast.value)) {
                        frm.sideNumLast.value = frm.sideNumFirst.value + 1;
                    } else {
	                //if input is greater than 99, has issues when the input is greater than 99
	                //subtracts 99 until its less than the number is less than 99
                        if (frm.topNumFirst.value > 99) {
                            while (frm.topNumFirst.value > 99) {
                                frm.topNumFirst.value = frm.topNumFirst.value - 99;
                            }
                        } else if (frm.topNumLast.value > 99) {
                            while (frm.topNumLast.value > 99) {
                                frm.topNumLast.value = frm.topNumLast.value - 99;
                            }
                        } else if (frm.sideNumFirst.value > 99) {
                            while (frm.sideNumFirst.value > 99) {
                                frm.sideNumFirst.value = frm.sideNumFirst.value - 99;
                            }
                        } else if (frm.sideNumLast.value > 99) {
                            while (frm.sideNumLast.value > 99) {
                                frm.sideNumLast.value = frm.sideNumLast.value - 99;
                            }
                        } else {
	                    //if first number is greater than the last
                            //subtracts last number until first number is less than the last number 
                            var checker = frm.topNumLast.value - frm.topNumFirst.value;
                            if (checker < 0) {
                                while (frm.topNumFirst.value > frm.topNumLast.value) {
                                    frm.topNumFirst.value = frm.topNumFirst.value - frm.topNumLast.value;
                                }
                            }
                            checker = frm.sideNumLast.value - frm.sideNumFirst.value;
                            if (checker < 0) {
                                while (frm.sideNumFirst.value > frm.sideNumLast.value) {
                                    frm.sideNumFirst.value = frm.sideNumFirst.value - frm.sideNumLast.value;
                                }
                            }      
                        }
                    }
                }
            }

            //printTbl function builds table from URL input 
            function printTbl() {
                var topLine = new Array();
                var sideLine = new Array();

                //following functions creates a dealt 10X10 table on the first load of the page  
                //otherwise it takes the info fomr user input
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

                //sets up the arrays based on user input 
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

	        //creates a 2D array based on user input
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
  <body id="A5Bdy" 
	onload="init();
		printTbl();
                document.getElementById('topNumFirst').focus();">
    <h1><strong>A5: </strong>Dynamic Multiplication Table</h1>
    <p><a href="http://www.cs.uml.edu/~cburbine/A3_index_Assign.html">Return to assignments page</a></p>
    <p id="instr">Please enter four numbers between 0 and 99, where the first multiplier is smaller than the last and the first multiplicand is smaller than the last.</p>
    <form id="frm" method="GET" onsubmit="return checkParas();">
      <label>First Multiplier:</label> <input type="text" name="topNumFirst" id="topNumFirst" tabindex="1" value="0"> <br>
      <label>Last  Multiplier:</label> <input type="text" name="topNumLast" id="topNumLast" tabindex="2" value="10"><br>
      <label>First Multiplicand:</label> <input type="text" name="sideNumFirst" id="sideNumFirst" tabindex="3" value="0"><br>
      <label>Last  Multiplicand:</label> <input type="text" name="sideNumLast" id="sideNumLast" tabindex="4" value="10"><br>
      <input id="buildit" type="submit" value="Build!" tabindex="5">
    </form>
    <div id="mydiv"></div>
    <p><a href="http://www.cs.uml.edu/~cburbine/A3_index_Assign.html">Return to assignments page</a></p>
  </body>
</html>
