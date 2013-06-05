<form name="profile_form" action="scripts/editprofile.php" method="post"
	onsubmit="return validate_profile_form(this)">
<table width="400">
	<tr>
		<td colspan="3" class="mainTextWhite"><?php if(isset($_GET['profileEditOK'])) print 'Your profile has been edited'; 
		else print 'You can edit your profile here'; ?></td>
	</tr>
	<tr>
		<td width="150"  class="register">Company Name:</td>
		<td><?php print'<input type="hidden" name="head_picture" value="'.$_GET['tmpl'].'">'; ?></td>
		<td><input type="text" class="registrationContent"
			name="prfl_company_name" maxlength="64"
			value="<?php print $profile['company_name']; ?>"></td>
	</tr>
	<tr>
		<td width="150"  class="register">Contact person name:</td>
		<td class="yellow">&nbsp;</td>
		<td><input type="text" class="registrationContent"
			name="prfl_contact_person_name" maxlength="64"
			value="<?php print $profile['contact_person_name']; ?>"></td>
	</tr>
	<tr>
		<td width="150"  class="register">Position:</td>
		<td></td>
		<td><input type="text" class="registrationContent"
			name="prfl_contact_person_position" maxlength="64"
			value="<?php print $profile['contact_person_position']; ?>"></td>
	</tr>
	<tr>
		<td width="150"  class="register">Street 1:</td>
		<td class="yellow">&nbsp;</td>
		<td><input type="text" class="registrationContent" name="prfl_street1"
			maxlength="45" value="<?php print $profile['street1']; ?>"></td>
	</tr>
	<tr>
		<td width="150"  class="register">Street 2:</td>
		<td class="yellow">&nbsp;</td>
		<td><input type="text" class="registrationContent" name="prfl_street2"
			maxlength="45" value="<?php print $profile['street2']; ?>"></td>
	</tr>
	<tr>
		<td width="150"  class="register">City:</td>
		<td class="yellow">&nbsp;</td>
		<td><input type="text" class="registrationContent" name="prfl_city"
			maxlength="45" value="<?php print $profile['city']; ?>"></td>
	</tr>
	<tr>
		<td width="150"  class="register">State:</td>
		<td class="yellow">&nbsp;</td>
		<td><select name="prfl_state" class="stateSelect" >
		<?php
		print '<option value="'.$profile['state'].'">'.$profile['state'].'</option>';
		foreach($state_array as $value)
		{
			if($value!=$profile['state'])
			print '<option value="'.$value.'">'.$value.'</option>';
		}
		?>
		</select></td>
	</tr>
	<tr>
		<td width="150"  class="register">Zip:</td>
		<td class="yellow">&nbsp;</td>
		<td><input type="text" class="registrationContent" name="prfl_zip"
			maxlength="5" value="<?php print $profile['zip']; ?>"></td>
	</tr>
	<tr>
		<td width="150"  class="register">Email:</td>
		<td class="yellow">&nbsp;</td>
		<td><input type="text" class="registrationContent" name="prfl_email"
			maxlength="45" value="<?php print $profile['email']; ?>"
			disabled="disabled"></td>
	</tr>
	<tr>
		<td width="150"  class="register">Main phone:</td>
		<td class="yellow">&nbsp;</td>
		<td><input type="text" class="registrationContent" name="prfl_phone" maxlength="11"
			value="<?php print $profile['phone']; ?>" ></td>
	</tr>
	<tr>
		<td width="150"  class="register">Cell phone:</td>
		<td class="yellow">&nbsp;</td>
		<td><input type="text" class="registrationContent"
			name="prfl_cell_phone" value="<?php print $profile['cell_phone']; ?>" maxlength="11"></td>
	</tr>
	<tr>
		<td width="150"  class="register">Fax:</td>
		<td class="yellow">&nbsp;</td>
		<td><input type="text" class="registrationContent" name="prfl_fax"
			value="<?php print $profile['fax']; ?>" maxlength="11"></td>
	</tr>
	<tr>
		<td width="150"  class="register">Carrier:</td>
		<td></td>
		<td><select name="prfl_carrier" class="stateSelect" disabled="disabled">
		<?php
		echo '<option>'.$profile['carrier'].'</option>';
		$array = $my->get_carrier();

		foreach($array as $value)
		{
			if($value[1]!=$profile['carrier'])
			echo '<option>'.$value[1].'</option>';
		}
		?>
		</select></td>
	</tr>
	<tr>
		<td width="150"  class="register">Expenses: How much do you currently
		spend for shipping (please estimate)?</td>
		<td></td>
		<td><input type="text" 	name="prfl_expenses" maxlength="64"
			value="<?php $expenses_buff=$profile['expenses'];  
			
			list($expenses_key, $expenses_value) = split(':', $expenses_buff, 2);
	 print $expenses_key;
			
			
			?>">&nbsp;<span class="register"><select name="prfl_expences_time_span">
		<?php
		echo '<option>'.$expenses_value.'</option>';
			
		foreach($period_array as $period)
		{
			if($period != $expenses_value)
			echo '<option>'.$period.'</option>';
		}
		?>
		</select>&nbsp;USD</span></td>
	</tr>
	<tr>
		<td width="150"  class="register">Amount: How many items do you ship?</td>
		<td></td>
		<td valign="middle"><input type="text" name="prfl_amount"
			maxlength="64"
			value="<?php 
		 $amount_buff=$profile['amount']; 
	   
	   
	   list($period_key, $period_value) = split(':', $amount_buff, 2);
	 print $period_key;
		
		?>">&nbsp;<select name="prfl_time_span">
		<?php
		echo '<option>'.$period_value.'</option>';
			
		foreach($period_array as $period)
		{
			if($period != $period_value)
			echo '<option>'.$period.'</option>';
		}
		?>
		</select></td>
	</tr>
	<tr>
		<td></td>
		<td></td>
		<td><?php if($profile['pickup_route']==1){$YES = 'checked="checked"';  $NO = '';}else{$YES = '';  $NO = 'checked="checked"';} ?>
		<font class="register">Yes</font><input type="radio" name="prfl_pickup_route" value="yes"
		<?php echo $YES ?> />&nbsp;&nbsp; <font class="register">No</font><input type="radio"
			name="prfl_pickup_route" value="no" <?php echo $NO; ?> /></td>
	</tr>
	<tr>
		<td width="150"  class="register">Do you currently ship internationally?</td>
		<td></td>
		<td><?php if($profile['internationally']==1){$INT_YES = 'checked="checked"';  $INT_NO = '';}else{$INT_YES = '';  $INT_NO = 'checked="checked"';} ?>
		<font class="register">Yes</font><input type="radio" name="prfl_international" value="yes"
		<?php echo $INT_YES; ?> />&nbsp;&nbsp; <font class="register">No</font><input type="radio"
			name="prfl_international" value="no" <?php echo $INT_NO; ?> /></td>
	</tr>
		<tr>
		<td colspan="3" align="center"><button name="profileEditSubmit" class="imageButton" type="submit"
					onMouseOut="MM_swapImgRestore()"
					onMouseOver="MM_swapImage('submit_profile_changes','','img/button_submit_ol.gif',1)"><img
					src="img/button_submit.gif" alt="submit registration" name="submit_profile_changes" width="109"
					height="31" border="0"></button></td>
				</tr>
