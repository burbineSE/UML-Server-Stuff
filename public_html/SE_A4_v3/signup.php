<div class="row">
    <div class="signupHolder jumbotron"
        <div class="container wrapper">
            <!-- Static navbar -->
            <nav class="navbar navbar-default navbar-fixed-top">
                <div class="container-fluid">
                    <div class="navbar-header">
                        <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
                            <span class="sr-only">Toggle navigation</span>
                            <span class="icon-bar"></span>
                            <span class="icon-bar"></span>
                            <span class="icon-bar"></span>
                        </button>
                        <a class="navbar-brand" href="#">Cloud Prototype</a>
                    </div>
                    <div id="navbar" class="navbar-collapse collapse">
                        <ul class="nav navbar-nav">
                            <li class="active"><a href="#signup">Sign In</a></li>
                            <li><a href="#about">About</a></li>
                        </ul>
                    </div><!--/.nav-collapse -->
                </div><!--/.container-fluid -->
            </nav>
            <div class="content">
                <div id="leftForm" class="col-md-6">
                    <div class="formHead">
                        <h1>Sign In</h1>
                    </div>
                    <form id="formSignin" class="form-signin">
                        <div class="inputField"><input id="email" required class="form-control" placeholder="Email address" required autofocus type="email" placeholder="Email"></div>
        				<div class="inputField"><input id="password" required class="form-control" type="password" placeholder="Password"></div>
                        <div class="inputField buttonHolder"><button id="signinBtn" class="btn btn-success" type="submit">Submit</button></div>
                    </form>
                </div><!--Comment to remove the blank space between the divs. This allows for the use of 100% width instead of 99% -->
                <div id="rightForm" class="col-md-6">
                    <div class="formHead">
                        <h1>Sign Up</h3>
                    </div>
                    <form id="formSignup" class="form-signin">
                        <div class="inputField"><input required class="form-control" type="text" placeholder="First Name"></div>
                        <div class="inputField"><input required class="form-control" type="text" placeholder="Last Name"></div>
                        <div class="inputField"><input required class="form-control" type="email" placeholder="Email"></div>
                        <div class="inputField"><input required class="form-control" type="password" placeholder="Password"></div>
                        <div class="inputField"><input required class="form-control" type="password" placeholder="Confirm Password"></div>
                        <div class="inputField buttonHolder"><button id="signupBtn" class="btn btn-success" type="submit">Submit</button></div>
                    </form>
                </div>
            </div>
        </div>
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.4/css/bootstrap.min.css">
        <script src="scripts/signup.js"></script>
    </div>
</div>