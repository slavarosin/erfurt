<?php
	$merchantId = "266866879738174";
	$itemName = "Shipping Service";
	$itemDesc = "Good shipping Service";
	$price = "100.00";
	$currency = "GBP";
	$key = "irHeIWMiiovVIzX0JlG84A";

	$cart = '<?xml version="1.0" encoding="UTF-8"?><checkout-shopping-cart xmlns="http://checkout.google.com/schema/2"><shopping-cart><items>'.
			'<item>'.
        	'<item-name>'.$itemName.'</item-name>'.
        	'<item-description>'.$itemDesc.'</item-description>'.
        	'<unit-price currency="'.$currency.'">'.$price.'</unit-price>'.
        	'<quantity>1</quantity>'.
      		'</item>'.
    		'</items></shopping-cart>';

	$blocksize = 64;
    $hashfunc = 'sha1';

    if (strlen($key) > $blocksize) {
        $key = pack('H*', $hashfunc($key));
    }

    $key = str_pad($key, $blocksize, chr(0x00));
    $ipad = str_repeat(chr(0x36), $blocksize);
    $opad = str_repeat(chr(0x5c), $blocksize);
    $hmac = pack(
                    'H*', $hashfunc(
                            ($key^$opad).pack(
                                    'H*', $hashfunc(
                                            ($key^$ipad).$cart
                                    )
                            )
                    )
                );

	$cart = base64_encode($cart);
	$signature = base64_encode($hmac);
?>

<form method="POST" action="https://checkout.google.com/api/checkout/v2/checkoutForm/Merchant/<?php echo $merchantId;?>">

   <input type="hidden" name="cart"
        value="<?php echo $cart;?>">
   <input type="hidden" name="signature"
        value="<?php echo $signature;?>">

  <!-- Button code -->
  <input type="image"
    name="Google Checkout"
    alt="Fast checkout through Google"
    src="http://checkout.google.com/buttons/checkout.gif?merchant_id=<?php echo $merchantId;?>&w=180&h=46&style=white&variant=text&loc=en_US"
    height="46"
    width="180"/>
</form>