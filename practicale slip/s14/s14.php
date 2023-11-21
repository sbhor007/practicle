<!DOCTYPE html>
<html lang="en">
<head>
    <!-- 
        Using regular expressions check for the validity of entered email-id. The @ symbol 
should not appear more than once. The dot (.) can appear at the most once before @ 
and at the most twice or at least once after @ symbol. The substring before @ should 
not begin with a digit or underscore or dot or @ or any other special character. (Use 
explode and ereg function.).
     -->
    <title>Document</title>
</head>
<body>
    <form action="s14.php" method="post">
        Email : <input type="email" name="email">
        <input type="submit" value="check" name="sub">
    </form>
</body>
</html>
<?php
if(isset($_POST['sub']))
{
    $email = $_POST['email'];
    if(!filter_var($email,FILTER_VALIDATE_EMAIL) == false)
    {
        echo "$email <br> Is Valid Email";
    }
    else
    {
        echo "$email <br> Is Not Valid Email";
    }
}
?>