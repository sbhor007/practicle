<html>
<!-- Write PHP program to create input form for Grocery that displays List of grocery 
items with checkboxes and create a bill according to list of items selected after 
clicking submit button.
-->
<body>
	<h1>GroceryShop</h1>
	<form action = "s15.php" method = "post">
	<input type = "checkbox" name = "item[]" value = "Rice">Rice(55 Rs/kg)<br>

	<input type = "checkbox" name = "item[]" value = "Oile">Oile(110 Rs/li)<br>

	<input type = "checkbox" name = "item[]" value = "Milk">Milk(45 Rs/ li)<br>

	<input type = "checkbox" name = "item[]"value = "Bread">Bread(20 Rs/ Pack)<br><br>

	<input type = "submit" name = "sub" value = "Generate Bill">
	<input type = "reset" value = "Reset">
	</from>
</body>
</html>

<?php

if(isset($_POST['sub']))
{
echo "<h2>Bill</h2><h3><ul>";
	$total = 0;
	$items = $_POST['item'];
	foreach($items as $val)
	{
		switch($val)
		{
			case 'Rice':
				echo "<li>$val - 55 Rs/kg</li>";
				$total += 55;
			break;
			case 'Oile':
				echo "<li>$val - 110 Rs/Li</li>";
				$total += 110;
			break;
			case 'Milk':
				echo "<li>$val - 45 Rs/Li</li>";
				$total += 45;
			break;
			case 'Bread':
				echo "<li>$val - 20 Rs/ Pack</li>";
				$total += 20;
			break;

		}
	
	}
	echo "</ul><hr>";
	echo "Total - $total</h3>";
}

?>