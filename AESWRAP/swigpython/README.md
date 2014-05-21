1>First install the following python interpretor

<code>Sudo apt-get install python-dev</code>

2>Second install the Swig latest version by typing this-

<code>Sudo apt-get install swig</code>

3>Now execute the following code in the swigpython directory

       <code> swig -python cryp.i
         gcc -Wall -fPIC -I/usr/include/python2.7 -c cryp.c cryp_wrap.c
       ld -shared cryp.o cryp_wrap.o -o _cryp.so</code>
 
4>After doing all this stuffs now import cryp lib in python window

    <code> import cryp
     cryp.enc_dec("key","name of file where ciphertext should be stored")</code>

5>Give your input now to STDIN and press ctrl+d
