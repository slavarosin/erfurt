<?php
require("req/dbaseutils.class");
$state_array = array ("AL","AK","AS","AZ","AR","CA","CO","CT","DE","DC","FM","FL","GA","GU","HI","ID","IL","IN","IA","KS","KY","LA","ME","MH","MD","MA","MI","MN","MS","MO","MT","NE","NV","NH","NJ","NM","NY","NC","ND","MP","OH","OK","OR","PW","PA","PR","RI","SC","SD","TN","TX","UT","VT","VI","VA","WA","WV","WI","WY");
$period_array = array("per day", "per week", "per month", "per year");

?>
<html>
<head>
<meta http-equiv="content-type" content="text/html; charset=ISO-8859-1">
<title>BW Shipping</title>

<link href="css/Level1_Arial.css" rel="stylesheet" type="text/css">
<LINK href="css/style.css" rel="stylesheet" type="text/css">

<SCRIPT LANGUAGE="JavaScript" src="scripts/scriptLib.js"></SCRIPT>

</head>
<body
	onload="MM_preloadImages('img/button_register_ol.gif','img/button_enter_ol.gif','img/menu_about_ol.gif','img/menu_prices_ol.gif','img/menu_faq_ol.gif')"
	bgcolor="#7b4c32">

<table class="tableMain" border="0" cellpadding="0" cellspacing="0"
	width="100%" height="100%">
	<tr>
		<td align="center" valign="top"><?php 


		echo $last_head_param;
		if (isset($_GET['pg']) && $_GET['pg'] != "")
		{
			$head_param = $_GET['pg'];

			if (file_exists('inc/head_'.$head_param.'.inc'))
			{
				@include ('inc/head_'.$head_param.'.inc');
				$last_head_param = $head_param;

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
		?> <?php @include("inc/mainmenu.inc");?> <img src="img/1px_dummie.gif"
			width="1" height="55">
		<table width="100%" height="100%" border="0" cellpadding="0"
			cellspacing="0">
			<tr>
			<?php
			if (!isset($_GET['pg']) && $_GET['pg'] == "")
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
				?> <?php include("inc/dummy.inc");?></td>
				<td align="center" valign="top" width="35%"><?php @include("inc/login.inc"); ?>
				</td>
			</tr>

		</table>
		</td>

	</tr>
</table>
</body>
</html>
