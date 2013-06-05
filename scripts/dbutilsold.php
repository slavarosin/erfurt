<?php
//Insert_Credentials('Romannss', 'Tallinn', 'Sole', 'Paasiku', 'Estonia', 'Harjumaa', '10314', 'sierra29@hot.ee', 'DHL', '12', '0', '123', '6504943');
//Check_Credentials('Romanzz', 'PASSWD');
//Get_Profile('Roman');




function Insert_Credentials($strName,$strPassword, $strCity, $strStreet1, $strStreet2,$strCountry, $strState, $strZip, $strEmail, $strCarrier, $strExpenses, $strPickroute, $strAmount, $strPhone )
{
	$password = md5($strPassword);
	 
	$link = @mysqli_connect("localhost","root", "123", "mydb");
	if (!$link) 
	{
     	$variable1 = mysqli_connect_error();
		return 5;
		//exit();
	}
	else
	{
	$mysqli = new mysqli("localhost","root", "123");
	$mysqli->select_db("mydb");
	
	$query = "INSERT INTO address(city, street1, street2, country, state, zip) VALUES('".$strCity."','".$strStreet1."','".$strStreet2."','".$strCountry."','".$strState."','".$strZip."')";
	$result = $mysqli->query($query);
		
	$selectQuery = "SELECT MAX(id) FROM address";
	$result=$mysqli->query($selectQuery);
	$row = mysqli_fetch_row($result);
	
	$maxID = $row[0];
	
		
	$insertQuery = "INSERT INTO user(name, email, passwd, carrier, expenses, pickup_route, amount, address_id, role, phone) VALUES('".$strName."', '".$strEmail."', '".$password."','".$strCarrier."', '".$strExpenses."','".$strPickroute."','".$strAmount."', '".$maxID."', 'THEROLE', '".$strPhone."')";
	$deleteQuery = "DELETE FROM address WHERE id='".$maxID."'";
	
	$result=$mysqli->query($insertQuery); 
	$statusFlag = $mysqli->affected_rows;
	if($statusFlag!=1)
	{
		$mysqli->query($deleteQuery); 
	}
	
	$mysqli->close();
	
	return $statusFlag;
	}
}


function Check_Credentials($strName, $strPasswd)
{
	
	$buff_passwd = md5($strPasswd);
	$link = @mysqli_connect("localhost","root", "123", "mydb");
	if (!$link) 
	{
     	$variable1 = mysqli_connect_error();
		return 5;
		//exit();
	}
	else
	{
	$mysqli = new mysqli("localhost","root", "123");
	$mysqli->select_db("mydb");
	
	$query = "SELECT id FROM user WHERE name='".$strName."' and passwd='".$buff_passwd."'";
	$mysqli->query($query);
	$presense_flag = $mysqli->affected_rows;
			
	return $presense_flag;
	
	$mysqli->close();
	}
}

function Get_Profile($strName)
{
	
	$mysqli = new mysqli("localhost","root", "123");
	$mysqli->select_db("mydb");
	
	$query = "SELECT * FROM user LEFT JOIN address ON(address.id=user.address_id)WHERE user.name='".$strName."'";
	
	$result=$mysqli->query($query);
	
	$row = $result->fetch_array();
		
	$result->close();
	$mysqli->close();

	return $row;
}

function Get_Carrier()
{
	$link = @mysqli_connect("localhost","root", "123", "mydb");
	if (!$link) 
	{
     	$variable1 = mysqli_connect_error();
		echo "<option value='".$variable1."'>".$variable1."</option>";	
		//exit();
	}
	else 
	{
	$mysqli = new mysqli("localhost","root", "123");
	$mysqli->select_db("mydb");
	$query = "SELECT * FROM carrier";
	
	$result=$mysqli->query($query);
	$number_of_records = $mysqli->affected_rows;
	
	while($row = $result->fetch_array())
	{
		echo "<option value='".$row[1]."'>".$row[1]."</option>";		
	}
	
	$result->close();
	$mysqli->close();
	}
}

?>