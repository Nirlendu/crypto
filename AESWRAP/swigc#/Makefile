all: callall

callall:swig compile lib cs mono

swig:  cryp.i
	swig -csharp cryp.i

compile: cryp.c cryp_wrap.c
	gcc -c -fpic cryp.c cryp_wrap.c

lib: cryp.o cryp_wrap.o
	gcc -shared cryp.o cryp_wrap.o -o libcryp.so

cs: runme.cs crypPINVOKE.cs cryp.cs
	gmcs *.cs -out:cryp.exe

mono: cryp.exe
	mono cryp.exe
