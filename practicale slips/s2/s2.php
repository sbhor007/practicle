<!DOCTYPE html>
<html lang="en">
<head>
    <!-- 

    Write a PHP script for the following:
        1 -- Design a form to accept two strings from the user. 
        2 -- Find the first occurrence and the last occurrence of the small string in the largetring.
             Also count the total number of occurrences of small string in the large string.
        3 -- Provide a text box to accept a string, which will replace the small string in the large 
            string. (Use built-in functions)
     -->
    <title>Document</title>
</head>
<body>
    <form action="s2.php" method="post">
        Large String : <input type="text" name="large"><br><br>
        Small String : <input type = "text" name = "small"><br><br>
        replace : <input type="text" name="replace" id=""><br><br>
        <input type="radio" name="ch" value="fo" id="">first occurrence
        <input type="radio" name="ch" value="lo" id="">Lasr occurrence
        <input type="radio" name="ch" value="r" id="">Replace string <br><br>
        <input type="submit" name = "submit">
    </form>
</body>
</html>

<?php
if(isset($_POST['submit']))
{
    $largeStr = $_POST['large'];
    $smallStr = $_POST['small'];
    $replace = $_POST['replace'];

    switch($_POST['ch'])
    {
        case 'fo':
            $firsPos = strpos($largeStr,$smallStr);
            if($firsPos !== 0)
            {
                echo "$smallStr not present at first position at the sting $largeStr";
            }
            else 
            {
                echo "$smallStr present at first position at the sting $largeStr";
            }
            break;
            case 'lo':
                $lastPos = strpos($smallStr,$largeStr);
                if($lastPos != 0)
                {
                    echo "$smallStr not present at LAST position at the sting $largeStr";
                }
                else 
                {
                    echo "$smallStr present at LAST position at the sting $largeStr";
                }
                break;
                case 'r':
                    $newStr = str_replace($smallStr,$replace,$largeStr);
                    echo "Replaced string is : <h1>$newStr</h1>";
                    // $new_str = str_replace($smallStr,$replace,$largeStr);
                    // echo "after replaced string : ",$new_str;
                    break;
                break;
    }
}
?>