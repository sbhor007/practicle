<?php
/*
Write class declarations and member function definitions for an employee(code, 
name, designation). Design derived classes as emp_account(account_no, 
joining_date) from employee and emp_sal(basic_pay, earnings, deduction) from 
emp_account. Write a menu driven PHP program a) to build a master table b) to sort 
all entries c) to search an entry d) Display salary
*/

class employee
{
    public $e_code,$e_name,$e_desg;
    function __construct($ecode,$ename,$edesg)
    {
        $this->e_code = $ecode;
        $this->e_name = $ename;
        $this->e_desg = $edesg;
    }
    public function display_info()
    {
        echo "
        <td>$this->e_code</td>
        <td>$this->e_name</td>
        <td>$this->e_desg</td>
        ";
    }
    public function getName()
    {
        echo"
         <td>$this->e_name</td>
         ";
    }
}
    class emp_account extends employee
    {
        public $acc_no,$jdate;
        function __construct($ecode,$ename,$edesg,$accno,$jdate)
        {
            parent::__construct($ecode,$ename,$edesg);
            $this->acc_no = $accno;
            $this->jdate = $jdate;
        }
        public function display_acc()
        {
            echo "
            <td>$this->acc_no</td>
            <td>$this->jdate</td>
            ";
        }
    }
    class emp_salary extends emp_account
    {
        public $basic_sal,$earning,$deduction,$total;
        function __construct($ecode,$ename,$edesg,$accno,$jdate,$bsal,$earn,$deduct)
        {
            parent::__construct($ecode,$ename,$edesg,$accno,$jdate);
            $this->basic_sal=$bsal;
            $this->earning=$earn;
            $this->deduction=$deduct;
            $this->total = $this->basic_sal + $this->earning - $this->deduction;
        }
        public function display_sal()
        {
            echo "<td>$this->basic_sal</td>
            <td>$this->earning</td>
            <td>$this->deduction</td>
            <td>$this->total</td>";
        }

    }

$emp[0] = new emp_salary('100','santosh',"manager",'123456789','22-07-2022','70000','25000','2000');
$emp[1] = new emp_salary('102','yash',"manager",'123456789','22-07-2022','70000','25000','2000');
$emp[2] = new emp_salary('103','dipak',"manager",'123456789','22-07-2022','70000','25000','2000');
$emp[3] = new emp_salary('104','yogesh',"manager",'123456789','22-07-2022','70000','25000','2000');
$emp[4] = new emp_salary('105','roshan',"manager",'123456789','22-07-2022','70000','25000','2000');

function mastertable($emp)
{
    echo "
    <h1 style = 'text-align:center;'>Master Table</h1>
    <table border = '1' width = '100%'>
    <tr>
        <th>Code</th>
        <th>Name</th>
        <th>Designation</th>
        <th>Ac No</th>
        <th>Date</th>
        <th>Basic Salary</th>
        <th>Earning</th>
        <th>Deduction</th>
        <th>Total salary</th>
    </tr>
    ";
    for($i = 0;$i<5;$i++)
    {
        echo "<tr>";
            $emp[$i]->display_info();
            $emp[$i]->display_acc();
            $emp[$i]->display_sal();
        echo "</tr>";
    }
    echo "</table>";

}
if(isset($_POST['sub']))
{
    switch($_POST['ch'])
    {
        case 1:
            mastertable($emp);
            break;
            case 2:
                usort($emp, function($a,$b){
                    return strcmp($a->e_name,$b->e_name);
                });
                mastertable($emp);
                break;
                case 3:
                    break;
                    case 4:
                        echo "<h3>Display Employee salary...</h3><br><br>";
                        echo "<table border = '1' width = '100%'>
                        <tr>
                            <th>Employee name</th>
                            <th>Basic salary</th>
                            <th>Earnig</th>
                            <th>Deduction</th>
                            <th>Toatl</th>
                        </tr>
                        ";
                        for($i = 0; $i<5;$i++)
                        {
                            echo "<tr>";
                            $emp[$i]->getName();
                            $emp[$i]->display_sal();
                            echo "</tr>";
                        }
                        echo "</table>";
    }
}



?>
