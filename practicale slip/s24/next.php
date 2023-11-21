<?php
session_start();

if(!isset($_SESSION['login_atempt']))
{
    $_SESSION['login_atempt'] = 3;
}

$username = 'santosh';
$password = 123456;
if($username === $_POST['username'] && $password === $_POST['pass'])
{
    echo "<h2>Login Successful</h2>";
    exit;
}
else
{
    if($_SESSION['login_atempt']>0)
    {
        echo "<h2>Lohin Unsuccessful";
        echo "<h2>",$_SESSION['login_atempt']-- ."login Atempt Are remaining </h2>";
        echo "<a href = 's24.php'>Back To Login</a>";
    }
    else
    {
        echo "<h2>You do not login again Login ";
    }
}
?>