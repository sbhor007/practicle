

<!DOCTYPE html>
<html lang="en">
<head>
<!-- Write a PHP script for the following: 
    --Design a form to accept the details of 5 different items, 
    --such as item code, item name, units sold, rate.
    --Display the bill in the tabular format. 
    --Use only 4 text boxes. (Hint : Use of explode function.) -->
    <title>Document</title>
</head>
<body>
    <form action="s5.php" method="post">
        Item Code : <input type="text" name="icode" default = '0' id=""><br><br>
        Item Name : <input type="text" name="iname" id=""><br><br>
        Units : <input type='number' name="units" id=""><br><br>
        Rate : <input type='number' name="rate" id=""><br><br>
        <input type="submit" value="Genarate Bill" name = "sub">
    </form>
    
    <table border = 3 cellpadding = '10px'>
        <tr>
            <th>Item Code</th>
            <th>Item Name</th>
            <th>Units</th>
            <th>Rate</th>
            <th>Total</th>
        </tr>
        <tr>
            <td><?php echo $_POST['icode']; ?> </td>
            <td><?php echo $_POST['iname']; ?> </td>
            <td><?php echo $_POST['units']; ?> </td>
            <td><?php echo $_POST['rate']; ?> </td>
            <td><?php echo $_POST['rate']*$_POST['units']; ?> </td>
        </tr>
    </table>
    
</body>
</html>

