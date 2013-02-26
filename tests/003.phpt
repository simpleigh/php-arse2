--TEST--
Check arse works with a parameter
--SKIPIF--
<?php if (!extension_loaded("arse2")) print "skip"; ?>
--FILE--
<?php
$a = new Arse();
$a->output(3);
?>
--EXPECT--
You're an arse!
You're an arse!
You're an arse!
