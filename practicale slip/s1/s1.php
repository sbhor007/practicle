<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="s1.php" method = "post">
        Name : <input type="text" name ="str" placeholder = "Enter a String"><br>
        <input type="radio" name = "op" value = "v">Total Vowels <br>
        <input type="radio" name = "op" value = "o">Occurences <br>
        <input type="radio" name = "op" value = "p">Check String palindrome <br>
        <input type="submit" name="sub">
    </form>
</body>
</html>

<?php
/*
Write a PHP script for the following: Design a form to accept a string. Write a 
function to count the total number of vowels (a,e,i,o,u) from the string. Show the 
occurrences of each vowel from the string. Check whether the given string is a 
palindrome or not, without using built-in function. (Use radio buttons and the concept 
of function. Use ‘include’ construct or require stmt.)
 */
function countVowels($str)
{
    $str = strtolower($str);
    $str = str_split($str);
    $ctr = 0;
    
    foreach($str as $val)
    {
        if($val == 'a'||$val == 'e' || $val == 'i' || $val == 'o' ||$val == 'u')
        $ctr++;
    }
    return $ctr;
}
function totalVowelOccurences($str)
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
        $a++;
        else if($val == 'e')
        $e++;
        else if($val == 'i')
        $i++;
        else if($val == 'o')
        $o++;
        else if($val == 'u')
        $u++;
    }
    echo "a = $a <br>";
    echo "e = $e <br>";
    echo "i = $i <br>";
    echo "o = $o <br>";
    echo "u = $u <br>";
      
}
function checkPalindrome($str)
{
    $temp = strrev($str);
    if($temp == $str)
    {
        echo "<b>$str</b> is <u>Palindrome</u> string";
    }
    else
    {
        echo "<b>$str</b> is <u>NOT Palindrome</u> string";
    }
}

if(isset($_POST['sub']))
{
    $str = $_POST['str'];
    switch($_POST['op'])
    {
        case 'v':
            echo "no of vowels in a $str is : ", countVowels($str);
            break;
            case 'o':
                totalVowelOccurences($str);
                break;
                case 'p':
                    checkPalindrome($str);
                    break;
    }
}
 ?>