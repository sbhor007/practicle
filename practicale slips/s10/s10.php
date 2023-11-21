<?php


/*
Write class declarations and member function definitions for an 
employee(code, name, designation). Design derived classes as 
emp_account(account_no, joining_date) from employee and 
emp_sal(basic_pay, earnings, deduction) from 
emp_account. 
Write a menu driven PHP program 
a) to build a master table 
b) to sort all entries 
c) to search an entry 
d) Display salary
*/

class employee
{
	public $ecode,$ename,$desig;
	function __construct($code,$name,$des)
	{
		$this ->ecode = $code;
		$this ->ename = $name;
		$this ->desig = $des;
	}
	public function emp_info()
	{
		echo "
			<td>$this->ecode</td>
			<td>$this->ename</td>
			<td>$this->desig</td>
				";
	}
	public function getName($name)
	{
		$this->ename = $name;
	}
}

class emp_account extends employee
{
	public $acc_no,$joining_date;
	
	function __construct($code,$name,$des,$acc_no,$j_date)
	{
		parent::__construct($code,$name,$des);
		$this->acc_no = $acc_no;
		$this->joining_date = $j_date;
	}
	public function account_info()
	{
		echo "
			<td>$this->acc_no</td>
			<td>$this->joining_date</td>
			";
	}
		
}

class emp_salary extends emp_account
{
	public $basic_pay, $earnings, $deduction ;
	function __construct($code,$name,$des,$acc_no,$j_date,$b_pay,$earn,$ded)
	{
		parent::__construct($code,$name,$des,$acc_no,$j_date);
		$this->basic_pay = $b_pay;
		$this->earnings = $earn;
		$this->deduction = $ded;
	}
	public function salary_info()
	{
		echo "
			<td>$this->basic_pay</td>
			<td>$this->earnings</td>
			<td>$this->deduction </td>
			";

	}
}



$emp[0] = new emp_salary (100,"santosh","ceo",123456,"22-07-2003",200000,150000,5000);
$emp[1] = new emp_salary (101,"yash","ceo",123456,"22-07-2003",200000,150000,5000);
$emp[2] = new emp_salary (101,"dipak","ceo",123456,"22-07-2003",200000,150000,5000);
$emp[3] = new emp_salary (101,"yogesh","ips",123456,"22-07-2003",200000,150000,5000);
$emp[4] = new emp_salary (104,"shivam","pharmasy",123456,"22-07-2003",200000,150000,5000);

function mastertable($emp)
{
	echo "
		<h1 style = 'text-align:center';>MASTER TABLE</h1>";
	echo "
		<table border = 1 width = 100%>
			<tr>
				<td>Employee Code</td>
				<td>Employee Name</td>
				<td>Designation</td>
				<td>Account No</td>
				<td>Joining date</td>
				<td>Basic Pay</td>
				<td>Earning</td>
				<td>Deduction</td>
			</tr>";
		
	for($i=0;$i<count($emp);$i++)
	{
		echo "<tr>";
			$emp[$i]->emp_info();
			$emp[$i]->account_info();
			$emp[$i]->salary_info();

		echo "</tr>";
	}
	echo "
	</table>
	";
		
}
mastertable($emp)


?>