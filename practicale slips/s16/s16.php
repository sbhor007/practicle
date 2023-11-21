<html>
<!-- Write a PHP program that accept customer name, consumer number and number of 
electricity units consumed from an input form and print electricity bill from following 
data

 For first 50 units – Rs. 3.50/unit 
 For next 100 units – Rs. 4.00/unit 
 For next 100 units – Rs. 5.20/unit 
 For units above 250 – Rs. 6.50/unit 
 Fixed meter and service charge- Rs. 150/
-->
<body>
<form method = "post" action = "s16.php">
	Customer Name : <input type = "text" name = "cname"><br><br>
	Customer No : <input type = "text" name = "cno"><br><br>
	Electricity Unit : <input type = "text" name = "unit"><br><br>
<input type = "submit" name = "sub">
</form>
</body>
</html>

<?php

if(isset($_POST['sub']))
{
	$cname = $_POST['cname'];
	$cno = $_POST['cno'];
	$units = $_POST['unit'];

	echo "<h1> Electricity Bill</h1>";
	echo "<b>Customer Name : $cname <br>
			Customer No : $cno<br>
			Electricity Units : $units<br><b>";
	if($units > 0 && $units <= 50)
		echo "<b>Total : ",3.50*$units," Rs<b>";
	else if($units <= 100)
		echo "<b>Total : ",4*$units," Rs<b>";
	else if($units <= 250)
		echo "<b>Total : ",5.20*$units," Rs<b>";
	else if($units > 250) 
		echo "<b>Total : ",6.50*$units," Rs<b>";
}

?>