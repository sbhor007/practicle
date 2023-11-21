<!DOCTYPE html>
<html lang="en">
<head>
    <!-- 
        Write a PHP script for the following: Design a form to accept two strings from the 
user. Find the first occurrence and the last occurrence of the small string in the large 
string. Also count the total number of occurrences of small string in the large string. 
Provide a text box to accept a string, which will replace the small string in the large 
string. (Use built-in functions)
     -->
    <title>Document</title>
</head>
<body>
    <form action="s2.php" method="post">
        large String : <input type="text" name = "lstr"><br><br>
        small string : <input type ="text" name = "sstr"><br><br>
        replace string : <input type='text' name = 'replace'><br>        
        <input type="radio" name = "op" value = "f">first Occurrence<br>
        <input type="radio" name = "op" value = "l">last Occurrence<br>
        <input type="radio" name = "op" value = "r">replace<br>
      
        
        <input type="submit" name = "sub">
    </form>
</body>
</html>
<?php
if(isset($_POST['sub']))
{
    $lasrgeStr = $_POST['lstr'];
    $smallStr = $_POST['sstr'];
    $replace = $_POST['replace'];
    switch($_POST['op'])
    {
        case 'f':
            $firtOccurrence = strpos($lasrgeStr,$smallStr);
            if($firtOccurrence !== 0)
            {
                echo $smallStr," Not Present at the start of",$lasrgeStr;
            }
            else
            {
                echo $smallStr," Present at the start of",$lasrgeStr;
            }
            break;
            case 'l':
                $lastOccurence = strpos($smallStr,$lasrgeStr);
                if($lastOccurence != 0)
            {
                echo $smallStr," Not Present at the last of",$lasrgeStr;
            }
            else
            {
                echo $smallStr," Present at the last of",$lasrgeStr;
            }
                break;
                case 'r':
                    $new_str = str_replace($smallStr,$replace,$lasrgeStr);
                    echo "after replaced string : ",$new_str;
                    break;
    }
   
}
?>