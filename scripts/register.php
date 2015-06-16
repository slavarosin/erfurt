<?php
require('../req/dbaseutils.class');

//form variables
$company_name = $_POST['company_name'];
$contact_person_name = $_POST['contact_person_name'];
$contact_person_position = $_POST['contact_person_position'];

$street1 = $_POST['street1'];
$street2 = $_POST['street2'];
$city = $_POST['city'];

$zip = $_POST['zip'];
$state = $_POST['state'];
$zip = $_POST['zip'];

$email = $_POST['email'];
$phone = $_POST['phone'];
$cell_phone = $_POST['cell_phone'];

$fax = $_POST['fax'];
$carrier = $_POST['carrier'];

$expensesPart = $_POST['expenses'];
$expenses_time_span = $_POST['expences_time_span'];
$expenses = $expensesPart.":".$expenses_time_span;

$buff = $_POST['pickup_route'];
if($buff=="yes")
$pickup_route = '1';
if($buff=="no")
$pickup_route = '0';

$amountPart = $_POST['amount'];
$time_span = $_POST['time_span'];
$amount = $amountPart.":".$time_span;


$buff_international = $_POST["international"];
if($buff_international=="yes")$international='1';
if($buff_international=="no")$international='0';

$headpicvariable = $_POST["head_picture"];
if (trim($headpicvariable)=="")$headpicvariable='city';

$ref_email = $_POST["ref_email"];

$var = new class_dbaseutils;
$pass = $var->generate_pass(8);
$var->sql_connect();

$err_buff = trim($var->sql_err);
if($err_buff!="0")
{
	header("location: ../?pg=error&&err_details=".$var->sql_err);
}
else
{
	$referalid = $var->get_referal_id(trim($ref_email));
	
	$var->insert_credentials($company_name, $contact_person_name, $contact_person_position, trim($email), $pass, $carrier, $expenses, $pickup_route,$international,
	$amount,'ROLE', $phone, $cell_phone, $fax, $city, $street1, $street2, $state, $zip, $referalid['id']);
	$err_buff = trim($var->sql_err);
	if($err_buff!="0")
	{
		header("location: ../?pg=error&&err_details=".$var->sql_err);
	}
	else
	{
		session_start();

		session_register("login");
		session_register("passwd");
		session_register("referal");
		
		$_SESSION["login"] = $email;
		$_SESSION["passwd"] = $pass;
		$_SESSION["referal"] = $referalid['id'];
		
		header("location: ../?pg=regdetails");
	}
}
$var->sql_close();
?>
