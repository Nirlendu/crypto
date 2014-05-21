1>First download the latest jdk version from internet and save the folder under the folder name java in usr directory
2>Second install the Swig latest version by typing this-Sudo apt-get install swig
3>Now execute the following code in the srccode directory
		swig -java cryp.i
		gcc -Wall -fPIC -I/usr/java/jdk1.8.0_05/include/ -I/usr/java/jdk1.8.0_05/include/linux -c cryp.c cryp_wrap.c
		ld -shared cryp.o cryp_wrap.o -o libcryp.so 
4>After doing all this stuffs now run the main.java file using javac compiler- javac main.java
5>Now call using the library path ... java -Djava.library.path=/home/rohit/swigjava main
6>Give your input now to STDIN.
