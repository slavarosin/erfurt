
<table width="245" height="300" border="0" cellpadding="0"
	cellspacing="0">
	<tr>
		<td align="left" valign="top"
			class="tdLoginAndCabinetShadow">
		<form name="logincheck" action="scripts/login.php" method="post">
		<table width="231" height="273" border="0" cellpadding="0"
			cellspacing="0">
			<tr>
				<td height="203" align="center" valign="middle"
					class="tdLoginRegisterShape">
				<input type="text" name="login" id="textfield" size="25"> <br>
				<br>
				<input type="password" name="password" id="textfield2" size="25"> <br>
				<br>
				<?php print'<input type="hidden" name="head_picture" value="'.$_GET['tmpl'].'">'; ?>
				<button name="button" class="imageButton" type="submit"
					onMouseOut="MM_swapImgRestore()"
					onMouseOver="MM_swapImage('enter_ol','','img/button_enter_ol.gif',1)"><img
					src="img/button_enter.gif" alt="enter" name="enter_ol" width="109"
					height="31" border="0"></button>
				<span class="smallText"><br>
				<a href="?pg=nologin">Forgot your
				password?</a> </span></td>
			</tr>
			<tr>
				<td height="70" align="center" valign="top"><a
					href="?pg=register"
					onMouseOut="MM_swapImgRestore()"
					onMouseOver="MM_swapImage('register_button','','img/button_register_ol.gif',1)"><img
					src="img/button_register.gif" alt="register" name="register_button"
					width="231" height="70" border="0"></a></td>
			</tr>
		</table>
		</form>
		<br>
		<img src="img/logo_chekout.gif" width="231" height="75"
			alt="google chekout"></td>
	</tr>
</table>
