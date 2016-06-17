--TEST--
Check for classes presence
--SKIPIF--
<?php if (!extension_loaded("light")) print "skip"; ?>
--FILE--
<?php
	$declared_classes = get_declared_classes();
	$classes = array_map(function ($s) {
		return ucfirst(trim(basename($s, '.c')));
	}, glob('../classes/*/*.c'));
	foreach ($classes as $class) {
		$classns = 'Light\\' . $class;
		if (!in_array($classns, $declared_classes))
			die("$classns: Class is not declared");
	}
	echo "All classes are declared";
?>
--EXPECT--
All classes are declared