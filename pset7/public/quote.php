<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("quote_form.php", ["title" => "Quote"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a symbol.");
        }
        
        // get symbol information
        $stock = lookup($_POST["symbol"]);
        
        // check if the symbol is not exist
        if($stock == false)
        {
            apologize("You are looking up for unknown symbol.");
        }
        else
        {
            // render the symbol information
            render("quote.php", ["name" => $stock["name"], "symbol" => $stock["symbol"], "price" => $stock["price"]]);
        }
    }

?>
