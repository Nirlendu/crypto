all: callall

callall:swig compile lib
 
swig: cryp.i
	swig -perl5 cryp.i

compile: cryp.c cryp_wrap.c
	gcc -c `perl -MConfig -e 'print join(" ", @Config{qw(ccflags optimize cccdlflags)},"-I$$Config{archlib}/CORE")'` cryp.c cryp_wrap.c

lib: cryp.o cryp_wrap.o
	gcc `perl -MConfig -e 'print $$Config{lddlflags}'` cryp.o cryp_wrap.o -o cryp.so


