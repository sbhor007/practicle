<html>
<!-- Using regular expressions check for the validity of entered email-id. The @ symbol 
should not appear more than once. The dot (.) can appear at the most once before @ 
and at the most twice or at least once after @ symbol. The substring before @ should 
not begin with a digit or underscore or dot or @ or any other special character. (Use 
explode and ereg function.).
-->
<body>
	<form action = "s14.php" method = "post">
		E-mail : <input type = "text" name = "mail">
		<input type = "submit" value = "check validate" name = "sub">
	</form>
</body>
</html>

<?php

if(isset($_POST['mail']))
{
	$mail = $_POST['mail'];
	if(filter_var($mail,FILTER_VALIDATE_EMAIL) == false)
	{
		echo "those email not validdate";
	}
	else
	{
		echo "those email validate";
	}
}

?>