<form name="forgot_passwd_form" action="scripts/remindpwd.php"
	method="post" onsubmit="return validate_form(this)">
<table width="100%" border="0">
	<tr>
		<td colspan="2">
		<div class="mainTextWhite">Forgot your password?</div>
		</td>
	</tr>
	<tr>
		<td colspan="2" valign="top">
		<div class="register_left"><?php if(!isset($_GET["err_details"])) 
		echo 'Please insert your email address to the text field
		below and press the button to receive new password for your accountd';
		else
		echo 'Such user is not found';
		?></div>
		</td>
	</tr>
	<tr>
		<td width="100" class="register">Your email</td>
		<td><input type="text" maxlength="45" class="registrationContent"
			name="mail_forgotten"></td>
		<td><?php print'<input type="hidden" name="head_picture" value="'.$_GET['tmpl'].'">'; ?></td>

	</tr>
	
	<tr>
		<td colspan="3" align="center">
		<button name="newPasswordRequestSubmit" class="imageButton" type="submit"
			onMouseOut="MM_swapImgRestore()"
			onMouseOver="MM_swapImage('submit_password_request','','img/button_submit_ol.gif',1)"><img
			src="img/button_submit.gif" alt="submit registration"
			name="submit_password_request" width="109" height="31" border="0"></button>
		</td>
	</tr>
</table>
</form>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
