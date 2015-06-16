
<?php $transContent = $my->get_trans_total($_SESSION['login']);

$transEntities = $my->get_trans_sums($_SESSION['login']);

if($transContent['sum(sum)']==0)
$amount_buff = '0.00';
else $amount_buff = $transContent['sum(sum)'];
?>

<table border="0" cellpadding="1" cellspacing="1" width="300">
	<tbody>

		<tr class="pricesTable_Content">
			<td bgcolor="#ffffff" align="left" class="pricesTable_Header"
				colspan="2"><span class=""><?php print 'Total amount: '.$amount_buff.' USD';  ?></span></td>
		</tr>

		<tr class="pricesTable_Header">
			<td align="center" bgcolor="#ffffff" valign="middle"><span class="">Transaction
			Description</span></td>
			<td align="center" bgcolor="#ffffff" valign="middle"><span class="">Amount</span></td>

		</tr>

		<?php foreach($transEntities as $value)
		{
			print '<tr class="pricesTable_Content">
			<td align="center" bgcolor="#ffffff" valign="middle" ><span class="">'.$value['comment'].'</span></td>
			<td align="center" bgcolor="#ffffff" valign="middle" ><span class="">'.$value['sum'].' USD</span></td>
		</tr>';
		}?>
	</tbody>
</table>

		<?php
		echo '<font class="register">&nbsp;</font>';
		@include("dummy.inc"); ?>
		<?php @include("dummy.inc"); ?>
