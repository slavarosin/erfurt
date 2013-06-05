<?php
	$merchantId = "266866879738174";
	$itemName = "Shipping Service";
	$itemDesc = "Good shipping Service";
	// $price = "1.00";
?>

<br><br>

<form method="POST" action="https://checkout.google.com/api/checkout/v2/checkoutForm/Merchant/<?php echo $merchantId;?>"
	onsubmit="return validate_gcheckout_form(this);"
	name="gchek_form">
  <input type="text" name="google_money" width="180" class="gchkout" onchange="provideAmount(this)"/><br><br>
  <input type="hidden" name="item_name_1" value="<?php echo $itemName;?>"/>
  <input type="hidden" name="item_description_1" value="<?php echo $itemDesc;?>"/>
  <input type="hidden" name="item_price_1" value="<?php echo $price;?>"/>
  <input type="hidden" name="item_currency_1" value="GBP"/>
  <input type="hidden" name="item_quantity_1" value="1"/>

  <input type="hidden"
    name="shopping-cart.items.item-1.digital-content.display-disposition"
    value="OPTIMISTIC"/>
  <input type="hidden"
    name="shopping-cart.items.item-1.digital-content.email-delivery" value="true"/>
  <input type="hidden"
    name="checkout-flow-support.merchant-checkout-flow-support.continue-shopping-url"
    value="http://neadekvat.uuuq.com/confirm.php"/>

  <input type="hidden" name="_charset_"/>

  <!-- Button code -->
  <input type="image"
    name="Google Checkout"
    alt="Fast checkout through Google"
    src="http://checkout.google.com/buttons/checkout.gif?merchant_id=<?php echo $merchantId;?>&w=180&h=46&style=white&variant=text&loc=en_US"
    height="46"
    width="180"/>
</form>

<?php

//todo: $_GET['price'] is needed!;
if(isset($_GET['bbls'])&&$_GET['bbls']!=""&&$_GET['bbls']>0)
{
$myTransactionAmount = $_GET['bbls'];
$transAmount = $myTransactionAmount/1;
$my->charge_account($_SESSION['login'], $transAmount);
	if(isset($profile['referal_id'])&&$profile['referal_id']!=0&&$myTransactionAmount!=0)
	{
		$ref_amount = $myTransactionAmount/10;
		$my->make_referal_charge($profile['referal_id'], $ref_amount);
	}
}
?>
<?php @include("dummy.inc"); ?>