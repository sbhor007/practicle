<?php

    $Massage = $_POST['mass'];
    $font = $_POST['font'];
    $fsize = $_POST['fsize'];
    $fcolor = $_POST['fcolor'];
    $bcolor = $_POST['bcolor'];
    setcookie('massage',$Massage);
    setcookie('font',$font);
    setcookie('fsize',$fsize);
    setcookie('fcolor',$fcolor);
    setcookie('bcolor',$bcolor);

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <style>
        body{
            font-style : <?php echo $_COOKIE['font']; ?>;
            color : <?php echo $_COOKIE['fcolor']; ?>;
            background-color : <?php echo $_COOKIE['bcolor'];?>;
            font-size : <?php echo $_COOKIE['fsize']; ?>;
        }
    </style>
    <title>Document</title>
</head>
<body>
    <h2>Select Preferences</h2>
    <p>Font style : <?php echo $_COOKIE['font']; ?></p>
    <p>Font Size : <?php echo $_COOKIE['fsize']; ?></p>
    <p>Font color : <?php echo $_COOKIE['fcolor']; ?></p>
    <p>Background color : <?php echo $_COOKIE['bcolor']; ?></p>
</body>
</html>