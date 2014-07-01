#!usr/bin/perl

use strict;
use warnings;

use rijndael::encd 'encd';
use rijndael::decd 'decd';

$ciph = encd("vicki", "Hi code! how are u man?? do work... please...");
say $ciph;
$pln = decd("vicki", $ciph);
print $pln;

