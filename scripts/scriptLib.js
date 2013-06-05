
function MM_swapImgRestore() { //v3.0
  var i,x,a=document.MM_sr; for(i=0;a&&i<a.length&&(x=a[i])&&x.oSrc;i++) x.src=x.oSrc;
}
function MM_preloadImages() { //v3.0
  var d=document; if(d.images){ if(!d.MM_p) d.MM_p=new Array();
    var i,j=d.MM_p.length,a=MM_preloadImages.arguments; for(i=0; i<a.length; i++)
    if (a[i].indexOf("#")!=0){ d.MM_p[j]=new Image; d.MM_p[j++].src=a[i];}}
}

function MM_findObj(n, d) { //v4.01
  var p,i,x;  if(!d) d=document; if((p=n.indexOf("?"))>0&&parent.frames.length) {
    d=parent.frames[n.substring(p+1)].document; n=n.substring(0,p);}
  if(!(x=d[n])&&d.all) x=d.all[n]; for (i=0;!x&&i<d.forms.length;i++) x=d.forms[i][n];
  for(i=0;!x&&d.layers&&i<d.layers.length;i++) x=MM_findObj(n,d.layers[i].document);
  if(!x && d.getElementById) x=d.getElementById(n); return x;
}

function MM_swapImage() { //v3.0
  var i,j=0,x,a=MM_swapImage.arguments; document.MM_sr=new Array; for(i=0;i<(a.length-2);i+=3)
   if ((x=MM_findObj(a[i]))!=null){document.MM_sr[j++]=x; if(!x.oSrc) x.oSrc=x.src; x.src=a[i+2];}
}


function validate_required(field)
{
 with (field)
 {

 if (value==null||trim(value)=="")
  {
  	field.style.backgroundColor='yellow';
  	return false;
  }
  else
  {
  return true
  }
 }
}


function validate_form(thisform)
{
	flag = true;
with (thisform)
{
if (validate_required(contact_person_name)==false)
  { flag = false;}
if (validate_required(street1)==false)
  { flag = false;}

if (validate_required(city)==false)
  { flag = false;}
if (validate_required(zip)==false)
  { flag = false;}
if(!isValidEmail())
   { flag = false;}
if(!radio_button_pickup_cheker())
   { flag = false;}
if(!radio_button_international_cheker())
   { flag = false;}
if(!validate_phoneNum1(phone))
	{flag = false;}
if(!validate_nonreq_phoneNum1(cell_phone))
	{flag = false;}
if(!validate_nonreq_phoneNum1(fax))
	{flag = false;}
}
return flag;
}

function validate_profile_form(thisform)
{
	flag = true;
with (thisform)
{
if (validate_required(prfl_contact_person_name)==false)
  { flag = false;}
if (validate_required(prfl_street1)==false)
  { flag = false;}
if (validate_required(prfl_city)==false)
  { flag = false;}
if (validate_required(prfl_zip)==false)
  { flag = false;}
if(!validate_nonreq_phoneNum1(prfl_phone))
	{flag = false;}
if(!validate_nonreq_phoneNum1(prfl_cell_phone))
	{flag = false;}
if(!validate_nonreq_phoneNum1(prfl_fax))
	{flag = false;}
}
return flag;
}

function validate_gcheckout_form(thisform)
{
 flag=true;
 with (thisform)
	{
		if(!ValidateAmount(google_money))
		return false;
	}
}
 function provideAmount(field)
 {
 	with(field)
 	{
 		document.gchek_form.item_price_1.value = value;
 	}
 }


function validate_password_form(thisform)
{
	flag = true;
with (thisform)
{
if(!validateEditedPass(prfl_old_pass))
	{flag = false;}
if(!validateEditedPass(prfl_new_pass))
	{flag = false;}
if(!validateEditedPass(prfl_new_pass_confirm))
	{flag = false;}
}
return flag;
}

function validateEditedPass(field)
{
 with (field)
 {

 if (value==null||trim(value)==""||value.length<8)
  {
  	field.style.backgroundColor='yellow';
  	return false;
  }
  else
  {
  return true
  }
 }
}



function radio_button_pickup_cheker()
{

	if(!document.reg_form.pickup_route[0].checked&!document.reg_form.pickup_route[1].checked)
	{
		return false;
	}
	else
	{

		return true;
	}
}
function radio_button_international_cheker()
{

	if(!document.reg_form.international[0].checked&!document.reg_form.international[1].checked)
	{

		return false;
	}
	else
	{

		return true;
	}
}

function validate_shipment_form(thisform)
{
	flag = true;
with (thisform)
{
if (validate_required(oneshp_company_name)==false)
  { flag = false;}
if (validate_required(oneshp_contact_person_name)==false)
  { flag = false;}
if (validate_required(oneshp_street1)==false)
  { flag = false;}
if (validate_required(oneshp_city)==false)
  { flag = false;}
if(!validate_phoneNum1(oneshp_phone))
	{flag = false;}
if (validate_required(oneshp_zip)==false)
  { flag = false;}
if (validate_required(oneshp_weight)==false)
  { flag = false;}
if (validate_required(oneshp_value)==false)
  { flag = false;}
}
return flag;
}


