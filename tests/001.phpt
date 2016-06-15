--TEST--
Check for light presence
--SKIPIF--
<?php if (!extension_loaded("light")) print "skip"; ?>
--FILE--
<?php
echo "light extension is available";
?>
--EXPECT--
light extension is available