<?php
	//Get Pane Info
	//
	//Loads up the pane's config file and echoes general information
	function get_pane_info($pane, $info, $property)
	{
		$file = new DOMDocument();
		$file->load($pane."/config.xml");
  
		$elements = $file->getElementsByTagName(strtolower($info));
		foreach($elements as $setting)
		{
			$outputs = $setting->getElementsByTagName($property);
			$output = $outputs->item(0)->nodeValue;
			echo $output;
		}
	}
	
	//Get Pane Settings
	//
	//Used in panes to grab settings from config.xml
	function get_pane_settings($property)
	{
		$file = new DOMDocument();
		$file->load("config.xml");
  
		$elements = $file->getElementsByTagName(strtolower('panesettings'));
		foreach($elements as $setting)
		{
			$outputs = $setting->getElementsByTagName($property);
			$output = $outputs->item(0)->nodeValue;
			echo $output;
		}
	}
	
	//Parse Folders
	//
	//Returns an array of files/folder in a directory, removes . and ..
	function parse_folders($directory)
	{
		$scan = scandir($directory);
		unset($scan[0]);
		unset($scan[1]);
		$child_entries = array_values($scan);
		$directories = array();
		foreach ($scan as $item)
		{
			if (is_dir($item)) array_unshift($directories, $item);
		}
		return $directories;
	}
	
	//Display Pane Info
	//
	//Only used in index.php for showing installed panes
	function display_pane_info($dir_array)
	{
		foreach ($dir_array as $pane)
		{
			echo "<div class='pane-title'>".get_pane_info($pane, "paneinfo", "title")."</div>".
				 "<div class='pane-author'>".get_pane_info($pane, "paneinfo", "author")."</div>".
				 "<div class='pane-resolution'>".get_pane_info($pane, "paneinfo", "resolution")."</div>".
				 "<div class='pane-description'>".get_pane_info($pane, "paneinfo", "description")."</div>".
				 "<div class='pane-screenshot'><img src='".$pane."/".get_pane_info($pane, "paneinfo", "screenshot")."'></div>";
		}
	}
	
	//Load jQuery
	//
	//Use in header
	function load_jquery()
	{
		echo "<script src='http://".$_SERVER['SERVER_NAME']."/include/jquery.js'></script>";
	}
	
	function load_simplepie()
	{
		require_once("http://".$_SERVER['SERVER_NAME']."/include/simplepie.inc");
	}
?>