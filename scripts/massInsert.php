<?php
require('../req/dbaseutils.class');

$oobject = new class_dbaseutils;

$oobject->sql_connect();
$e=0;

$e=0;
$sql = "SELECT COUNT(name) from carrier";
$gav= $oobject->sql_count();

$records_per_page = 50;
$total_recs = $gav[0];
$number_of_pages = $total_recs/$records_per_page;
$number_of_extrapages = $total_recs%$records_per_page;



echo $records_per_page."<br>";
echo $total_recs."<br>";
echo $number_of_pages."<br>";
echo $number_of_extrapages."<br>";

//print_r($pagination);

echo '<br><br>';




if(isset($_GET['pag'])&&$_GET['pag']!=0)
{
	$page_num = $_GET['pag'];

	$off = $records_per_page * ($page_num-1);
	$lim = $off + $records_per_page;

	if($lim<=$total_recs){

		$arr_off=$oobject->sql_pagination($off, $lim);
		foreach($arr_off as $vvl){
			
			$printout[]=$vvl[0];
		}

	}else
	{
		$arr_off=$oobject->sql_pagination($off, $lim);
		foreach($arr_off as $vvl){
			
			$printout[]=$vvl[0];
		}
	}
}
else
{
$arr_off=$oobject->sql_pagination(0, 50);
		foreach($arr_off as $vvl){
			
			$printout[]=$vvl[0];
		}
	
}

foreach($printout as $vvl1){
			
			echo $vvl1."<br>";
		}
	


echo '<br>';
echo '<br>';

echo 'page :';
for($i=1;$i<$number_of_pages+1;$i++)
{
	echo'<a href=?pag='.$i.'>&nbsp;'.$i.'&nbsp;</a>';
}

$oobject->sql_close();

?>