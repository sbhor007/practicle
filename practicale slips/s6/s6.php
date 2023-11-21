<!DOCTYPE html>
<html lang="en">
<head>
    <!--
         Write a PHP script for the following: 
            Design a form to accept two strings.
            -- Compare the two strings using both methods (= = operator &strcmp function). 
            -- Append second string to the first string.
            -- Accept the position from the user;
                from where the characters from the first string are reversed. (Use radio buttons)
 -->
    <title>Document</title>
</head>
<body>
    <form action="s6.php" method = "post">
        str 1 : <input type="text" name="s1"><br><br>
        str 2 : <input type="text" name="s2"><br><br>
        Possition : <input type="text" name="pos"><br><br>
        <input type="radio" name="ch" value = "c" id="">Compare 1st and 2nd string <br>
        <input type="radio" name="ch" value = "a" id="">Append Second String To First String <br>
        <input type="radio" name="ch" value = "r" id="">Reversed 1st string  with character position<br>
       <input type="submit" name = "sub"> 
    </form>
</body>
</html>
<?php
    if(isset($_POST['sub']))
    {
        $str1 = $_POST['s1'];
        $str2 = $_POST['s2'];
        $pos = $_POST['pos'];
        switch($_POST['ch'])
        {
            case 'c':
                if(strcmp($str1,$str2)==0)
                    echo "Both the string are equal";
                else
                    echo "String 1 And String 2 are not equal";
            break;
            case 'a':
                echo $str1 ,$str2;
                break;
            case 'r':
                $len = strlen($str1) - $pos;
                $newstr = substr($str1,$pos,$len);
                echo "Reversed string is : ",strrev($newstr);
                break;
        }
    }
?>