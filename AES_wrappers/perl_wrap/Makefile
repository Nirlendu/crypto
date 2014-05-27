all: callall

callall:swig compile move lib
 
swig: ../lib/rijndael.i
	swig -perl5 ../lib/rijndael.i

compile: ../lib/rijndael.c ../lib/rijndael_wrap.c
	gcc -c `perl -MConfig -e 'print join(" ", @Config{qw(ccflags optimize cccdlflags)},"-I$$Config{archlib}/CORE")'` ../lib/rijndael.c ../lib/rijndael_wrap.c

move: ../lib/rijndael.pm
	mv ../lib/*pm ../perl_wrap

lib: rijndael.o rijndael_wrap.o
	gcc `perl -MConfig -e 'print $$Config{lddlflags}'` rijndael.o rijndael_wrap.o -o rijndael.so


