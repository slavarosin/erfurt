
<table>
	<tr>
		<td class="register">Login:</td>
		<td class="register"><?php session_start(); echo $_SESSION["login"] ?></td>
	</tr>
	<tr>
		<td class="register">Password:</td>
		<td class="register"><?php echo $_SESSION["passwd"] ?></td>
	</tr>
	<tr>
		<td colspan="2" class="register">Thank you! Your password has been sent to: <?php echo $_SESSION["login"]; ?></td>
	</tr>
</table>
<?php
session_unregister("login");
session_unregister("passwd");
session_destroy();
?>
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
