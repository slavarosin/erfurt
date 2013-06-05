<?php
require('../req/dbaseutils.class');
$shipment_param = $_POST["shipment_id"];


$headpicvariable = $_POST["head_picture"];
if (trim($headpicvariable)=="")$headpicvariable='city';

//echo $shipment_param;


$shipment_archiver = new class_dbaseutils;
//echo "new dbobject created<br>";

$shipment_archiver->sql_connect();
//echo "dabase connect<br>";

 	
$shipment_archiver->archive_shipment($shipment_param);
//echo "shipment updated<br>";

//echo $shipment_archiver->sql_err;
if(trim($shipment_archiver->sql_err)!="0")
{
	header("location: ../BWCabinet.php?pg=error&&err_details=".$shipment_archiver->sql_err);
}
else
{
	header("location: ../BWCabinet.php?pg=myshipments");
}
$shipment_archiver->sql_close();
//echo "Connection Closed<br>";

?>