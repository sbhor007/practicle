<html>
<body>
	<form action = "s13.php" method = "post">
		distance : <input type = "number" name = "dist">
		
		convert to <input type = "radio" name = "ch" value = "km">kilometres
		<input type = "radio" name = "ch" value = "ml">Miles
		<br><br>
		<input type = "submit" name ="sub">
		<input type = "reset" name ="res">
	</form>
</body>
</html>

<?php
if(isset($_POST['sub']))
{
	$dis = $_POST['dist'];
	switch($_POST['ch'])
	{
		case 'km':
			echo "<br><h3>$dis Miles =  ",1.609*$dis,"kilometres<h3>";
			break;
		case 'ml':
			echo "<br><h3>$dis Kilometer =  ",$dis/1.609,"Miles<h3>";
			break;
	}
}

?>