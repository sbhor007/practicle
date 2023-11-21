<html>
<!-- 
Write a PHP script to create a form to accept student information (name, class, 
address). Once the student information is accepted, accept marks in next form (Phy, 
Bio, Chem, Maths, Marathi, English).Display the mark sheet for the student in the 
next form containing name, class, marks of the subject, total and percentage.[25 M]
-->
<body>
<h1>Student Information</h1>
	<form action = "s21B.php" method = "post">
		Name : <input type = "text" name = "sname"><br><br>
		Class : <input type = "text" name = "class"><br><br>
		Address : <textarea name = "addr"></textarea><br><br>
		<input type = "submit" value = "Next" name = "next">
	</form>
</body>
</html>