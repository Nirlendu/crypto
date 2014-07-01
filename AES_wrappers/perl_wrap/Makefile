all: callall

callall:swig compile lib
 
swig: ../rijndael.i
	swig -perl5 ../rijndael.i
	mv ../rijndael_wrap.c .
	mv ../*pm .

compile: ../../src/AES/lib/base64.c ../../src/AES/lib/rijndael.c rijndael_wrap.c
	gcc -c `perl -MConfig -e 'print join(" ", @Config{qw(ccflags optimize cccdlflags)},"-I$$Config{archlib}/CORE")'` ../../src/AES/lib/base64.c ../../src/AES/lib/rijndael.c rijndael_wrap.c
	
lib: base64.o rijndael.o rijndael_wrap.o
	gcc `perl -MConfig -e 'print $$Config{lddlflags}'` base64.o rijndael.o rijndael_wrap.o -o rijndael.so


.PHONY: clean

clean: 
	rm *.o *.so *pm
