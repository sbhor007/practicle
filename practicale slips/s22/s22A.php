<?php
session_start();
$_SESSION['tsharP'] = 250;
$_SESSION['mobileP'] = 11250;

?>

<html>
<!--
Write a PHP program to create a shopping mall UI.
User must be allowed to do purchase from two pages. Each page should have a page total. 
The third page should display a bill, which consists of a page total of whatever the purchase has been done and print the total. (Use http session tracking).
-->
<body>
<h1>Select Items </h1>
	<form action = "s22B.php" method = "post">
		<b>Price : <?php echo $_SESSION['tsharP']; ?> Rs / T-shart<br>
		T-Shart<input type = "checkbox" name = "tshart" value = "tshart">
		Quantity : <input type = "number" name = "tshartq" value = 0><br><br>
		<b>Price : <?php echo $_SESSION['mobileP']; ?>  Rs / Mobile<br>
		Mobile<input type = "checkbox" name = "mobile" value = "mobile">
		Quantity : <input type = "number" name = "mobileq" value = 0><br><br>
		<input type = "submit" name = "next" value = "Next"> </b>
	</form>
</body>
</html>