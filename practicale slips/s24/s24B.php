<?php
session_start();
if(!isset($_SESSION['attemt']))
{
	$_SESSION['attemt'] = 3;
}

$user =  $_POST['user'];
$pass =  $_POST['pass'];

$username = 'santosh';
$password = '12345';

if($username === $user && $password === $pass)
{
	echo "<h1>Login Successful</h1>";
	exit;
}
else if($_SESSION['attemt'] > 0)
{
	echo "<h1>Login Faile</h1>";
	echo "<h1>",$_SESSION['attemt']--;" Attempts Are Remaining </h1>";
	echo "<h4><a href = 's24A.php'>Back To Login</h4>";
}
else
{
	echo "<h1>You don't Login Again</h1>";
}

?>