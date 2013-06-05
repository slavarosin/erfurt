<?php
require('../req/dbaseutils.class');
session_start();

//form variables
$company_name = $_POST['prfl_company_name'];
$contact_person_name = $_POST['prfl_contact_person_name'];
$contact_person_position = $_POST['prfl_contact_person_position'];

$street1 = $_POST['prfl_street1'];
$street2 = $_POST['prfl_street2'];
$city = $_POST['prfl_city'];

$zip = $_POST['prfl_zip'];
$state = $_POST['prfl_state'];


$email = $_POST['prfl_email'];
$phone = $_POST['prfl_phone'];
$cell_phone = $_POST['prfl_cell_phone'];

$fax = $_POST['prfl_fax'];
$carrier = $_POST['prfl_carrier'];

$expensesPart = $_POST['prfl_expenses'];
$expenses_time_span = $_POST['prfl_expences_time_span'];
$expenses = $expensesPart.":".$expenses_time_span;




$buff = $_POST['prfl_pickup_route'];
if($buff=="yes")$pickup_route = '1';
if($buff=="no")$pickup_route = '0';


$amountPart = $_POST['prfl_amount'];
$time_span = $_POST['prfl_time_span'];
$amount = $amountPart.":".$time_span;

$buff_international = $_POST["prfl_international"];
if($buff_international=="yes")$international='1';
if($buff_international=="no")$international='0';

$headpicvariable = $_POST["head_picture"];
if (trim($headpicvariable)=="")$headpicvariable='city';

$newPasswd = $_POST["prfl_passwd"];




/*echo $company_name."<br>" ;
 echo $contact_person_name."<br>";
 echo $contact_person_position."<br>";

 echo $street1."<br>";
 echo $street2."<br>";
 echo $city."<br>";

 echo $zip."<br>";
 echo $state."<br>";


 echo  $email."<br>";
 echo $phone."<br>";
 echo $cell_phone."<br>";

 echo $fax."<br>";
 echo $carrier."<br>";
 echo $expenses."<br>";

 echo $amount."<br>";
 echo $international." Internat<br>";
 echo $pickup_route." on the road again<br>";*/

$var = new class_dbaseutils;
$var->sql_connect();

//        update_profile($strEmail, $strAdditionalParam, $strCompany,$strContactPerson, $strContactPersonPosition, $strExpenses, $strPickupRoute,$strInternational , $strAmount, $strRole, $strPhone, $strCell, $strFax, $strCity, $strStreet1, $strStreet2, $strState, $strZip)

$var->update_profile($_SESSION["login"], $_SESSION["additional_param"], $company_name,$contact_person_name, $contact_person_position, $expenses, $pickup_route,$international, $amount, 'ROLE', $phone, $cell_phone, $fax, $city, $street1, $street2, $state, $zip);
if(trim($var->sql_err)!="0")
{
	header("location: ../BWCabinet.php?pg=error&&err_details=".$var->sql_err);
}
else
{
	header("location: ../BWCabinet.php?pg=profile&&profileEditOK=1");
}


$var->sql_close();
?>