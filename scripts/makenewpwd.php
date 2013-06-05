<?php
require('../req/dbaseutils.class');
session_start();
$new_pass_object = new class_dbaseutils;
$new_pass = $new_pass_object->generate_pass(8);

$new_pass_object->sql_connect();

$new_pass_object->update_passwd($_SESSION["login"],$new_pass);
$new_pass_object->send_credentials($_SESSION["login"], $new_pass, $_SESSION["login"]); //require smtp setup
$new_pass_object->sql_close();
header("location: ../?pg=pwdsent");
?>