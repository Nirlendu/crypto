all: callall

callall:swig compile lib

swig: ../lib/rijndael.i
	swig -python ../lib/rijndael.i

compile: ../lib/rijndael.c ../lib/rijndael_wrap.c
	gcc -Wall -fPIC -I/usr/include/python2.7 -c ../lib/rijndael.c ../lib/rijndael_wrap.c

lib: rijndael.o rijndael_wrap.o
	ld -shared rijndael.o rijndael_wrap.o -o _rijndael.so 


