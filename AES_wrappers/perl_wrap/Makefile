all: callall

callall:swig compile lib
 
swig: ../rijndael.i
	swig -perl5 ../rijndael.i
	mv ../rijndael_wrap.c .
	mv ../*pm .

compile: ../lib/rijndael.c rijndael_wrap.c
	gcc -c `perl -MConfig -e 'print join(" ", @Config{qw(ccflags optimize cccdlflags)},"-I$$Config{archlib}/CORE")'` ../lib/base64.c ../lib/rijndael.c rijndael_wrap.c
	
lib: rijndael.o rijndael_wrap.o
	gcc `perl -MConfig -e 'print $$Config{lddlflags}'` base64.o rijndael.o rijndael_wrap.o -o rijndael.so


.PHONY: clean

clean: 
	rm *.o *.so *pm
