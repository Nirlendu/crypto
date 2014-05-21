1>First install the following c# compiler-sudo apt-get install monodevelop
2>Second install the Swig latest version by typing this-Sudo apt-get install swig.
3>Now execute the following code in the srccode directory
		swig -csharp cryp.i
		gcc -c -fpic cryp.c cryp_wrap.c
		gcc -shared cryp.o cryp_wrap.o -o libcryp.so
4>After doing all this stuffs now type this command and execute
		
		gmcs *.cs -out:cryp.exe
		mono cryp.exe
5>Give your input now to STDIN and press ctrl+d
