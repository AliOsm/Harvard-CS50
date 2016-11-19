<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("buy_form.php", ["title" => "Buy"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a symbol.");
        }
        else if(empty($_POST["shares"]))
        {
            apologize("You must provide a number of shares.");
        }
        else if($_POST["shares"] < 1)
        {
            apologize("You must provide a positive number of shares.");
        }

        // take the integer part of shares number
        $_POST["shares"] = intval($_POST["shares"]);
        
        // uppercase the symbol
        $_POST["symbol"] = strtoupper($_POST["symbol"]);
        
        // get symbol information
        $stock = lookup($_POST["symbol"]);
        
        // apologize if the symbol is not invalid
        if($stock == false)
        {
            apologize("Invalid symbol.");
        }
        
        // get user informations
        $user = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        
        // calculate shares price
        $new_cash = $stock["price"] * $_POST["shares"];
        
        // check if user can't buy this shares
        if($user[0]["cash"] < $new_cash)
        {
            apologize("You don't have enought cash to buy this shares.");
        }

        // query database for symbol
        CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], $_POST["symbol"], $_POST["shares"]);
        
        // update user cash
        CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $new_cash, $_SESSION["id"]);
        
        // add this transaction to history
        CS50::query("INSERT INTO history (user_id, transaction, timestamp, symbol, shares, price) VALUES(?, ?, ?, ?, ?, ?)", $_SESSION["id"], true, date("Y-m-d H:i:s"), $_POST["symbol"], $_POST["shares"], $stock["price"]);

        redirect("/");
    }

?>
