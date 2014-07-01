all: callall

callall:swig compile lib

swig: ../rijndael.i
	swig -python ../rijndael.i
	mv ../rijndael_wrap.c .
	mv ../*py .

compile: ../../src/AES/lib/rijndael.c rijndael_wrap.c ../../src/AES/lib/base64.c
	gcc -Wall -fPIC -I/usr/include/python2.7 -c ../../src/AES/lib/base64.c ../../src/AES/lib/rijndael.c rijndael_wrap.c

lib: base64.o rijndael.o rijndael_wrap.o
	ld -shared rijndael_wrap.o rijndael.o base64.o -o _rijndael.so

.PHONY: clean

clean: 
	rm *.o *.so *py*
