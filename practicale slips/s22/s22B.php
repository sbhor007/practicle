<?php
session_start();

$_SESSION['sugarP'] = 48; 
$_SESSION['riceP'] = 50; 

if(isset($_POST['tshart']) && isset($_POST['tshartq']))
{
	$_SESSION['tshart'] = $_POST['tshart'];
	$_SESSION['tshartq'] = $_POST['tshartq'];
}
else


if(isset($_POST['mobile']) && isset($_POST['mobileq']))
{
	$_SESSION['mobile'] = $_POST['mobile'];	
	$_SESSION['mobileq'] = $_POST['mobileq'];
}

?>

<html>
<body>
	<form action = "s22C.php" method = "post">
		<b>Price : <?php echo $_SESSION['sugarP']; ?> Rs/kg <br>
		Sugar : <input type ="checkbox" name = "sugar" value = "Sugar"> 
Quantitty : <input type = "number" name = "sugarq" value = 0><br><br>
		<b>Price : <?php echo $_SESSION['riceP']; ?> Rs/kg <br>
		Rise : <input type ="checkbox" name = "rice" value = "Rice"> 
Quantitty : <input type = "number" name = "riceq" value = 0><br><br>
	<input type = "submit" name = "sub"></b>
	</form>
</body>
</html>
