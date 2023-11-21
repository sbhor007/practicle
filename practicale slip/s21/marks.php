<!DOCTYPE html>
<html lang="en">
<head>
    <title>Document</title>
</head>
<body>
   <h2>Fill Your Marksd</h2> 
   <form action="marks.php" method="post">
    Physics : <input type="number" name="phy"><br><br>
    Biology : <input type="number" name="bio"><br><br>
    Chemestri : <input type="number" name="chem"><br><br>
    Math : <input type="number" name="math"><br><br>
    Marathi : <input type="number" name="mar"><br><br>
    English : <input type="number" name="eng"><br><br>
    <input type="submit" name = "sub">
   </form>

</body>
</html>
<?php
session_start();
if(isset($_POST['sub']))
{
    $_SESSION['name'] = $_POST['name'];
    $_SESSION['class'] = $_POST['class'];
    $_SESSION['add'] = $_POST['add'];
}
?>