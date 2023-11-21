<!DOCTYPE html>
<html lang="en">
<head>
    <!-- 
        Write a PHP script for the following: Design a form to accept two strings from the 
user. Find whether the small string appears at the start of the large string. Provide a 
text box to accept the string that will replace all occurrences of small string present in 
the large string. Also split the large string into separate words. (Use regular 
expressions)
     -->
    <title>Document</title>
</head>
<body>
    <form action="s4.php" method = "post">
        large string : <input type="text" name = "lstr" placeholder = "Enter a large string"><br><br>
        small string : <input type="text" name = "sstr" placeholder = "Enter a small string"><br><br>
        replace : <input type="text" name = "replace" placeholder = "Enter a small string"><br>
        <input type="radio" name="op" value = "o">Occurence <br>
        <input type="radio" name="op" value = "r">Replace <br>
        <input type="radio" name="op" value = "s">Split <br>
        <input type="submit" name = "sub">
    </form>
</body>
</html>
<?php
if(isset($_POST['sub']))
{
    $largeStr = $_POST['lstr'];
    $smaleStr = $_POST['sstr'];
    $replace = $_POST['replace'];
    switch($_POST['op'])
    {
        case 'o':
            $firtOccurrence = strpos($largeStr,$smaleStr);
            if($firtOccurrence !== 0)
            {
                echo $smaleStr," Not Present at the start of ",$largeStr;
            }
            else
            {
                echo $smaleStr," Present at the start of ",$largeStr;
            }
            break;
        break;
        case 'r':
            $new_str = str_replace($smaleStr,$replace,$largeStr);
            echo "After Replaced String : ",$new_str;
            break;
            case 's':
                
                $str = str_split($largeStr);
                foreach($str as $val)
                {
                    if($val == " ")
                    echo "<br>";
                    else
                    echo $val;  
                }
    }
}
?>