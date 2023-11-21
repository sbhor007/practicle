<?php
session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <title>Document</title>
</head>
<body>
    <h2>BILL</h2>
    <h4>Customer Name : <?php echo $_SESSION['cname']; ?></h4>
    <h4>Customer Address : <?php echo $_SESSION['addr']; ?></h4>
    <h4>Customer Pnone No. : <?php echo $_SESSION['pno']; ?></h4>
    <h4>Product Name : <?php echo $_POST['pname'];?></h4>
    <h4>Quantiti : <?php echo $_POST['qty'];?></h4>
    <h4>Rate : <?php echo $_POST['rate'];?></h4>
    <h4>TOTAL : <?php echo $_POST['qty'] * $_POST['rate'];?></h4>
    
</body>
</html>