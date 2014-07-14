<?php
$con = mysql_connect("localhost","root","iamfreenow26") or die("Unable to connect to SERVER.sdfs.!");
$db = mysql_select_db("weg_appilant_dev",$con) or die("Unable to connect to DATABASE..!");
$ArrayUserWithCredits = array('user_id' => '104', 'name' => 'suman', 'email' => 'sumansourabh26@yahoo.com');


class UserTest extends PHPUnit_Framework_TestCase{
	public function FunctionName(){
		global $ArrayuserWithCredits;// $ArrayuserWithNoCredits, $ArraySubuser;
		$testUser = getUserById($ArrayuserWithCredits['user_id']);
		$result = mysql_query("SELECT * FROM login_table WHERE `email_id` = {$ArrayUserWithCredits}['email']") or die( mysql_error());
		$assoc = mysql_fetch_assoc($result);
		$actualUser = new User($ArrayUserWithCredits['email'], $assoc['password']);

		$this->assertEquals($testUser, $actualUser);
	}
}
?>