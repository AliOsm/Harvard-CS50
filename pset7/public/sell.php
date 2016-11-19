<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // get user stocks
        $symbols = CS50::query("SELECT symbol FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
        
        // check if the user don't have any stocks
        if(count($symbols) == 0)
        {
            apologize("Nothing to sell.");
        }
        
        // render form
        render("sell_form.php", ["symbols" => $symbols, "title" => "Sell"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must choose a symbol.");
        }

        // query database for symbol
        $symbol = CS50::query("SELECT * FROM portfolios WHERE symbol = ? AND user_id = ?", $_POST["symbol"], $_SESSION["id"]);

        // if we found user, check password
        if (count($symbol) == 1)
        {
            // get symbol information
            $stock = lookup($_POST["symbol"]);
            
            // calculate new price
            $new_cash = $symbol[0]["shares"] * $stock["price"];

            // delete shares
            CS50::query("DELETE FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
            
            // update user cash
            CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $new_cash, $_SESSION["id"]);
            
            // add this transaction to history
            CS50::query("INSERT INTO history (user_id, transaction, timestamp, symbol, shares, price) VALUES(?, ?, ?, ?, ?, ?)", $_SESSION["id"], false, date("Y-m-d H:i:s"), $_POST["symbol"], $symbol[0]["shares"], $stock["price"]);
            
            redirect("/");
        }
        else
        {
            // else apologize
            apologize("Invalid symbol.");
        }
    }

?>
