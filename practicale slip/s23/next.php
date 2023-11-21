<!DOCTYPE html>
<html lang="en">
<head>
    <title>Document</title>
</head>
<body>
    <h2>Product Information</h2>
    <form action="bill.php" method="post">
        Product Name: <input type="text" name="pname"><br><br>
        quantity: <input type="text" name="qty"><br><br>
        Rate: <input type="number" name="rate"><br><br>
        <input type="submit" value="submit" name = "sub">
    </form>
</body>
</html>
<?php
session_start();
if(isset($_POST['s'])){
$_SESSION['cname'] = $_POST['cname'];
$_SESSION['addr'] = $_POST['addr'];
$_SESSION['pno'] = $_POST['pno'];
}
?>