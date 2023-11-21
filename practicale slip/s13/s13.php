<!DOCTYPE html>
<html lang="en">
<head>
    <!-- 
        Implement calculator to convert distances between (both ways) miles and kilometres. 
One mile is about 1.609 kilometres. User interface (distance.html) has one text-input, 
two radio-buttons, submit and reset -buttons. Values are posted to PHP-script 
(distance.php) which calculates the conversions according the user input.
     -->
    <title>Document</title>
</head>
<body>
    <form action="s13.php" method="post">
        distance : <input type="number" name="dis">
        <select name="op">
            <option value="km">KM</option>
            <option value="mile">MILE</option>
        </select>
        <br>
        <input type="radio" name="ch" value = 'k'>Kilomitor To Miles <br>
        <input type="radio" name="ch" value = 'm'>Miles To Kilomiter <br>
        <input type="submit" value="Calculate" name = "sub">
    </form>
</body>
</html>

<?php
if(isset($_POST['sub']))
{
    $op = $_POST['op'];
    $ch = $_POST['ch'];
    $dis = $_POST['dis'];
    if($op == "km" && $ch == "k")
    {
        $m = $dis/1.609;
        echo "$dis KM = $m Miles";
    }
    else if($op == "mile" && $ch == "m")
    {
        $m = $dis*1.609;
        echo "$dis Miles = $m KM";
    }
    else
    {
        echo "please choose correct option";
    }
}
?>