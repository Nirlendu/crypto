1>First install the following perl interpretor

<code>Sudo apt-get install perl5</code>

2>Second install the Swig latest version by typing this

<code>Sudo apt-get install swig</code>

3>Now execute the following code in this directory

	 swig -perl5 ../lib/rijndael.i
	gcc -c `perl -MConfig -e 'print join(" ", @Config{qw(ccflags optimize cccdlflags)}, \
            "-I$Config{archlib}/CORE")'` ../lib/rijndael.c ../lib/rijndael_wrap.c
         gcc `perl -MConfig -e 'print $Config{lddlflags}'` rijndael.o rijndael_wrap.o -o rijndael.so

4>After doing all this stuffs now type this command and execute

	perl
	use rijndael;
	cryp::enc("rohit","Hey rohit anurag");
	ctrl+d
	

