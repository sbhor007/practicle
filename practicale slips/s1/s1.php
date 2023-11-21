<!DOCTYPE html>
<!--/*
Write a PHP script for the following: Design a form to accept a string.
1  - Write a function to count the total number of vowels (a,e,i,o,u) from the string. 
2  - Show the occurrences of each vowel from the string. 
3  - Check whether the given string is a palindrome or not, without using built-in function. 
(Use radio buttons and the concept of function. Use include construct or require stmt.)
*/-->
<html lang="en">
<head>
    <title>Document</title>
</head>
<body>
    <form action="s1.php" method="post">
        Sring : <input type="text" name="str" id="">
        <br><br>
        <input type="radio" name = "ch" value="v" id="">Check Total Vovels <br>
        <input type="radio" name = "ch" value="o" id="">occurrences of each vowel <br>
        <input type="radio" name = "ch" value="p" id="">Check whether the given string is a palindrome or not, without using <br><br>
        <input type="submit" value="submit" name = "sub">
    </form>
</body>
</html>
<?php
if(isset($_POST['sub']))
{
    $str = $_POST['str'];

    function checkVovel($str)
    {
        $ctr = 0;
        $str = strtolower($str);
        $str = str_split($str);
        foreach ($str as $val) {
            if($val == 'a' || $val == 'e' || $val == 'i' || $val == 'o' || $val == 'u')
            {
                $ctr++;
            }
        }
        return $ctr;
    }
    function eachVovelOccurence($str)
    {
        $str = strtolower($str);
        $str = str_split($str);
        $a = 0;
        $e = 0;
        $i = 0;
        $o = 0;
        $u = 0;
        foreach($str as $val)
        {
            if($val == 'a')
            {
                $a++;
            }else if($val == 'e')
            {
                $e++;
            }else if($val == 'i'){
                $i++;
            }else if($val == 'o'){
                $o++;
            }else if($val == 'u')
            {
                $u++;
            }
        }
        echo "a : $a<br>";
        echo "e : $e<br>";
        echo "i : $i<br>";
        echo "o : $o<br>";
        echo "u : $u<br>";
    }


    switch($_POST['ch'])
    {
        case 'v':
            echo "Total vovels in a $str is :  ",checkVovel($str);
            break;
            case 'o';
            echo "Each occurance of vovels in a $str is : <br>",eachVovelOccurence($str);
            break;
            case 'p';
            $temp = $str;
            if($str === strrev($temp))
            {
                echo "<br>$str is palindrom string";
            }
            else
            {
                echo "<br>$str is not palindrom string";
            }
    }
}
?>