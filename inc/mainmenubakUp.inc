<table background="img/bg_menu.png" border="0" cellpadding="0"
	cellspacing="0" width="100%" height="29">
	<tbody>
		<tr>
		<?php $menu_pic=$_GET['pg']; ?>
			<td width="10%" height="29">&nbsp;</td>
			<td width="2"><img src="img/menu_separator.gif" width="2" height="21"></td>
			<td width="195"><a href="?tmpl=city&&pg=about"
				onmouseout="MM_swapImgRestore()"
				onmouseover="MM_swapImage('about','','img/menu_about_ol.gif',1)"><?php 
				if($menu_pic=='about')
				echo '<img
				src="img/menu_about_ol.gif" alt="about us" name="about" border="0"
				width="195" height="29">';
				else
				echo'<img
				src="img/menu_about.gif" alt="about us" name="about" border="0"
				width="195" height="29">';?></a></td>
			<td width="2"><img src="img/menu_separator.gif" width="2" height="21"></td>
			<td width="176"><a href="?tmpl=sky&&pg=prices
				"
				onmouseout="MM_swapImgRestore()"
				onmouseover="MM_swapImage('prices','','img/menu_prices_ol.gif',1)"><?php 
				if($menu_pic=='prices')
				echo '<img
				src="img/menu_prices_ol.gif" alt="about us" name="about" border="0"
				width="176" height="29">';
				else
				echo'<img
				src="img/menu_prices.gif" alt="prices" name="prices" border="0"
				width="176" height="29">';?></a></td>
			<td width="2"><img src="img/menu_separator.gif" width="2" height="21"></td>
			<td width="134"><a href="?tmpl=question&&pg=faq"
				onmouseout="MM_swapImgRestore()"
				onmouseover="MM_swapImage('faq','','img/menu_faq_ol.gif',1)"><?php 
				if($menu_pic=='faq')
				echo '<img
				src="img/menu_faq_ol.gif" alt="about us" name="about" border="0"
				width="134" height="29">';
				else
				echo'<img
				src="img/menu_faq.gif" alt="FAQ" name="faq" border="0" width="134"
				height="29">';?></a></td>
			<td width="2"><img src="img/menu_separator.gif" width="2" height="21"></td>
			<td width="182"><a href="?tmpl=phone&&pg=contact"
				onmouseout="MM_swapImgRestore()"
				onmouseover="MM_swapImage('contact','','img/menu_contacts_ol.gif',1)"><?php 
				if($menu_pic=='contact')
				echo '<img
				src="img/menu_contacts_ol.gif" alt="about us" name="about" border="0"
				width="182" height="29">';
				else
				echo'<img
				src="img/menu_contacts.gif" alt="contact" name="contact" border="0"
				width="182" height="29">';?></a></td>

			<td width="2"><img src="img/menu_separator.gif" width="2" height="21"></td>
			<td width="55%"></td>
		</tr>
	</tbody>
</table>
