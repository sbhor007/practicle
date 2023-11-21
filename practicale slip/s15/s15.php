<!DOCTYPE html>
<html lang="en">
<head>
    <!-- 
        Write PHP program to create input form for Grocery that displays List of grocery 
items with checkboxes and create a bill according to list of items selected after 
clicking submit button
     -->
        <title>Document</title>
</head>
<body>
    <form action="s15.php" method="post">
        <h2>Please select your grosery</h2>
        <input type="checkbox" name="check[]" Value = "rice">Rice(50 Rs./kg) <br>
        <input type="checkbox" name="check[]" Value = "oils">oils(100 Rs./l) <br>
        <input type="checkbox" name="check[]" Value = "milk">milk(35 Rs/l) <br>
        <input type="checkbox" name="check[]" Value = "bread">bread(30 Rs.)<br>
        <input type="submit" name = "sub">
    </form>
</body>
</html>
<?php
if(isset($_POST['sub']))
{
    if(isset($_POST['check']))
    {
        $items = $_POST['check'];
        $total = 0;
        echo "Selected Items : <br>";
        echo "<h4><ul>";
        foreach($items as $val)
        {
            echo "<li> $val </li>";
            switch($val)
            {
                case 'rice':
                    $total += 50;
                    break;
                    case 'oils':
                        $total +=100;
                        break;
                        case 'milk';
                        $total += 35;
                        break;
                        case 'bread';
                        $total += 30;
                        break;
            }
        }
        echo "</h4><h2>Total bill : $total</h2>";
    }
    else
    {
        echo "Items Are Not Silected";
    }
   
}
?>