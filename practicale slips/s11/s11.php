<?php
interface shape
{
	public function area();
}

class Rectangle implements shape
{
	public $length,$width;
	
	public function __construct($length,$width)
	{
		$this->length = $length;
		$this->width = $width;
	}
	public function area()
	{
		return $this->length * $this->width;
	}
}

class squer extends Rectangle
{
	public function __construct($side)
	{
		parent::__construct($side,$side);
	}
}

class circle implements shape
{
	public $radius;
	function __construct($radius)
	{
		$this->radius = $radius;
	}
	function area()
	{
		return M_PI * $this->radius * $this->radius;
	}
}

$squer = new squer(4);
$circle = new circle(7);
$rectangle = new Rectangle(3,5);

echo "<br>Area Of Squer : ",$squer->area();
echo "<br>Area Of circle : ",$circle->area();
echo "<br>Area Of rectangle : ",$rectangle->area();

?>