function isValidEmail(){
  validRegExp = /^[^@]+@[^@]+.[a-z]{2,}$/i;
  strEmail = document.reg_form.email.value;
  if (strEmail.search(validRegExp) == -1)
   {
     document.reg_form.email.style.backgroundColor='yellow';
        return false;
   }
   return true;
}



function validate_phoneNum1(field)
{

with (field)
 {
 	if (value==null||trim(value)=="")
  	{
  		field.style.backgroundColor='yellow';
  		return false;
  	}
 	else
 	{
 		phoneNumm = value;

		firstSymbol = phoneNumm.substring(0,1);
		if(firstSymbol==' '|firstSymbol=='-')
		{
			field.style.backgroundColor='yellow';
  			return false;
		}
		else
		if ((parseInt(phoneNumm) != phoneNumm)) {

			field.style.backgroundColor='yellow';
  			return false;
		}
		else
		{
			return true;
		}
  }
}
}

function ValidateAmount(field)
{
with (field)
 {
 		if (value==null||trim(value)=="")
  		{
  			field.style.backgroundColor='yellow';
  			return false;
  		}
  		else
  		{
  			if(isNaN(value))
  			{
  			 field.style.backgroundColor='yellow';
  			 return false;
  			}
  			else
  			{
  				subValue = trim(value);
  				firstSymbol = subValue.substring(0,1);

  				if(firstSymbol=='+'||firstSymbol=='-')
  				{
  					field.style.backgroundColor='yellow';
  			 		return false;
  				}
  				else
  				{
  					if(subValue<=0||subValue.length>13)
  					{
  					field.style.backgroundColor='yellow';
  			 		return false;
  					}
  					else
  					{
  					numValue = (parseFloat(subValue)).toFixed(2).replace(',', '.');

  					document.gchek_form.item_price_1.value=numValue;
  					return true;
					}
  				}
  			}

  		}

 }
}


function validate_nonreq_phoneNum1(field)
{

with (field)
 {

 		phoneNumm = value;
 		if(trim(phoneNumm)=='')
 		{
 			return true;
 		}
		else{
		firstSymbol = phoneNumm.substring(0,1);
		if(firstSymbol==' '|firstSymbol=='-')
		{
			field.style.backgroundColor='yellow';
  			return false;
		}
		else
		if ((parseInt(phoneNumm) != phoneNumm)) {

			field.style.backgroundColor='yellow';
  			return false;
		}
		else
		{
			return true;
		}
  	}
  }
}






function validate_phoneNum(field)
{

 with (field)
 {
 	if (value==null||trim(value)=="")
  {
  	field.style.backgroundColor='yellow';
  	return false;
  }
 	else
 	{
 	phoneNumm = value;

 	firstSymbol = phoneNumm.substring(0,1);
 	 if(firstSymbol=='+'){
 	  lastIndex = phoneNumm.lastIndexOf('+');
 	    if(lastIndex<=0){
  	       subNum = phoneNumm.substring(lastIndex+1,phoneNumm.length);
 	        if(!isNaN(subNum)&subNum.length<=10)
 	        {
 	        	return true;
 	        }
 	    }
 	  }
 	  else
 	  {
 	  	if(phoneNumm.lastIndexOf('-')<0&!isNaN(trim(phoneNumm))&phoneNumm.length<=10)
 	  	return true;
 	  	else
 	  	{
 	  		field.style.backgroundColor='yellow';
  	  		return false;
 	  	}
 	  }
 	}
  }
}

function validate_nonreq_phoneNum(field)
{

 with (field)
 {
 	phoneNumm = value;

 	firstSymbol = phoneNumm.substring(0,1);
 	 if(firstSymbol=='+'){
 	  lastIndex = phoneNumm.lastIndexOf('+');
 	    if(lastIndex<=0){
  	       subNum = phoneNumm.substring(lastIndex+1,phoneNumm.length);
 	        if(!isNaN(subNum)&subNum.length<=10)
 	        {
 	        	return true;
 	        }
 	    }
 	  }
 	  else
 	  {
 	  	if(phoneNumm.lastIndexOf('-')<0&!isNaN(trim(phoneNumm))&phoneNumm.length<=10)
 	  	return true;
 	  	else
 	  	{
 	  		field.style.backgroundColor='yellow';
  	  		alert("num not ok or minus ees false");
 	  		return false;
 	  	}
 	  }
   }
}



function trim(str)
{
	return str.split(' ').join('');
}



function isValidShipmentEmail(){
  validRegExp = /^[^@]+@[^@]+.[a-z]{2,}$/i;
  strEmail = document.oneshp_form.oneshp_email.value;
  if (strEmail.search(validRegExp) == -1)
   {
     document.oneshp_form.oneshp_email.style.backgroundColor='yellow';
        return false;
   }
   return true;
}
