<form name="reg_form" action="scripts/register.php" method="post"
	onsubmit="return validate_form(this)">
<table>
	<tr>
		<td width="150" class="register">Company Name:</td>
		<td></td>
		<td><input type="text" class="registrationContent" name="company_name"
			maxlength="64"></td>
	</tr>
	<tr>
		<td width="150" class="register">Contact person name:</td>
		<td><font class="yellow">*</font></td>
		<td><input type="text" class="registrationContent"
			name="contact_person_name" maxlength="64"></td>
	</tr>
	<tr>
		<td width="150" class="register">Position:</td>
		<td></td>
		<td><input type="text" class="registrationContent"
			name="contact_person_position" maxlength="64"></td>
	</tr>
	<tr>
		<td width="150" class="register">Street 1:</td>
		<td><font class="yellow">*</font></td>
		<td><input type="text" class="registrationContent" name="street1"
			maxlength="45"></td>
	</tr>
	<tr>
		<td width="150" class="register">Street 2:</td>
		<td><font class="yellow"></font></td>
		<td><input type="text" class="registrationContent" name="street2"
			maxlength="45"></td>
	</tr>
	<tr>
		<td width="150" class="register">City:</td>
		<td><font class="yellow">*</font></td>
		<td><input type="text" class="registrationContent" name="city"
			maxlength="45"></td>
	</tr>
	<tr>
		<td width="150" class="register">State:</td>
		<td><font class="yellow">*</font></td>
		<td><select name="state" class="stateSelect">
		<?php
		foreach($state_array as $value)
		{
			print '<option value="'.$value.'">'.$value.'</option>';
		}
		?>
		</select></td>
	</tr>
	<tr>
		<td width="150" class="register">Zip:</td>
		<td><font class="yellow">*</font></td>
		<td><input type="text" class="registrationContent" name="zip" maxlength="5"></td>
	</tr>
	<tr>
		<td width="150" class="register">Email:</td>
		<td><font class="yellow">*</font></td>
		<td><input type="text" class="registrationContent" name="email"
			maxlength="45"></td>
	</tr>
	<tr>
		<td width="150" class="register">Referal Email:</td>
		<td><font class="yellow"></font></td>
		<td><input type="text" class="registrationContent" name="ref_email"
			maxlength="45"></td>
	</tr>
	<tr>
		<td width="150" class="register">Main phone:</td>
		<td><font class="yellow">*</font></td>
		<td><input type="text" class="registrationContent" name="phone"
			maxlength="11"></td>
	</tr>
	<tr>
		<td width="150" class="register">Cell phone:</td>
		<td><font class="yellow"></font></td>
		<td><input type="text" class="registrationContent" name="cell_phone"
			maxlength="11"></td>
	</tr>
	<tr>
		<td width="150" class="register">Fax:</td>
		<td><font class="yellow"></font></td>
		<td><input type="text" class="registrationContent" name="fax"
			maxlength="11"> <?php print'<input type="hidden" name="head_picture" value="'.$_GET['tmpl'].'">'; ?>
		</td>
	</tr>
	<tr>
		<td width="150" class="register">Carrier:</td>
		<td></td>
		<td><select name="carrier" class="stateSelect">
		<?php
		$array = $my->get_carrier();
		foreach($array as $value)
		{
			echo '<option>'.$value[1].'</option>';
		}
		?>
		</select></td>
	</tr>
	<tr>
		<td width="150" class="register">Expenses: How much do you currently
		spend for shipping (please estimate)?</td>
		<td></td>
		<td><input type="text" name="expenses"
			maxlength="64">&nbsp;<span class="register"><select
			name="expences_time_span">
			<?php
			foreach($period_array as $period)
			{
				echo '<option>'.$period.'</option>';
			}
			?>
		</select>&nbsp;USD</span></td>
	</tr>
	<tr>
		<td width="150" class="register">Amount: How many items do you ship?</td>
		<td></td>
		<td valign="middle"><input type="text" name="amount" maxlength="64">&nbsp;<select
			name="time_span">
			<?php
			foreach($period_array as $period)
			{
				echo '<option>'.$period.'</option>';
			}
			?>
		</select></td>
	</tr>
	<tr>
		<td width="150" class="register">Pickup Route: Are you currently on
		the daily pick up route?</td>
		<td><font class="yellow">*</font></td>
		<td><font class="register">Yes</font><input type="radio"
			name="pickup_route" value="yes" />&nbsp;&nbsp; <font class="register">No</font><input
			type="radio" name="pickup_route" value="no" /></td>
	</tr>
	<tr>
		<td width="150" class="register">Do you currently ship
		internationally?</td>
		<td><font class="yellow">*</font></td>
		<td><font class="register">Yes</font><input type="radio"
			name="international" value="yes" />&nbsp;&nbsp; <font
			class="register">No</font><input type="radio" name="international"
			value="no" /></td>
	</tr>
	<tr>

		<td colspan="3" align="center"><FONT class="yellow"><br>
		Please note, that fields marked with (*) are required<br>
		<br>
		</FONT></td>
	</tr>
	<tr>
		<td colspan="3" align="center">
		<button name="registrationSubmit" class="imageButton" type="submit"
			onMouseOut="MM_swapImgRestore()"
			onMouseOver="MM_swapImage('submit_butt','','img/button_submit_ol.gif',1)"
			><img src="img/button_submit.gif"
			alt="submit registration" name="submit_butt" width="109" height="31"
			></button>
		</td>
	</tr>
</table>
</form>
