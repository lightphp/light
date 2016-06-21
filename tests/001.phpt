--TEST--
Check for light presence (PHP module & Zend extension)
--SKIPIF--
<?php if (!extension_loaded("light")) print "skip"; ?>
--FILE--
<?php
	var_dump(in_array('Light', get_loaded_extensions()));
	var_dump(in_array('Light', get_loaded_extensions(true)));
?>
--EXPECT--
bool(true)
bool(true)