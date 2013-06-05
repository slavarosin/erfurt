<form name="oneshp_form" action="scripts/makeshipment.php" method="post"
	onsubmit="return validate_shipment_form(this)">
<table >
	<tr>
		<td colspan="3" class="mainTextWhite"><?php if(isset($_GET['outofM'])) print 'Your accaunt does not contain enough money  for this service type.'; 
		else print 'You can fill shipment form here'; ?></td>
	</tr>

	<tr>
		<td width="150"  class="register">Company Name:</td>
		<td class="yellow">*</td>
		<td><input type="text" class="registrationContent"
			name="oneshp_company_name" maxlength="64"></td>
	</tr>
	<tr>
		<td width="150"  class="register">Contact person name:</td>
		<td class="yellow">*</td>
		<td><input type="text" class="registrationContent"
			name="oneshp_contact_person_name" maxlength="64"></td>
	</tr>
	<tr>
		<td width="150"  class="register">Position:</td>
		<td></td>
		<td><input type="text" class="registrationContent"
			name="oneshp_contact_person_position" maxlength="64"></td>
	</tr>
	<tr>
		<td width="150"  class="register">Street 1:</td>
		<td class="yellow">*</td>
		<td><input type="text" class="registrationContent" name="oneshp_street1"
			maxlength="45"></td>
	</tr>
	<tr>
		<td width="150"  class="register">Street 2:</td>
		<td class="yellow"></td>
		<td><input type="text" class="registrationContent" name="oneshp_street2"
			maxlength="45"></td>
	</tr>
	<tr>
		<td width="150"  class="register">City:</td>
		<td class="yellow">*</td>
		<td><input type="text" class="registrationContent" name="oneshp_city"
			maxlength="45"></td>
	</tr>
	<tr>
		<td width="150"  class="register">State:</td>
		<td class="yellow">*</td>
		<td><select name="oneshp_state" class="stateSelect">
		<?php
		foreach($state_array as $value)
		{
		 echo '<option value="'.$value.'">'.$value.'</option>';
		}
		?>
		</select></td>
	</tr>
	<tr>
		<td width="150"  class="register">Zip:</td>
		<td class="yellow">*</td>
		<td><input type="text" class="registrationContent" name="oneshp_zip"
			maxlength="5"></td>
	</tr>
	<tr>
		<td width="150"  class="register">Main phone:</td>
		<td class="yellow">*</td>
		<td><input type="text" class="registrationContent" name="oneshp_phone" maxlength="11"></td>
	</tr>
	<tr>
		<td width="150"  class="register">Carrier:</td>
		<td></td>
		<td><select name="oneshp_carrier" class="stateSelect">
		<?php
		echo '<option>'.$profile['carrier'].'</option>';
		/*$array = $my->get_carrier();

		foreach($array as $value)
		{
			if($value[1]!=$profile['carrier'])
			echo '<option>'.$value[1].'</option>';
		}*/
		?>
		</select></td>
	</tr>
	<tr>
		<td width="150"  class="register">Item description:</td>
		<td></td>
		<td><input type="text" class="registrationContent"
			name="oneshp_description" maxlength="64"></td>
	</tr>
	<tr>
		<td width="150"  class="register">Weight</td>
		<td class="yellow">*</td>
		<td valign="middle"><input type="text" name="oneshp_weight" maxlength="64">&nbsp;<select
			name="weight_span">
			<?php
			foreach($weight_array as $period)
			{
				echo '<option>'.$period.'</option>';
			}
			?>
		</select></td>
	</tr>
	<tr>
		<td width="150"  class="register">Value </td>
		<td class="yellow">*</td>
		<td><input type="text" name="oneshp_value" maxlength="64"><span class="register">&nbsp;USD</span></td>
	</tr>
	<tr>
		<td width="150"  class="register">Type of service:</td>
		<td></td>
		<td><select name="oneshp_servicetype">
			<?php
		
		foreach($servises_array as $value)
		{
			echo '<option>'.$value.'</option>';
		}
		?>
		</select></td>
	</tr>

	<tr>

		<td colspan="3" align="center"><FONT class="yellow"><br>
		Please note, that fields marked with (*) are required<br>
		<br>
		</FONT></td>
	</tr>
	<tr>
		<td colspan="3" align="center"><button name="oneShipmentnSubmit" class="imageButton" type="submit"
					onMouseOut="MM_swapImgRestore()"
					onMouseOver="MM_swapImage('submit_shipment','','img/button_submit_ol.gif',1)"><img
					src="img/button_submit.gif" alt="submit shipment" name="submit_shipment" width="109"
					height="31" border="0"></button></td>
				</tr>
</table>
</form>
