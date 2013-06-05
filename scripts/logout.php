<?php
	session_start();
	
	session_unregister("login");
	session_unregister("person");
	session_unregister("additional_param");
	
session_destroy();
header("location: ../");
?>