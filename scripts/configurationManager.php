<?php
function getConfiguration($fileName) 
{
	foreach(split("\n", file_get_contents($fileName)) as $line)
	{
		$line = trim($line);
		if (($line != "")&&(substr($line, 0, 1)!="#")) 
		{
			list($key, $value) = split("=", $line, 2);
			if ($value != "" && $key != "") $output[$key] = $value;
		}
	}
	return $output;	
}

?>