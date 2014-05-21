1>First install the following c# compiler-

<code>sudo apt-get install monodevelop</code>

2>Second install the Swig latest version by typing this-

<code>Sudo apt-get install swig.</code>

3>Now execute the following code in this directory

	<code>swig -csharp cryp.i
	gcc -c -fpic cryp.c cryp_wrap.c
	gcc -shared cryp.o cryp_wrap.o -o libcryp.so</code>

4>After doing all this stuffs now type this command and execute
		
	<code>gmcs *.cs -out:cryp.exe
	mono cryp.exe</code>

5>Give your input now to STDIN and press ctrl+d
