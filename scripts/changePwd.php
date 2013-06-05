<?php
require('../req/dbaseutils.class');
session_start();

$OldPass = $_POST['prfl_old_pass'];

$NewPass = $_POST['prfl_new_pass'];

$NewPassConfirmed = $_POST['prfl_new_pass_confirm'];

$change_pass_object = new class_dbaseutils;

$change_pass_object->sql_connect();

$userCount = $change_pass_object->get_user($_SESSION['login'], $OldPass);
if($userCount['username']==$_SESSION['login'])
{
	
	
	if($NewPass==$NewPassConfirmed)
	{
		$change_pass_object->update_passwd($_SESSION['login'],$NewPass);
		header("location: ../BWCabinet.php?pg=profile&passeditOK=1");
	}
	else
	{
		header("location: ../BWCabinet.php?pg=profile&npm=22");
	}
}
else
{
	header("location: ../BWCabinet.php?pg=profile&opm=12");
}


$change_pass_object->sql_close();
?>