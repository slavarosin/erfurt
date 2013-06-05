<table width="100%" border="0">
<tr>
 <td class="registrationLabel"><div class="Header"> <?php  print 'Internal Error. Try again later';  ?> </div></td>
</tr>
<tr>
 <td class="registrationLabel"><div class="Header"> <?php if(!isset($_GET["err_details"])){print $err_content;} else {print $_GET["err_details"];} ?></div></td>
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
