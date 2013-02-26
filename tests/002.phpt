--TEST--
Check arse works with no parameters
--SKIPIF--
<?php if (!extension_loaded("arse2")) print "skip"; ?>
--FILE--
<?php
$a = new Arse();
$a->output();
?>
--EXPECT--
You're an arse!
