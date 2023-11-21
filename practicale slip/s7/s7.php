<?php
/*
Write a menu driven PHP program to perform the following operations on an 
associative array: 
i. Display the elements of an array along with the keys. 
ii. Display the size of an array 
iii. Delete an element from an array from the given index.
iv. Reverse the order of each element’s key-value pair.[Hint: use array_flip()]
v. Traverse the elements in an array in random order [[Hint: use shuffle()]
*/

$arr = array(
    "a" => "Apple",
    "b" => "banana",
    "c" =>"cherry",
    "d" => "Date"
);

//Display the elements of an array along with the keys.
foreach($arr as $key => $val)
    echo "$key -> $val <br>";
//Display the size of an array
echo "<br>Size of array : ", count($arr),"<br>";

//Delete an element from an array from the given index.
printf("<br>Delete an element from an array from the given index.<br>");
print_r($arr);
unset($arr["b"]);
echo "<br>";
print_r($arr);

// Reverse the order of each element’s key-value pair.[Hint: use array_flip()]
printf("<br><br>Reverse the order of each element's key-value pair.<br>");
$rev = array_flip($arr);
print_r($rev);

// Traverse the elements in an array in random order [[Hint: use shuffle()]
printf("<br><br> Traverse the elements in an array in random order [[Hint: use shuffle()]<br>");
$keys = array_keys($arr);
shuffle($keys);
foreach($keys as $key)
    echo "$key<br>";