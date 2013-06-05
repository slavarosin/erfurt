
<span class="HeaderWhite">My Shipments</span>
<hr size="1" noshade class="mainTextWhite">
<table width="700" border="0" cellspacing="0" cellpadding="0">
	<tr>
		<td align="left" valign="middle"><a href="?pg=oneshipment"
			onMouseOut="MM_swapImgRestore()"
			onMouseOver="MM_swapImage('add_ship','','img/button_add_shipment_ol.gif',1)"><img
			src="img/button_add_shipment.gif" alt="add shipment" name="add_ship"
			width="130" height="31" border="0"></a></td>
		<td align="right" valign="middle"><a href="?pg=archive"
			onMouseOut="MM_swapImgRestore()"
			onMouseOver="MM_swapImage('archive','','img/button_view_archive_ol.gif',1)"><img
			src="img/button_view_archive.gif" alt="Veiw Archive" name="archive"
			width="130" height="31" border="0"></a></td>
	</tr>

</table>
<br>

<table border="0" cellpadding="1" cellspacing="1" width="100%">
	<tbody>
		<tr class="shipmetsTable_Header">
			<td align="center" bgcolor="#ffffff" valign="middle"><span class="">Date</span></td>
			<td align="center" valign="middle" bgcolor="#ffffff"><span class="">Receiver Company</span></td>
			<td align="center" valign="middle" bgcolor="#ffffff"><span class="">Destination</span></td>
			<td align="center" valign="middle" bgcolor="#ffffff"><span class="">Carrier</span></td>
			<td align="center" valign="middle" bgcolor="#ffffff"><span class="">Tracking</span></td>
			<td align="center" valign="middle" bgcolor="#ffffff"><span class="">Label</span></td>
			<td><span class="">&nbsp;</span></td>
		</tr>

		<?php

		$shipments_array = $my->get_shipment($_SESSION["additional_param"]);
		if(trim($my->sql_err)!="0") echo $my->sql_err;

		foreach($shipments_array as $value)
		{
			if(trim($value['company_name'])!="")
			$receiver_company_details = $value['company_name'];
			else $receiver_company_details = $value['contact_person_name'];

			list($month, $day, $year) =  split(" ", $value['date']);
			
			if(substr($day, 0,1)==0)$dateDay = substr($day, 1,1); else $dateDay = $day;
			$dateDate = $dateDay."/".$month."/".$year;
			
			print'
		<td align="center" valign="middle" bgcolor="#ffffff"><span class="shipmetsTable">'.$dateDate.'</span></td>
		<td align="center" valign="middle" bgcolor="#ffffff"><span class="shipmetsTable">'.$receiver_company_details.'</span></td>
		<td align="center" valign="middle" bgcolor="#ffffff"><span class="shipmetsTable">'.$value['city'].', '.$value['state'].', '.$value['zip'].'</span></td>
		<td align="center" valign="middle" bgcolor="#ffffff"><span class="shipmetsTable"><img src="img/'.$value['carrier'].'_logo.gif" width="20" height="20" alt="'.$value['carrier'].'"></span></td>
		<td align="center" valign="middle" bgcolor="#ffffff"><span class="shipmetsTable">'.$value['sh_id'].'</span></td>
		<td align="center" valign="middle" bgcolor="#ffffff">&nbsp;</td>
		<td valign="middle"><form name ="ArchiveShipment" method="post" action="scripts/send_to_archive.php">
		<input type="hidden" name="shipment_id" value = "'.$value['sh_id'].'">				
		<input type="submit" class="shipmetsTableSentToarchiveButton" value="Mark as Delievered">
			</form>
		</td>
		</tr>
		';
		}

		?>
	</tbody>
</table>
<br>
<table width="100%" border="0" cellspacing="0" cellpadding="0">
	<tr>
		<td align="left" valign="middle"><a href="?pg=oneshipment"
			onMouseOut="MM_swapImgRestore()"
			onMouseOver="MM_swapImage('add_ship2','','img/button_add_shipment_ol.gif',1)"><img
			src="img/button_add_shipment.gif" alt="add shipment" name="add_ship2"
			width="130" height="31" border="0"></a></td>

		<td align="right" valign="middle"><a href="?pg=archive"
			onMouseOut="MM_swapImgRestore()"
			onMouseOver="MM_swapImage('archive2','','img/button_view_archive_ol.gif',1)"><img
			src="img/button_view_archive.gif" alt="Veiw Archive" name="archive2"
			width="130" height="31" border="0"></a></td>
	</tr>
</table>

