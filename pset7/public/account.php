<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // get user information
        $user = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
        
        // render form
        render("account_form.php", ["user" => $user[0], "title" => "Setting"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // get user information
        $user = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
        $user = $user[0];
        
        // compare hash of user's input against hash that's in database
        if (!password_verify($_POST["opassword"], $user["hash"]))
        {
            apologize("Wrong old password.");
        }
        
        // validate submission
        if (!empty($_POST["username"]) && $_POST["username"] !== $user["username"])
        {
            CS50::query("UPDATE users SET username = ? WHERE id = ?", $_POST["username"], $_SESSION["id"]);
        }
        if (!empty($_POST["password"]) && !empty($_POST["confirmation"]) &&
                 $_POST["password"] == $_POST["confirmation"])
        {
            CS50::query("UPDATE users SET hash = ? WHERE id = ?", password_hash($_POST["password"], PASSWORD_DEFAULT), $_SESSION["id"]);
        }

        redirect("/");
    }

?>
