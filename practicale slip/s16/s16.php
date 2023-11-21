<!DOCTYPE html>
<html lang="en">
<head>
    <!-- 
        Write a PHP program that accept customer name, consumer number and number of 
electricity units consumed from an input form and print electricity bill from following 
data For first 50 units – Rs. 3.50/unit 
 For next 100 units – Rs. 4.00/unit 
  For next 100 units – Rs. 5.20/unit 
   For units above 250 – Rs. 6.50/unit 
    Fixed meter and service charge- R
     -->
    <title>Document</title>
</head>
<body>
   <form action="s16.php" method="post">
    Customer Name : <input type="text" name = "cname"><br><br>
    Customer number : <input type="text" name = "cnum"><br><br>
    Electricity Units : <input type="number" name="unit"><br><br>
    <input type="submit" value="Generate Bill" name = "sub">
   </form> 
</body>
</html>
<?php

    if(isset($_POST['sub']))
    {
        if(!empty($_POST['cname']) && !empty($_POST['cnum']) && !empty($_POST['unit']))
        {
            $cname = $_POST['cname'];
        $cno = $_POST['cnum'];
        $unit = $_POST['unit'];
        $total = 0;
            if($unit > 250)
            {
                $total = 150+(6.50*$unit);
            }
            else if($unit > 100)
            {
                $total = 150+(5.20*$unit);
            }
            else if($unit > 50)
            {
                $total = 150+(4*$unit);
            }
            else if($unit>0)
            {
                $total = 150+(3.50*$unit);
            }
            else
            {
                echo "Negative unit are not allow....!";
            }
            echo "
            <h3>Bill</h3>
            Customer No : $cno <br>
            Customer Name : $cname <br>
            Electricity Unit : $unit <br>
            <b>Total Amount : $total</b>
            ";
        }
        else
        {
            echo "all fields are require";
        }
    }

?>