1>First install the following perl interpretor

<code>Sudo apt-get install perl5</code>

2>Second install the Swig latest version by typing this

<code>Sudo apt-get install swig</code>

3>Now execute the following code in this directory

	<code> swig -perl5 cryp.i</code>
	<code>gcc -c `perl -MConfig -e 'print join(" ", @Config{qw(ccflags optimize cccdlflags)}, \"-I$Config{archlib}/CORE")'` cryp.c cryp_wrap.c </code>
       <code>gcc `perl -MConfig -e 'print $Config{lddlflags}'` cryp.o cryp_wrap.o -o cryp.so</code>

4>After doing all this stuffs now type this command and execute

	<code>perl</code>
	<code>use cryp;</code>
	<code>cryp::enc_dec("rohit","d.txt");</code>
	<code>ctrl+d</code>
	<code>enter the input to STDIN</code>
	<code>ctrl+d</code>
		

