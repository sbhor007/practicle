<?php
session_start();
if(!isset($_SESSION['count']))
{
    $_SESSION['count'] = 0;
}
$_SESSION['count']++;
$count  = $_SESSION['count'];
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <!-- 
        Write a PHP script to keep track of number of times the web page has been accessed.
     -->
    <title>Document</title>
</head>
<body>
    <h2>This Web Page Access <?php echo "$count"; ?> time</h2>
</body>
</html>










