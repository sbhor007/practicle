<!DOCTYPE html>
<html lang="en">
<head>
    <!-- 
        Write a PHP script for the following: Design a form to accept the details of 5 different 
items, such as item code, item name, units sold, rate. Display the bill in the tabular 
format. Use only 4 text boxes. (Hint : Use of explode function.)
     -->
    <title>Document</title>
    <style>
        input{
            border : none;
            outline : none;
            background-color : transparent;
            border-bottom : 2px solid;
            border-radius : 15px;
            padding : 5px 15px;
        }
        #btn{
            background-color: green;
            padding : 5px 15px;
        }
    </style>
</head>
<body style = "background-color : powderblue;">
   <form action="s5.php" method = "post">
    <h2>Enter the Details of 5 items</h2>
    <table>
        <tr>
            <th>Item Code</th>
            <th>Item Name</th>
            <th>Unit Sold</th>
            <th>Rate</th>
            
        </tr>
        <?php
        for($i = 1;$i<=5;$i++)
        {
            echo "<tr>";
            echo "<td><input type = 'text' name = 'item[]' placeholder = 'Item code'></td>";
            echo "<td><input type = 'text' name = 'item[]' placeholder = 'Item Name'></td>";
            echo "<td><input type = 'number' name = 'item[]' placeholder = 'Unit Sold'></td>";
            echo "<td><input type = 'number' name = 'item[]' placeholder = 'Rate'></td>";
            echo "</tr>";
        }
        ?>
    </table><br>
    <input type="submit" id="btn" name = "sub" value = "generate Bill">
   </form> 
</body>
</html>
<?php
if(isset($_POST['sub']))
{
    $items = $_POST['item'];
    $count = count($items);
    if($count % 4 === 0)
    {
        echo "<h2>Bill Details</h2>";
        echo "<table border = '1'>";
        echo "
        <tr>
        <th>Item Code</th> 
        <th>Item Name</th>
        <th>Unit Sold</th>
        <th>Rate</th>
        </th>Total</th>
        </tr>
        ";

        for($i =0 ;$i<$count;$i+=4)
        {
            $iCode = $items[$i];
            $iname = $items[$i+1];
            $unitSold = $items[$i+2];
            $rate = $items[$i+3];
            $total =$unitSold * $rate;

            echo "
            <tr>
                <td>$iCode</td>
                <td>$iname</td>
                <td>$unitSold</td>
                <td>$rate</td>
                <td>$total</td>

            </tr>
            ";
        }
        echo "</table>";
    }
    else{
        echo "please fill in details for all 5 items.";
    }
}
?>