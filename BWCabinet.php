<?php
require("req/dbaseutils.class");

session_start();
if (!isset($_POST["login"]))
{
	session_start();
	if(!isset( $_SESSION["login"]) || !isset($_SESSION["additional_param"]))
	{
		header("location: ../erfurt_1/");
	}
}
$state_array = array ("AL","AK","AS","AZ","AR","CA","CO","CT","DE","DC","FM","FL","GA","GU","HI","ID","IL","IN","IA","KS","KY","LA","ME","MH","MD","MA","MI","MN","MS","MO","MT","NE","NV","NH","NJ","NM","NY","NC","ND","MP","OH","OK","OR","PW","PA","PR","RI","SC","SD","TN","TX","UT","VT","VI","VA","WA","WV","WI","WY");
$period_array = array("per day", "per week", "per month", "per year");
$weight_array = array("LB", "KG");

$servises_array = array("Envelope(GROUND)", "Envelope(2ND DAY)","Envelope(NEXT DAY)","Envelope(PRIORITY EXPRESS)","0-2 kg / 0-5 lb package(GROUND)","0-2 kg / 0-5 lb package(2ND DAY)","0-2 kg / 0-5 lb package(NEX DAY)","0-2 kg / 0-5 lb package(PRIORITY EXPRESS)",
"2 - 5 kg / 5 - 12 lb(GROUND)","2 - 5 kg / 5 - 12 lb(2ND DAY)","2 - 5 kg / 5 - 12 lb(NEXT DAY)","2 - 5 kg / 5 - 12 lb(PRIORITY EXPRESS)","5 - 10 kg / 12 - 22 lb(GROUND)","5 - 10 kg / 12 - 22 lb(2ND DAY)","5 - 10 kg / 12 - 22 lb(NEXT DAY)","5 - 10 kg / 12 - 22 lb(PRIORITY EXPRESS)",
"More than 10 kg / 22 lb(GROUND)","More than 10 kg / 22 lb(2ND DAY)","More than 10 kg / 22 lb(NEXT DAY)","More than 10 kg / 22 lb(PRIORITY EXPRESS)");

$prices_array = array();

$prices_array["Envelope(GROUND)"]="n/a";
$prices_array["Envelope(2ND DAY)"]="10.00 ";
$prices_array["Envelope(NEXT DAY)"]="10.00 ";
$prices_array["Envelope(PRIORITY EXPRESS)"]="20.00";

$prices_array["0-2 kg / 0-5 lb package(GROUND)"]="10.00";
$prices_array["0-2 kg / 0-5 lb package(2ND DAY)"]="10.00 ";
$prices_array["0-2 kg / 0-5 lb package(NEXT DAY)"]="20.00 ";
$prices_array["0-2 kg / 0-5 lb package(PRIORITY EXPRESS)"]="35.00";

$prices_array["2 - 5 kg / 5 - 12 lb(GROUND)"]="10";
$prices_array["2 - 5 kg / 5 - 12 lb(2ND DAY)"]="20";
$prices_array["2 - 5 kg / 5 - 12 lb(NEXT DAY)"]="35";
$prices_array["2 - 5 kg / 5 - 12 lb(PRIORITY EXPRESS)"]="45";

$prices_array["5 - 10 kg / 12 - 22 lb(GROUND)"]="10.00";
$prices_array["5 - 10 kg / 12 - 22 lb(2ND DAY)"]="40.00 ";
$prices_array["5 - 10 kg / 12 - 22 lb(NEXT DAY)"]="50.00 ";
$prices_array["5 - 10 kg / 12 - 22 lb(PRIORITY EXPRESS)"]="60.00";

$prices_array["More than 10 kg / 22 lb(GROUND)"]="15";
$prices_array["More than 10 kg / 22 lb(2ND DAY)"]="60";
$prices_array["More than 10 kg / 22 lb(NEXT DAY)"]="70";
$prices_array["More than 10 kg / 22 lb(PRIORITY EXPRESS)"]="90";


?>

<HTML>
<HEAD>
<meta http-equiv="content-type" content="text/html; charset=ISO-8859-1">
<TITLE>BW Cabinet</TITLE>

<LINK href="css/Level1_Arial.css" rel="stylesheet" type="text/css">
<LINK href="css/style.css" rel="stylesheet" type="text/css">
<SCRIPT LANGUAGE="JavaScript" src="scripts/scriptLib.js"></SCRIPT>


</HEAD>

<body
	onload="MM_preloadImages('img/menu_about_ol.gif','img/menu_prices_ol.gif','img/menu_faq_ol.gif','img/button_sign_out_ol.gif')"
	bgcolor="#7b4c32">
<table class="tableMain" border="0" cellpadding="0" cellspacing="0"
	width="100%">
	<tr>
		<td align="center" valign="top"><?php 
		if (isset($_GET['pg']) && $_GET['pg'] != "")
		{
			$head_param = $_GET['pg'];
			
			if (file_exists('inc/head_'.$head_param.'.inc'))
			{
				@include ('inc/head_'.$head_param.'.inc');
			}
			elseif (!file_exists('inc/head_'.$head_param.'.inc'))
			{
				@include ('inc/head_about.inc');
			}
		}
		else
		{
			@include ('inc/head_about.inc');
		}
		
		
		@include("inc/mainmenu.inc");?> <img src="img/1px_dummie.gif"
			width="1" height="55">
		<table width="100%" height="100%" border="0" cellpadding="0"
			cellspacing="0">
			<tr>

			<?php if (!isset($_GET['pg']) && $_GET['pg'] == "")
			{
				@include ('inc/side_about.inc');
			}
			else{
				$side_param=$_GET['pg'];
				if (file_exists('inc/side_'.$side_param.'.inc'))
				{
					@include ('inc/side_'.$side_param.'.inc');
				}
				elseif (!file_exists('inc/side_'.$side_param.'.inc'))
				{
					@include ('inc/side_about.inc');
				}
			}
			
			
			?>
				<td align="left" valign="top"><?php
				$my = new class_dbaseutils();
				$my->sql_connect();


					
				$err_buff = $my->sql_err;
				$exec_error = trim($err_buff);
					
				if($exec_error!="0")
				{
					$pg="error";
					$err_content = $exec_error;
					@include ('inc/'.$pg.'.inc');
				}
				else
				{

					//get profile
					$profile = $my->get_profile($_SESSION["login"]);
					
					if(trim($my->sql_err)!="0")
					{
						header("location: ../?pg=error&&err_details=$my->sql_err");//excessive
					}
					else
					{
						if($profile[8]==1)$checked='checked="checked"';
						$email_param = $profile['username'];
					}


					//set include file
					if (isset($_GET['pg']) && $_GET['pg'] != "")
					{
						$pg = $_GET['pg'];
						if (file_exists('inc/'.$pg.'.inc'))
						{
							@include ('inc/'.$pg.'.inc');
						}
						elseif (!file_exists('inc/'.$pg.'.inc'))
						{
							echo 'Page you are requesting doesn´t exist';
						}
					}
					else
					{
						@include ('inc/about.inc');
					}

				}
				?> <?php include("inc/dummy.inc"); ?></td>
				<td align="center" valign="top" width="35%"><?php include("inc/mycabinet.inc");?>

				</td>
			</tr>

		</table>
		</td>
	</tr>
</table>
</body>
</html>
