<?php
session_start();
$bio = $_POST['bio'];

$chem = $_POST['chem'];

$maths = $_POST['maths'];
$marathi= $_POST['marathi'];
$english = $_POST['english'];
$total = $bio + $chem + $maths + $marathi + $english;

?>
<html>
<head>
<style>
th{
	padding : 10px 30px;
	text-align : center;
}
td{
	text-align : center;
}
</style>
</head>
<body>

	<h1>Result>
	<h3> Name : <?php echo $_SESSION['sname']; ?>
	<h3> Class : <?php echo $_SESSION['class']; ?>
	<h3> Address : <?php echo $_SESSION['addr']; ?><br><br>
	<table border>
		<tr>
			<th>Bio</th>
			<th>Chem</th>
			<th>Maths</th>
			<th>Marathi</th>
			<th>English</th>
			<th>Total</th>
			<th>Percentage</th>
		</tr>
		<tr>
			<td> <?php echo $_POST['bio']; ?> </td>
			<td> <?php echo $chem ; ?> </td>
			<td> <?php echo $maths; ?></td>
			<td> <?php echo $marathi; ?></td>
			<td> <?php echo $english; ?></td>
			<td> <?php echo $total; ?></td>
			<td> <?php echo $total/5; ?>%</td>
		</tr>
	</table>
<h3>

</body>
</html>