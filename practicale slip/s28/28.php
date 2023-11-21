<!DOCTYPE html>
<html lang="en">
<head>
    <!-- 
        Consider the following entities and their relationships 
student (sno integer, s_name char(30), s_class char(10), s_addr char(50)),
teacher (tno integer, t_name char (20), qualification char (15),experience integer). 
The relationship between student-teacher: m-m with descriptive attribute subject. 
Using above database write a script in PHP to accept a teacher name from user and 
display the names of students along with subjects to whom teacher is teaching.
     -->
    <title>Document</title>
</head>
<body>
    
</body>
</html>
<?php 

$host = '127.0.0.1';
$user = 'root';
$pass = '';
$db_name = 'php';

$conn = new mysqli($host,$user,$pass,$db_name);
if($conn->connect_error)
{
    die("Connection Fail <br>ERROR ::". $conn->connect_error);
}
else{
    echo "connection successfull...";
}

$sql = "CREATE TABLE student(
    sno int primary key,
    sname varchar(30),
    sclass varchar(30),
    saddr varchar(50)
);";
/*if($conn->query($sql))
{
    echo "<br>Table Created...";
}
else{
    echo "<br>ERROR::". $conn->error;
}*/
$sql = "CREATE TABLE teacher(
    tno int primary key,
    tname varchar(20),
    qualification varchar(15),
    experience int
);";
/*if($conn->query($sql))
{
    echo "<br>Table Created...";
}
else{
    echo "<br>ERROR::". $conn->error;
}*/
$sql = "CREATE TABLE st(
    sno int references student(sno),
    tno int references teacher(tno)
);";
/*if($conn->query($sql))
{
    echo "<br>Table Created...";
}
else{
    echo "<br>ERROR::". $conn->error;
}*/

$sql = "INSERT INTO student values(5,'yogesh','tybcom','peth')";
/*if($conn->query($sql))
{
    echo "<br>Record inserted...";
}
else{
    echo "<br>ERROR::". $conn->error;
}*/
$sql = "INSERT INTO teacher VALUES(105,'pawar','mca',2);";
/*if($conn->query($sql))
{
    echo "<br>Record inserted...";
}
else{
    echo "<br>ERROR::". $conn->error;
}*/

$sql = "INSERT INTO st VALUES(4,101)";
/*if($conn->query($sql))
{
    echo "<br>Record inserted...";
}
else{
    echo "<br>ERROR::". $conn->error;
}*/
$name = 'wagh';
$sql = "
    SELECT sname
    FROM st
    JOIN student s ON s.sno = st.sno
    JOIM teacher t ON t.tno = st.tno
    where tname = '$name'
";
?>