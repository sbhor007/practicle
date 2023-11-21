<html>
<body>
	<h3>Array : ['a' =>5,'b' => 4,'c' =>3,'c' =>2,'d' =>1]</h3>
	<form action = 's8.php' method = 'post'>
		<input type = 'radio' name = 'ch' value = 'a'>Sort the array by values (changing the keys) in ascending, descending order.<br>
		<input type = 'radio' name = 'ch' value = 'b'>Also sort the array by values without changing the keys.<br>
		<input type = 'radio' name = 'ch' value = 'c'>Filter the odd elements from an array.<br>
		<input type = 'radio' name = 'ch' value = 'd'>Sort the different arrays at a glance using single function.<br>
		<input type = 'radio' name = 'ch' value = 'e'>Merge the given arrays.<br>
		<input type = 'radio' name = 'ch' value = 'f'>Find the Union, intersection& set difference of two arrays.<br>
		<input type = 'submit' name = 'sub'>
	</form>
</body>
</html>


<?php

/*
Write a menu driven PHP program to perform the following operations on associative 
arrays: 
a) Sort the array by values (changing the keys) in ascending, descending order. 
b) Also sort the array by values without changing the keys. 
c) Filter the odd elements from an array. 
d) Sort the different arrays at a glance using single function. 
e) Merge the given arrays.
f) Find the Union, intersection& set difference of two arrays. 
*/

$arr = ['a' =>5,'b' => 4,'c' =>3,'c' =>2,'d' =>1];
if(isset($_POST['sub']))
{
	switch($_POST['ch'])
	{
		case 'a':
			echo 'Ascending Order <br>';
			sort($arr);
			print_r($arr);
			echo '<br>descending Order <br>';
			rsort($arr);
			print_r($arr);
			break;
		
		case 'b':
			echo 'Ascending Order <br>';
			asort($arr);
			print_r($arr);
			echo '<br>descending Order <br>';
			arsort($arr);
			print_r($arr);
			break;

		case 'c':
			foreach($arr as $val)
			{
				if($val % 2 == 0)
					echo "even : $val<br>";
				else
					echo "odd : $val<br>";
			}
			break;


			

	}
}

?>