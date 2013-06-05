<?php $menu_pic=$_GET['pg']; ?>
<table width="100%" height="29" border="0" cellpadding="0" cellspacing="0" background="img/bg_menu.png">
      <tr>
        <td height="29" width="10%">&nbsp;</td>
        <td width="2"><img src="img/menu_separator.gif" width="2" height="21"></td>
        <td width="195"><a href="?pg=about" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('about','','img/menu_about_ol.gif',1)"><img src="<? if ($menu_pic=='about')  print 'img/menu_about_ol.gif';  else  print 'img/menu_about.gif';?>" alt="about us" name="about" width="195" height="29" border="0"></a></td>
        <td width="2"><img src="img/menu_separator.gif" width="2" height="21"></td>
        <td width="176"><a href="?pg=prices" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('prices','','img/menu_prices_ol.gif',1)"><img src="<? if ($menu_pic=='prices')  print 'img/menu_prices_ol.gif';  else  print 'img/menu_prices.gif';?>" alt="prices" name="prices" width="176" height="29" border="0"></a></td>
        <td width="2"><img src="img/menu_separator.gif" width="2" height="21"></td>
        <td width="134"><a href="?pg=faq" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('faq','','img/menu_faq_ol.gif',1)"><img src="<? if ($menu_pic=='faq') print 'img/menu_faq_ol.gif'; else print 'img/menu_faq.gif';?>" alt="FAQ" name="faq" width="134" height="29" border="0"></a></td>
        <td width="2"><img src="img/menu_separator.gif" width="2" height="21"></td>
        <td width="182"><a href="?pg=contact" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('contact','','img/menu_contacts_ol.gif',1)"><img src="<? if ($menu_pic=='contact') print 'img/menu_contacts_ol.gif'; else print 'img/menu_contacts.gif';?>" alt="contact" name="contact" width="182" height="29" border="0"></a></td>
        <td width="2"><img src="img/menu_separator.gif" width="2" height="21"></td>
        <td width="55%"></td>
      </tr>
    </table>