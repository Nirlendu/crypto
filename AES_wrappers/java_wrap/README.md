1>First download the latest jdk version from internet and save the folder under the folder name java in usr directory.

2>Second install the Swig latest version by typing this

<code>Sudo apt-get install swig</code>

3>Now execute the following code in this directory

	swig -java ../lib/rijndael.i
	gcc -Wall -fPIC -I/usr/java/jdk1.8.0_05/include/ -I/usr/java/jdk1.8.0_05/include/linux -c ../lib/rijndael.c ../lib/rijndael_wrap.c
	ld -shared rijndael.o rijndael_wrap.o -o librijndael.so
	mv ../lib/*java ../java_wrap
 
4>After doing all this stuffs now run the main.java file using javac compiler-

<code> javac main.java</code>

5>Now call using the library path ...

<code> java -Djava.library.path=/home/rohit/java_wrap main</code>


