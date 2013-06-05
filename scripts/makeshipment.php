<?php
require('../req/dbaseutils.class');
session_start();

$rcvCompany         =$_POST['oneshp_company_name'];
$rcvContactPerson	=$_POST['oneshp_contact_person_name'];
$rcvPersonPosition  =$_POST['oneshp_contact_person_position'];

$rcvStreet1			=$_POST['oneshp_street1'];
$rcvStreet2			=$_POST['oneshp_street2'];
$rcvCity			=$_POST['oneshp_city'];

$rcvState			=$_POST['oneshp_state'];
$rcvZip				=$_POST['oneshp_zip'];
//$rcvEmail			=$_POST['oneshp_email'];
$rcvEmail			='oneshp_email';


$rcvPhone			=$_POST['oneshp_phone'];
$rcvCell			='oneshp_cell_phone';
$rcvFax				='oneshp_fax';

$sndrCarrier		=$_POST['oneshp_carrier'];
$packDescription	=$_POST['oneshp_description'];

$packWeightNum		=$_POST['oneshp_weight'];
$packWeghtDef		=$_POST['weight_span'];
$packWeight          =$packWeightNum." ".$packWeghtDef;

$packValue			=$_POST['oneshp_value'];
$serviceType		=$_POST['oneshp_servicetype'];



$oneshipment  = new class_dbaseutils;
$oneshipment->sql_connect();

$serviceTypeCost = $oneshipment->get_price($serviceType);


if(trim($oneshipment->sql_err)!="0")
{
	header("location: ../BWCabinet.php?pg=error&&err_details=".$oneshipment->sql_err);
}
else
{
	$amount_check = $oneshipment->get_trans_total($_SESSION['login']);
	if( $amount_check['sum(sum)']<$serviceTypeCost)
	{
			header("location: ../BWCabinet.php?pg=oneshipment&outofM=2");
	}
	else{
		$oneshipment->make_transaction($_SESSION['login'], $serviceTypeCost);
		
		$oneshipment-> make_shipment($rcvEmail, $rcvCompany, $rcvContactPerson, $rcvPersonPosition, $rcvCity, $rcvStreet1,
		$rcvStreet2, $rcvState, $rcvZip, $serviceType, 'SOMEID', $_SESSION["additional_param"], $sndrCarrier, $packDescription, $packWeight, $packValue);
		if(trim($oneshipment->sql_err)!="0")
		{
			header("location: ../BWCabinet.php?pg=error&&err_details=".$oneshipment->sql_err);
		}
		else
		{
			header("location: ../BWCabinet.php?pg=myshipments");
		}
	}
}


$oneshipment->sql_close();

?>