<?php
/*
Derive a class square from class Rectangle. Create one more class circle. Create an 
interface with only one method called area(). Implement this interface in all the 
classes. Include appropriate data members and constructors in all classes. Write a PHP 
program to accept details of a square, circle and rectangle and display the area.
*/
$radius = 3;
$side = 10;
$breadth =11;
$length = 12;
interface one
{
    function area($length,$breadth);
}
class rect implements one
{
    function area($length,$breadth)
    {
        $area = $length*$breadth;
        echo "Area of Rectangle : $area <br>";
    }
}
class square extends rect
{
    function area($side,$side1)
    {
        $area = $side * $side1;
        echo "Area of Square : $area <br>";
    }
}
class circle 
{
    function area($radius)
    {
        $area = 3.14*$radius*$radius;
        echo "Area of Circle : $area <br>";
    }
}

$rectangle = new rect();
$rectangle->area($length,$breadth);
$square = new square();
$square->area($side,$side);
$circle = new circle();
$circle->area($radius);

?>