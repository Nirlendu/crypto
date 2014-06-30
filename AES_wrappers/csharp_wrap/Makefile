all: callall

callall:swig compile lib cs mono

swig:  ../rijndael.i
	swig -csharp ../rijndael.i
	mv ../rijndael_wrap.c .
	mv ../*cs .

compile:  ../lib/rijndael.c rijndael_wrap.c
	gcc -c -fpic ../lib/base64.c ../lib/rijndael.c rijndael_wrap.c

lib: rijndael.o rijndael_wrap.o base64.o
	gcc -shared base64.o rijndael.o rijndael_wrap.o -o librijndael.so

cs: runme.cs rijndaelPINVOKE.cs rijndael.cs
	gmcs *.cs -out:rijndael.exe

mono: rijndael.exe
	mono rijndael.exe

.PHONY: clean

clean: 
	rm *.o *.so *.exe
