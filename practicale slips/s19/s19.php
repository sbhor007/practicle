<?php
session_start();
if(!isset($_SESSION['count']))
{
	$_SESSION['count'] = 0;
}
$count = $_SESSION['count']++;
?>

<html>
<!--
-->
<body>
<h1>This Page Visited at <?php echo $count; ?> Times</h1>
</body>
</hrml>