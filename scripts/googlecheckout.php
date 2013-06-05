<?php
	$merchantId = "266866879738174";
	$itemName = "Shipping Service";
	$itemDesc = "Good shipping Service";
	$price = "100.00";
?>

<form method="POST" action="https://checkout.google.com/api/checkout/v2/checkoutForm/Merchant/<?php echo $merchantId;?>">
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

  <input type="hidden" name="_charset_"/>

  <!-- Button code -->
  <input type="image"
    name="Google Checkout"
    alt="Fast checkout through Google"
    src="http://checkout.google.com/buttons/checkout.gif?merchant_id=<?php echo $merchantId;?>&w=180&h=46&style=white&variant=text&loc=en_US"
    height="46"
    width="180"/>
</form>