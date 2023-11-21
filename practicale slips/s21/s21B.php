<html>
<body>
	<h1>Marks</h1>
	<form action = "s21C.php" method = "post">
		Bio : <input type = "text" name = "bio"><br><br>
		Chem : <input type = "text" name = "chem"><br><br>
		Maths : <input type = "text" name = "maths"><br><br>
		Marathi : <input type = "text" name = "marathi"><br><br>
		English : <input type = "text" name = "english"><br><br>
		<input type = "submit" value = "Genarate Result" name = "sub">
</body>
</html>

<?php

session_start();
$_SESSION['sname'] = $_POST['sname'];
$_SESSION['class'] = $_POST['class'];
$_SESSION['addr'] = $_POST['addr'];

?>