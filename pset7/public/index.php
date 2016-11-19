<?php

    // configuration
    require("../includes/config.php");
    
    // get user portfolios
    $rows = CS50::query("SELECT * FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
    
    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
            ];
        }
    }
    
    // get user cash
    $rows = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);

    // render portfolio
    render("portfolio.php", ["positions" => $positions, "cash" => $rows[0]["cash"], "title" => "Portfolio"]);

?>
