1>First install the following c# compiler-

<code>sudo apt-get install monodevelop</code>

2>Second install the Swig latest version by typing this-

<code>Sudo apt-get install swig.</code>

3>Now execute the following code in this directory

	swig -csharp ../lib/rijndael.i
	gcc -c -fpic ../lib/rijndael.c ../lib/rijndael_wrap.c
	gcc -shared rijndael.o rijndael_wrap.o -o librijndael.so

4>After doing all this stuffs now type this command and execute
		
	gmcs *.cs -out:rijndael.exe
	mono rijndael.exe


