<html>
    <!--
Write a menu driven PHP program to perform the following operations on associative 
arrays: 
a) Sort the array by values (changing the keys) in ascending, descending order. 
b) Also sort the array by values without changing the keys. 
c) Filter the odd elements from an array. 
d) Sort the different arrays at a glance using single function. 
e) Merge the given arrays.
f) Find the Union, intersection& set difference of two arrays. 
-->
<body>
    <form action="s8.php" method="post">
        <input type="radio" name="ch" value=1>sort the array by values (changing the keys) in ascending, descending order <br>
        <input type="radio" name="ch" value=2>Also sort the array by values without changing the keys <br>
        <input type="radio" name="ch" value=3>Filter the odd elements from an array. <br>
        <input type="radio" name="ch" value=4>Sort the different arrays at a glance using single function <br>
        <input type="radio" name="ch" value=5>Merge the given arrays. <br>
        <input type="radio" name="ch" value=6>Find the Union, intersection& set difference of two arrays <br>
        <input type="submit" name = "sub">
    </form>
</body>
</html>
<?php
if(isset($_POST['sub']));
{
    $arr = array('a' => 1,'b' => 2,'c' => 3,'d' => 4,'e' => 5);
    $arr1 = array('p' => 10,'q' => 20,'r' => 30,'s' => 40,'t' => 50);
    $arr2 = array('a' => 5,'b' => 22,'c' => 33,'d' => 44,'e' => 55);
    switch($_POST['ch'])
    {
        case 1:
            sort($arr);
            echo "<br>ascending order<br>";
            print_r($arr);
            echo "<br>desending order<br>";
            rsort($arr);
            print_r($arr);
            break;
            case 2:
                asort($arr);
                echo "<br>ascending order<br>";
                print_r($arr);
                arsort($arr);
                echo "<br>desending order<br>";
                print_r($arr);
                break;
                case 3:
                    foreach($arr as $val)
                    {
                        if($val % 2 == 0)
                        echo "<br>Even : $val";
                    else
                    echo "<br>odd : $val";
                    }
                    break;
                    case 4:
                        echo "<br>array Multy sort<br>";
                        array_multisort($arr,0,$arr1,1,$arr2,0);
                        print_r($arr);
                        echo "<br>";
                        print_r($arr1);
                        echo "<br>";
                        print_r($arr2);
                        echo "<br>";
                        break;
                        case 5:
                            //echo "<pre>";
                            print_r(array_merge($arr,$arr1));
                            break;
                            case 6:
                                echo "Unioun of an array<br>";
                                $union = array_merge($arr,$arr1);
                                print_r(array_unique($union));
                                echo "<br>Intersect of an array<br>";
                                print_r(array_intersect($arr,$arr2));
                                echo "<br>different of an array<br>";
                                print_r(array_diff($arr,$arr2));

                           
    }
}
?>
