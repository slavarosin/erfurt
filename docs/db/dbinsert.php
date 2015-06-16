<?php

function Insert_Credentials($strName,$strPassword, $strCity, $strStreet1, $strStreet2,$strCountry, $strState, $strZip, $strEmail, $strCarrier, $strExpenses, $strPickroute, $strAmount, $strPhone )
 	{
		$conn_id = @ mysql_connect("localhost", "erfurt", "erfurt");
			if(!$conn_id)
				{
					$sgl_err = mysql_errno() . " " . mysql_error() . "\n";
					echo "MYSQL CONNECT:".$sgl_err."<br>";
				}
			else
				{
					echo "MYSQL CONNECT OK <br>";
					mysql_select_db("erfurt", $conn_id);
					$sgl_err = mysql_errno($conn_id) . " " . mysql_error($conn_id). "\n";
					echo "SELECT DB: ".$sgl_err."<br>";
				}

		$result = mysql_query("INSERT INTO address(city, street1, street2, country, state, zip) VALUES('".$strCity."','".$strStreet1."','".$strStreet2."','".$strCountry."','".$strState."','".$strZip."')", $conn_id);
 		$sql_err = mysql_errno() . " " . mysql_error() . "\n";
		echo "INSERT INTO ADDRESS: ".$sql_err."<BR>";

 		$statusFlag = trim($sql_err);
 		if($statusFlag=="0")
 		{
 			$result = mysql_query("SELECT MAX(id) FROM address", $conn_id);
 			$sql_err = mysql_errno() . " " . mysql_error() . "\n";
 			echo "SELECT MAXID FROM ADDRESS: ".$sql_err."<BR>";

 			$statusFlag = trim($sql_err);
 			if($statusFlag=="0")
 			{
 				$row = mysql_fetch_array($result);
				echo "FETCH ID FROM QUERY RESULT: ".$sql_err."<BR>";

				$maxID = $row[0];

				$insertQuery = "INSERT INTO user(name, email, passwd, carrier, expenses, pickup_route, amount, address_id, role, phone) VALUES('".$strName."', '".$strEmail."', '".$password."','".$strCarrier."', '".$strExpenses."','".$strPickroute."','".$strAmount."', '".$maxID."', 'USER', '".$strPhone."')";
				$deleteQuery = "DELETE FROM address WHERE id='".$maxID."'";

				$result=mysql_query($insertQuery);
				$sql_err = mysql_errno() . " " . mysql_error() . "\n";
 				echo "INSERT INTO USER: ".$sql_err."<BR>";

 				$statusFlag = trim($sql_err);

 				if($statusFlag!="0")
				{
					$result = mysql_query($deleteQuery);
 				}
 			}
		}
	}


?>
