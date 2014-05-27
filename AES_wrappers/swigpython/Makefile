all: callall

callall:swig compile lib

swig: cryp.i
	swig -python cryp.i

compile: cryp.c cryp_wrap.c
	gcc -Wall -fPIC -I/usr/include/python2.7 -c cryp.c cryp_wrap.c

lib: cryp.o cryp_wrap.o
	ld -shared cryp.o cryp_wrap.o -o _cryp.so 


