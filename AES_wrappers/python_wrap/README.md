1>First install the following python interpretor

<code>Sudo apt-get install python-dev</code>

2>Second install the Swig latest version by typing this-

<code>Sudo apt-get install swig</code>

3>Now execute the following code in the swigpython directory

      swig -python ../lib/rijndael.i
      gcc -Wall -fPIC -I/usr/include/python2.7 -c ../lib/rijndael.c ../lib/rijndael_wrap.c
      ld -shared rijndael.o rijndael_wrap.o -o _rijndael.so
 
4>After doing all this stuffs now import cryp lib in python window

    import rijndael
    rijndael.enc("key","message")


