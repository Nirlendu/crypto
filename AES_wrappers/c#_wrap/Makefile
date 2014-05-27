all: callall

callall:swig compile lib move cs mono

swig:  ../lib/rijndael.i
	swig -csharp ../lib/rijndael.i

compile:  ../lib/rijndael.c ../lib/rijndael_wrap.c
	gcc -c -fpic ../lib/rijndael.c ../lib/rijndael_wrap.c

lib: rijndael.o rijndael_wrap.o
	gcc -shared rijndael.o rijndael_wrap.o -o librijndael.so

cs: runme.cs rijndaelPINVOKE.cs rijndael.cs
	gmcs *.cs -out:rijndael.exe

mono: rijndael.exe
	mono rijndael.exe

move:../lib/rijndael.cs ../lib/rijndaelPINVOKE.cs
	mv ../lib/*cs ../c#_wrap
