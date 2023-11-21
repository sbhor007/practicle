<?php
/*
Write a menu driven PHP program to perform the following operations on an 
associative array: 

*/

$arr = ['a' => 1,'b' => 2,'c' => 3,'d' => 4,'e' =>5];
// i. Display the elements of an array along with the keys. 
echo "<br>Display the elements of an array along with the keys.<br>";
foreach($arr as $key => $val)
    echo "$key -> $val <br>";

    // ii. Display the size of an array 
    echo "<br>Display the size of an array.<br>";
    echo "array size is : ",sizeof($arr),"<br>";

    // iii. Delete an element from an array from the given index.
    echo "<br>Delete an element from an array from the given index.<br>";
    unset($arr['b']);
    print_r($arr);
    
    // iv. Reverse the order of each element’s key-value pair.[Hint: use array_flip()]
    echo "<br><br>Reverse the order of each element’s key-value pair<br>";
    print_r(array_flip($arr));
    // v. Traverse the elements in an array in random order [[Hint: use shuffle()]
    echo "<br><br>Traverse the elements in an array in random order<br>";
    print_r(shuffle($arr))

    
?>