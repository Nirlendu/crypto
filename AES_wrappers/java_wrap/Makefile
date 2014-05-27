all: callall

callall:swig compile lib move java path 

swig: ../lib/rijndael.i
	swig -java ../lib/rijndael.i

compile: ../lib/rijndael.c ../lib/rijndael_wrap.c
	gcc -Wall -fPIC -I/usr/java/jdk1.8.0_05/include/ -I/usr/java/jdk1.8.0_05/include/linux -c ../lib/rijndael.c ../lib/rijndael_wrap.c

lib: rijndael.o rijndael_wrap.o
	ld -shared rijndael.o rijndael_wrap.o -o librijndael.so 

java: main.java
	javac main.java

move:../lib/rijndael.java ../lib/rijndaelJNI.java
	mv ../lib/*java ../java_wrap

path: main.class main.java
	java -Djava.library.path=/home/rohit/AESWRAPLIBRARIES/java_wrap/ main
