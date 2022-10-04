<?php
class SomeClass
	{

		function __construct()
		{
			echo "This is constructor";
			$this->name = "Class object! ";
		}

		function __destruct()
		{
			echo " This is destrutor and object is destroying " . $this->name . "\n";
		}
	}
$obj = new Someclass();

?>
