<!DOCTYPE html>
<html lang="en">
<head>
    <!-- 
        Write a PHP script for the following: Design a form to accept two numbers from the 
user. Give options to choose the arithmetic operation (use radio buttons). Display the 
result on the next form. (Use the concept of function and default parameters. Use 
‘include’ construct or require stmt)
     -->
    <title>Document</title>
</head>
<body>
<form action="s3.php" method = "post">
    No 1 : <input type="number" name = "n1"><br><br>
    No 2 : <input type="number" name = "n2"><br><br>
    <input type="radio" name="op" value='+'>Addition <br>
    <input type="radio" name="op" value="-">Subdtractio <br>
    <input type="radio" name="op" value="*">MUltiplication <br>
    <input type="radio" name="op" value="/">Division <br>
    <input type="submit" name = "sub">
</form>
</body>
</html>
<?php

if(isset($_POST['sub']))
{
   
    $no1 = $_POST['n1'];
    $no2 = $_POST['n2'];
    if(!empty($no1) && !empty($no2)){
        switch($_POST['op'])
        {
            case '+':
                echo "Addition :$no1 + $no2 =  ",$no1+$no2;
                break;
                case '-':
                    echo "substraction :$no1 - $no2 =  ",$no1-$no2;
                    break;
                    case '*':
                        echo "Multiplication :$no1 * $no2 =  ",$no1*$no2;
                        break;
                        case '/':
                            echo "Division :$no1 / $no2 =  ",$no1/$no2;
                            break;
        }
    }
    else
    {
        echo "all field are reuired....!";
    }

}

?>