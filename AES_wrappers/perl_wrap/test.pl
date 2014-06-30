#!usr/bin/perl

use strict;
use warnings;

use rijndael::encd 'encode';
use rijndael::decd 'decode';

$ciph = encode("vicki", "Hi code! how are u man?? do work... please...");
say $ciph;
$pln = decode("vicki", $ciph);
print $pln;

