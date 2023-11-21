<!DOCTYPE html>
<html lang="en">
<head>
    <title>Document</title>
</head>
<body>
    <form action="s27.php" method = "post">
        Project name : <input type="text" name="pname">
        <input type="submit" value="Search" name ="sub">
    </form>
</body>
</html>

<?php
    $host = '127.0.0.1';
    $user = "root";
    $pass = "";
    $db_name = "php";

    $conn = new mysqli($host,$user,$pass,$db_name);
    if($conn->connect_error)
    {
        die ("Connection not stablish".$conn->connect_error);
    }
    else
    {
        echo "Connection Successfull !";
    }
    $sql = "CREATE TABLE project(
        pno int primary key,
        p_name varchar(30),
        ptype varchar(20),
        duration int
        );";
        
       /* if($conn->query($sql))
        {
            echo "Table created successfully.";
        }
        else
        {
            echo "<br>Error creating table: ". $conn->error;
        }*/
        $sql = "CREATE TABLE employee(
            eno int primary key,
            e_name varchar(50),
            qualification varchar(15),
            joinDate date
        )";
        /*if($conn->query($sql))
        {
            echo "<br>Employee Table Created";
        }
        else
        {
            echo "<br>Error :: ".$conn->error;
        }
        */
        $sql = "CREATE TABLE pm(
            pno int references project(pno),
            eno int references employee(eno),
            start_date date,
            hours_worked int
        );";
         /* if($conn->query($sql))
        {
            echo "<br>PM table was created.";
        }
        else
        {
            echo "<br>Error :: ",$conn->error;
        }*/
        $sql = "insert into project values(3,'space','z',50);";
        /*if($conn->query($sql))
        {
            echo "<br>record iserted";
        }
        else
        {
            echo "<br>Error :: ",$conn->error;
        }*/
        $sql = "insert into employee values(103,'Dipak','BCA','2020-07-20');";
        /*if($conn->query($sql))
        {
            echo "<br>Record inserted...";
        }
        else
        {
            echo "<br>Error :: ",$conn->error;
        }*/
        $sql = "insert into pm values(3,102,'2020-08-01',60);";
        /*if($conn->query($sql))
        {
            echo "<br>Record inserted...";
        }
        else
        {
            echo "<br>Error :: ",$conn->error;
        }*/
        if(isset($_POST['sub']))
        {
            $name = $_POST['pname'];
            $sql = "
            SELECT e.e_name,e.qualification,pm.start_date,pm.hours_worked
            FROM pm
            JOIN project p ON pm.pno = p.pno
            JOIN employee e ON pm.eno = e.eno
            where p.p_name = '$name';
            ";
            $result = $conn->query($sql);
            if($result->num_rows > 0)
            {
                echo "<h2>Employee working on project $name :</h2>";
                echo "<table border = '1'>";
                echo "
                <tr>
                    <th>Employee name</th>
                    <th>Qualigication</th>
                    <th>Start Date</th>
                    <th>Hours Worked</th>
                </tr>
                ";

                while($row = $result->fetch_assoc())
                {
                    echo "<tr>";
                    echo "<td>". $row["e_name"]. "</td>";
                    echo "<td>". $row["qualification"]. "</td>";
                    echo "<td>". $row["start_date"]. "</td>";
                    echo "<td>". $row["hours_worked"]. "</td>";
                }
                echo "</table>";
            }    
            else
            {
                echo "<h2>No employee found Error:: ",$conn->error ,"</h2>";
            }
        }
        // mysqli->close($conn);
?>