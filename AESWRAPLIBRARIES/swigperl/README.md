1>First install the following perl interpretor:Sudo apt-get install perl5
2>Second install the Swig latest version by typing this-Sudo apt-get install swig.
3>Now execute the following code in this directory
		 swig -perl5 cryp.i
		 gcc -c `perl -MConfig -e 'print join(" ", @Config{qw(ccflags optimize cccdlflags)}, \
                "-I$Config{archlib}/CORE")'` cryp.c cryp_wrap.c
		 gcc `perl -MConfig -e 'print $Config{lddlflags}'` cryp.o cryp_wrap.o -o cryp.so
4>After doing all this stuffs now type this command and execute
		perl
		use cryp;
		cryp::enc_dec("rohit","d.txt");
		ctrl+d
		enter the input to STDIN
		ctrl+d
		

