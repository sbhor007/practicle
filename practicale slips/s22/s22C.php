<?php
session_start();

if(isset($_POST['sugar']) && isset($_POST['sugarq']))
{
	 $sugar = $_POST['sugar'];
	 $sugarq = $_POST['sugarq'];
}

if(isset($_POST['rice']) && isset($_POST['riceq']))
{
	 $rice = $_POST['rice'];
	 $riceq = $_POST['riceq'];
}

$totalTshatPrice = $_SESSION['tshartq'] * $_SESSION['tsharP'] ;
$totalMobilePrice = $_SESSION['mobileq'] * $_SESSION['mobileP'] ;
$totalSugarPrice = $sugarq * $_SESSION['sugarP']; 
$totalRicePrice = $riceq * $_SESSION['riceP'];
echo "<br>", $_SESSION['tshartq'] ;
echo "<br>", $_SESSION['mobileq'] ;
echo "<br>", $totalSugarPrice ;
echo "<br>", $totalRicePrice ;

?>

<html>
<dody>

<h1>Bill</h1>
<h2> Total : <?php echo $totalTshatPrice + $totalMobilePrice + $totalSugarPrice + $totalRicePrice; ?></h2>

</body>
</html>