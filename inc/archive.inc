<FORM name="SingleArchiveEntry" method="post">
<table border="0" cellpadding="1" cellspacing="1" width="100%">
	<tr>
		<td><span class="mainTextWhite">Search Shipment from Archive</span> <input
			type="text" name="archive_search_param"> <input type="submit"
			value="Search Shipment"></td>
	</tr>
</table>
</FORM>
<table border="0" cellpadding="1" cellspacing="1" width="100%">
	<tr>
		<td><?php if(isset($_POST['archive_search_param'])& trim($_POST['archive_search_param'])!="")print'<span class="HeaderWhite">Shipments found:</span>'; 
		else print'<span class="HeaderWhite">Archive Shipments</span>';
		?>
		<hr size="1" noshade class="mainTextWhite">
		</td>
	</tr>
</table>
<table border="0" cellpadding="1" cellspacing="1" width="100%">
	<tr>
		<td colspan="3"><?php
		//echo $_SESSION['additional_param'];
		$records_per_page = 10;
		$archive_count = $my->sql_count($_SESSION['additional_param']);
		//print_r ($archive_count);
		$total_recs = $archive_count[0];
		//echo $total_recs;

		$number_of_pages = $total_recs/$records_per_page;

		$number_of_extrapages = $total_recs%$records_per_page;
		if((!isset($_POST['archive_search_param'])|trim($_POST['archive_search_param'])=="")& $total_recs!=0)
		{
			echo '<span class="mainTextWhite">page :';
			for($i=1;$i<$number_of_pages+1;$i++)
			{
				if(!isset($_GET['arcpg']))
				{
					if($i==1)
					{
						echo'<a href=?&pg='.$_GET['pg'].'&arcpg='.$i.' class="mainTextBlue" >&nbsp;'.$i.'&nbsp;</a>';
					}
					else
					{
						echo'<a href=?pg='.$_GET['pg'].'&arcpg='.$i.' class="mainTextWhite" >&nbsp;'.$i.'&nbsp;</a>';
					}}
					else
					{
						if($i==$_GET['arcpg'])
						{
							echo'<a href=?&pg='.$_GET['pg'].'&arcpg='.$i.' class="mainTextBlue" >&nbsp;'.$i.'&nbsp;</a>';
						}
						else
						{
							echo'<a href=?pg='.$_GET['pg'].'&arcpg='.$i.' class="mainTextWhite" >&nbsp;'.$i.'&nbsp;</a>';
						}
					}

			}
			echo '</span>';
		}
		?></td>
	</tr>
</table>

<table border="0" cellpadding="1" cellspacing="1" width="100%" >
	<tr class="shipmetsTable_Header">
			<td align="center" valign="middle" bgcolor="#ffffff"><span class="">Date</span></td>
			<td align="center" valign="middle" bgcolor="#ffffff"><span class="">Receiver
			Company</span></td>
			<td align="center" valign="middle" bgcolor="#ffffff"><span class="">Destination</span></td>
			<td align="center" valign="middle" bgcolor="#ffffff"><span class="">Carrier</span></td>
			<td align="center" valign="middle" bgcolor="#ffffff"><span class="">Tracking</span></td>
			<td align="center" valign="middle" bgcolor="#ffffff"><span class="">Label</span></td>
			<td><span class="">&nbsp;</span></td>
		</tr>

		<?php
		$search_param = $_POST["archive_search_param"];
		//if(trim($search_param)=="")$search_param="+";
		
		if(isset($_POST["archive_search_param"])&trim($search_param)!=""){
			$needed_archive_entry = $my->get_archive_entry_by_id($_SESSION["additional_param"],$search_param, '10');

			if(trim($my->sql_err)!="0") echo $my->sql_err;

			foreach($needed_archive_entry as $arch_record)
			{
				if(trim($arch_record['company_name'])!="")
				$receiver_company_details = $arch_record['company_name'];
				else $receiver_company_details = $arch_record['contact_person_name'];

				list($month, $day, $year) =  split(" ", $arch_record['date']);
			
			if(substr($day, 0,1)==0) $archDay = substr($day, 1,1); else $archDay = $day;
			$archDate = $archDay."/".$month."/".$year;
					
				print'
		<tr>
		<td align="center" valign="middle" bgcolor="#CCCCCC"><span class="shipmetsTable">'.$archDate.'</span></td>
		<td align="center" valign="middle" bgcolor="#CCCCCC"><span class="shipmetsTable">'.$receiver_company_details.'</span></td>
		<td align="center" valign="middle" bgcolor="#CCCCCC"><span class="shipmetsTable">'.$arch_record['city'].', '.$arch_record['state'].', '.$arch_record['zip'].'</span></td>
		<td align="center" valign="middle" bgcolor="#CCCCCC"><span class="shipmetsTable"><img src="img/'.$arch_record['carrier'].'_logo.gif" width="20" height="20" alt="'.$arch_record['carrier'].'"></span></td>
		<td align="center" valign="middle" bgcolor="#CCCCCC"><span class="shipmetsTable"></td>
		<td align="center" valign="middle" bgcolor="#CCCCCC"><span class="shipmetsTable"></span></td>
		<td>&nbsp;</td>
		</tr>
		';
			}
			echo '<tr><td colspan="6"><span class="mainTextWhite"><a href="?pg=archive" class="cabinet">Back to Archive</a></span></td></tr>';

		}
		else{
			if(isset($_GET['arcpg'])&&$_GET['arcpg']!=0)
			{
				$page_num = $_GET['arcpg'];

				$off = $records_per_page * ($page_num-1);
				$lim = $records_per_page;

				$arr_off=$shipments_array = $my->get_archive_shipment($_SESSION["additional_param"],$lim, $off);
				foreach($arr_off as $vvl){

					$printout[]=$vvl;

				}
			}
			else
			{
				$arr_off=$shipments_array = $my->get_archive_shipment($_SESSION["additional_param"],$records_per_page, 0);
				foreach($arr_off as $vvl){

					$printout[]=$vvl;

				}

			}

			$shipments_array =$printout;

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
		
				<tr>
			<td align="center" valign="middle" bgcolor="#CCCCCC"><span class="shipmetsTable">'.$dateDate.'</span></td>
		<td align="center" valign="middle" bgcolor="#CCCCCC"><span class="shipmetsTable">'.$receiver_company_details.'</span></td>
		<td align="center" valign="middle" bgcolor="#CCCCCC"><span class="shipmetsTable">'.$value['city'].', '.$value['state'].', '.$value['zip'].'</span></td>
		<td align="center" valign="middle" bgcolor="#CCCCCC"><span class="shipmetsTable"><img src="img/'.$value['carrier'].'_logo.gif" width="20" height="20" alt="'.$value['carrier'].'"></span></td>
		<td align="center" valign="middle" bgcolor="#CCCCCC"><span class="shipmetsTable"></span></td>
		<td align="center" valign="middle" bgcolor="#CCCCCC"><span class="shipmetsTable"></span></td>
		<td>&nbsp;</td>
		</tr>
		';
			}
		}
		?>
</table>
<?php @include("dummy.inc"); ?>