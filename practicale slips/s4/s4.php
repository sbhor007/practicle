<!DOCTYPE html>
<html lang="en">
<head>
    <!-- 
        Write a PHP script for the following: 
            --Design a form to accept two strings from the user.
            --Find whether the small string appears at the start of the large string.
            --Provide a text box to accept the string that will replace all occurrences of small string present in 
              the large string. 
            --Also split the large string into separate words. (Use regular expressions
     -->
    <title>Document</title>
</head>
<body>
    <form action="s4.php" method="post">
        Large String : <input type="text" name="largeStr" id=""><br><br>
        Small String : <input type="text" name="samllStr" id=""><br><br>
        Replace String : <input type="text" name="replace" id=""><br><br>
        <input type="radio" name="ch" value = "f" id="">Find First Occurence
        <input type="radio" name="ch" value = "r" id="">Replace String
        <input type="radio" name="ch" value = "s" id="">Split Words 
        <br><br>
        <input type="submit"  name = "sub">
    </form>
</body>
</html>

<?php
if(isset($_POST['sub']))
{
    $largeStr = $_POST['largeStr'];
    $samllStr = $_POST['samllStr'];
    $replace = $_POST['replace'];

    switch($_POST['ch'])
    {
        case 'f':
            $firstOccur = strpos($largeStr,$samllStr);
            if($firstOccur != 0)
            {
                echo "$samllStr not present at the start of $largeStr.";
            }
            else
            {
                echo "$samllStr present at the start of $largeStr.";
            }
            break;
            case 'r':
                $new_str = str_replace($samllStr,$replace,$largeStr);
                echo "After replace string : <h4>$new_str</h4>";
                break;
                case 's':
                    $largeStr = str_split($largeStr);
                    foreach($largeStr as $val)
                    {
                        if($val != ' ')
                        echo $val;
                        else
                        echo "<br>";
                    }
                    break;
    }
}
?>