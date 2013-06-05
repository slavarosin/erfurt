<?php
require('../req/dbaseutils.class');

$mail_of_pesrosn_who_lost_pwd = $_POST["mail_forgotten"];

$headpicvariable = $_POST["head_picture"];
if (trim($headpicvariable)=="")$headpicvariable='city';


$reminder = new class_dbaseutils;
$reminder->sql_connect();
if(trim($reminder->sql_err)!="0")
{
	header("location: ../?pg=error&&err_details=".$reminder->sql_err);
}
else
{
	$pwd_array = $reminder->get_profile($mail_of_pesrosn_who_lost_pwd);
	if(trim($reminder->sql_err)!="0")
	{
		//header("location: ../?pg=error&&err_details=".$reminder->sql_err);
	}
	else
	{
		$chek_email = $pwd_array['username'];
			
		if(trim($chek_email)!="")
		{
			session_start();
			session_register("check_email");
			$_SESSION["check_email"]=$chek_email;
			//$reminder->send_credentials($mail_of_pesrosn_who_lost_pwd, $forgotten_pass, $mail_of_pesrosn_who_lost_pwd);need proper SMTP setting
			
			header("location: ../?pg=pwdsent");
		}
		else
		{
			header("location: ../?pg=pwdnotsent");
		}

	}
}


?>