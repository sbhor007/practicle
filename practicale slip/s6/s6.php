<!DOCTYPE html>
<html lang="en">
<head>
    <!-- 
        Write a PHP script for the following: Design a form to accept two strings. Compare 
the two strings using both methods (= = operator &strcmp function). Append second 
string to the first string. Accept the position from the user; from where the characters 
from the first string are reversed. (Use radio buttons)
     -->
    <title>Document</title>
</head>
<body>
    <form action="s6.php" method = "post">
        string 1 : <input type="text" name = "str1" require><br><br>
        string 2 : <input type="text" name = "str2" require><br><br>
        position to reverse string : <br>
        <input type="number" name="pos" id=""><br>
        <input type="radio" name = "ch" value = "c">Compare string <br>
        <input type="radio" name = "ch" value = "d">Compare string wih data type<br>
        <input type="radio" name = "ch" value = "a">Append String <br>
        <input type="radio" name = "ch" value = "p">Position for reverse <br>
        <input type="submit" name="sub">

    </form>
</body>
</html>
<?php
if(isset($_POST['sub']))
{
    $str1 = $_POST['str1'];
    $str2 = $_POST['str2'];
    $pos = $_POST['pos'];
    switch($_POST['ch'])
    {
        case 'c':
            if($str1 == $str2)
            {
                echo "Both string are equal";
            }
            else
            {
                echo "Both string are not equal";
            }
            break;
            case 'd':
                if($str1 === $str2 )
                {
                    echo "both are exactly same";
                }
                else
                {
                    echo "both are not exactly same";
                }
                break;
                case 'a':
                    echo "appended string is : ",$str1.$str2;
                    break;
                    case 'p':
                        $len = strlen($str1)-$pos;
                        $newstr =  substr($str1,$pos,$len);
                        $rev = strrev($newstr);
                        echo "reverse string : $rev";
                        break;
    }

}
?>