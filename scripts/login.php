<?php
require('../req/dbaseutils.class');

$login = $_POST["login"];
$passwd = $_POST["password"];

$headpicvariable = $_POST["head_picture"];
if (trim($headpicvariable)=="")$headpicvariable='city';

$loginCheker = new class_dbaseutils;
$loginCheker->sql_connect();
//echo $loginCheker->sql_err;
$localerror = trim($loginCheker->sql_err);
if($localerror!="0")
{
	header("location: ../?pg=error&err_details=".$localerror);
}
else
{
	$result = $loginCheker-> get_user($login, $passwd);
	$localerror = trim($loginCheker->sql_err);
	if($localerror!="0")
	{
		header("location: ../?pg=error&err_details=".$localerror);
	}
	else
	{
		if(trim($result[0])!="")
		{


			session_register("login");
			session_register("additional_param");

			$_SESSION["login"] = $result['username'];
			$_SESSION["additional_param"] = $result['address_id'];


			header("location: ../BWCabinet.php?pg=about");
				
		}
		else
		{
			header("location: ../?pg=error&err_details=Forgot your password?");
		}
			
	}

}
?>