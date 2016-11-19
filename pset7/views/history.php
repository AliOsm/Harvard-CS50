<table class="table table-striped">
    <tr>
        <th>Transaction</th>
        <th>Date/Time</th>
        <th>Symbol</th>
        <th>Shares</th>
        <th>Price</th>
        <th>TOTAL</th>
    </tr>
    
    <?php $total = 0 ?>
    <?php foreach ($history as $h): ?>

        <tr>
            <?php if($h["transaction"] == true): ?>
                <td>Buy</td>
            <?php else: ?>
                <td>Sell</td>
            <?php endif; ?>
            <td><?= $h["timestamp"] ?></td>
            <td><?= $h["symbol"] ?></td>
            <td><?= $h["shares"] ?></td>
            <td><?= number_format($h["price"], 2, '.', ',') ?></td>
            <td>$<?= number_format($h["shares"] * $h["price"], 2, '.', ',') ?></td>
        </tr>
        
        <?php
            if($h["transaction"] == true) {
                $total += $h["shares"] * $h["price"];
            } else {
                $total -= $h["shares"] * $h["price"];
            }
        ?>
        
    <?php endforeach ?>
    
    <tr>
        <td>TOTAL</td>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
        <td>$<?= number_format($total, 2, '.', ',') ?></td>
    </tr>
</table>