</table>
</form>

<form name="prfl_pass_edit" method="post" action="scripts/changePwd.php" onsubmit="return validate_password_form(this)">
<table width="400">
	<tr>
		<td colspan="4" class="mainTextWhite"><?php if(isset($_GET['passeditOK'])) print 'Your password has been edited'; 
		else print 'You can edit your password here'; ?></td>
	</tr>
	<tr>
		<td width="150"  class="register">Old password:</td>
		<td></td>
		<td><input type="password" name="prfl_old_pass" maxlength="64"></td>
		<td width="150"><?php if(isset($_GET['opm'])) print '<span class="register">Password mismatch</span>';?></td>
	</tr>
	<tr>
		<td width="150"  class="register">New password:</td>
		<td class="yellow"></td>
		<td><input type="password" name="prfl_new_pass" maxlength="64"></td>
		<td width="150"></td>
	</tr>
	<tr>
		<td width="150"  class="register">Retype new password:</td>
		<td></td>
		<td><input type="password" 	name="prfl_new_pass_confirm" maxlength="64"></td>
		<td width="150"><?php if(isset($_GET['npm'])) print '<span class="register">Retyped password mismatch</span>';?></td>
	</tr>
<tr>
		<td colspan="4" align="center"><button name="passEditSubmit" class="imageButton" type="submit"
					onMouseOut="MM_swapImgRestore()"
					onMouseOver="MM_swapImage('submit_pass_changes','','img/button_submit_ol.gif',1)"><img
					src="img/button_submit.gif" alt="submit registration" name="submit_pass_changes" width="109"
					height="31" border="0"></button></td>
				</tr>
</table>
</form>