all: callall

callall:swig compile lib

swig: ../rijndael.i
	swig -python ../rijndael.i
	mv ../rijndael_wrap.c .
	mv ../*py .

compile: ../lib/rijndael.c rijndael_wrap.c
	gcc -Wall -fPIC -I/usr/include/python2.7 -c ../lib/rijndael.c rijndael_wrap.c

lib: rijndael.o rijndael_wrap.o
	ld -shared rijndael.o rijndael_wrap.o -o _rijndael.so 


.PHONY: clean

clean: 
	rm *.o *.so *py*
