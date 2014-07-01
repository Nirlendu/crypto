all: callall

callall:swig compile lib cs mono

swig:  ../rijndael.i
	swig -csharp ../rijndael.i
	mv ../rijndael_wrap.c .
	mv ../*cs .

compile: ../../src/AES/lib/base64.c ../../src/AES/lib/rijndael.c rijndael_wrap.c
	gcc -c -fpic ../../src/AES/lib/base64.c ../../src/AES/lib/rijndael.c rijndael_wrap.c

lib: base64.o rijndael.o rijndael_wrap.o
	gcc -shared base64.o rijndael.o rijndael_wrap.o -o librijndael.so

cs: runme.cs rijndaelPINVOKE.cs rijndael.cs
	gmcs *.cs -out:rijndael.exe

mono: rijndael.exe
	mono rijndael.exe

.PHONY: clean

clean: 
	rm *.o *.so *.exe
