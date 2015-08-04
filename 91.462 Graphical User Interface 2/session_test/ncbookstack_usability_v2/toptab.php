<!-- jQuery UI modifications take from http://knowledgebase.bridge-delivery.com/jquery-ui-menu-horizontal-and-vertical/ by Hari KT-->
   <link rel="stylesheet" href="http://code.jquery.com/ui/1.10.2/themes/smoothness/jquery-ui.css">
    <style>
      .ui-menu { 
        overflow: hidden;
        /*background:blue;*/
        /*float:right;*/
      	font-size:115%;
	border:1px solid #ff8300;
    	border-radius:15px;
	box-shadow: 5px 5px 2.5px #888888;
      }
      #imglink{
        float:left;
	
      }
      /*img{
        float:left:
      }*/
      .ui-menu .ui-menu {
        overflow: visible !important;
        /*background:blue;*/
	
      }
      .ui-menu > li { 
        float: right;
        display: block;
        width: auto !important;
	color:blue;
      }
      .ui-menu ul li {
        display:block;
        float:none;
      }
      .ui-menu ul li ul {
        left:120px !important;
        width:100%;
      }
      .ui-menu ul li ul li {
        width:auto;
      }
      .ui-menu ul li ul li a {
        float:left;
      }
      .ui-menu > li {
        margin: 5px 5px !important;
        padding: 0 0 !important;
      }
      .ui-menu > li > a { 
        float: left;
        display: block;
        clear: both;
        overflow: hidden;
      }
      .ui-menu .ui-menu-icon { 
        margin-top: 0.3em !important;
      }
      .ui-menu .ui-menu .ui-menu li { 
        float: left;
        display: block;
      }
      label{
        display: inline-block;
        float: left;
        clear: left;
        width: 100px;
        text-align: right;
      }
      button{
        float:center;
        margin-top:10px;
      }
     
      #herelink:hover{
        color:blue;
      }
      .bwrap {
        text-align: center;
      }
      
      .button {
        position: absolute;
        top: 50%;
      }
    </style> 
    <script src="http://code.jquery.com/jquery-1.9.1.js"></script>
    <script src="http://code.jquery.com/ui/1.10.2/jquery-ui.js"></script>
    <ul id="nav">
    <?php
      if(!$onmain == 1){
      echo '<li id="imglink"><a href="home.php"><img border="0" alt="NChome" id="logo" src="logosmall.png" width="100" height="35"></a></li>';
       }
       if($_SESSION['id']){
           echo '<li><a href="logout.php">Logout ';
	   echo $_SESSION['username'];
	   echo '</a></li>';
         }  
	 
	 #if($notsearch == 1){
      	 #echo '<li><a href="search_v2.php">Search</a></li>';
	 #}
      
         if($onhome == 1){
	    echo '<li><a href="pw_change_form.php">Change Password</a></li>';
	 }
	 if($notsearch == 1){
         echo '<li><a href="search_v2.php">Search</a></li>';
         }
	 if($_SESSION['id'] && !$onhome == 1){
	   echo '<li><a href="mypage.php">My Profile</a></li>';
	 } else if(!$_SESSION['id'] && !$onlogin == 1){
	   echo '<li><a href="login.php">Login</a>';
	   #echo '<ul><li>
	    #         <label>Username:</label><input type="text">
	     #        <label>Password:</label><input type="text">
	#	     <div class="bwrap"><input class="button" type="submit" value="Login"></div>
	#	     <p id="redp" style="text-align:center;">Not a member? Sign up <a id="herelink" href="#">here</a>.</p></li>
         #            </ul></li>';
	 }
	
	 ?>
    </ul>
    <script>
      $( "#nav" ).menu({position: {at: "left bottom"}});
    </script>
