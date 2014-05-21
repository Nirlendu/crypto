1>First install the following perl interpretor

<code>Sudo apt-get install perl5</code>

2>Second install the Swig latest version by typing this

<code>Sudo apt-get install swig</code>

3>Now execute the following code in this directory

	<code> swig -perl5 cryp.i
	gcc -c `perl -MConfig -e 'print join(" ", @Config{qw(ccflags optimize cccdlflags)}, \
            "-I$Config{archlib}/CORE")'` cryp.c cryp_wrap.c
         gcc `perl -MConfig -e 'print $Config{lddlflags}'` cryp.o cryp_wrap.o -o cryp.so</code>

4>After doing all this stuffs now type this command and execute

	<code>perl
	use cryp;
	cryp::enc_dec("rohit","d.txt");
	ctrl+d
	enter the input to STDIN
	ctrl+d</code>
		

