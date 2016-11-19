<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // restore history of this user
        $history = CS50::query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"]);
        
        // check if there is no history
        if(count($history) == 0) {
            apologize("There is no history for you!");
        }
        
        // render form
        render("history.php", ["history" => $history, "title" => "Portfolio"]);
    }

    // else if user reached page via POST or anything else
    else
    {
        apologize("You can't access this page.");
    }

?>
