all: callall

callall:swig compile lib move path 

swig: ../rijndael.i
	swig -java ../rijndael.i
	mv ../rijndael_wrap.c .
	mv ../*java .

compile: ../lib/rijndael.c rijndael_wrap.c
	gcc -Wall -fPIC -I/usr/java/jdk1.8.0_05/include/ -I/usr/java/jdk1.8.0_05/include/linux -c ../lib/rijndael.c rijndael_wrap.c

lib: rijndael.o rijndael_wrap.o
	ld -shared rijndael.o rijndael_wrap.o -o librijndael.so 

java: main.java
	javac main.java
	
path: main.class main.java
	java -Djava.library.path=./main

.PHONY: clean

clean:
	rm *.o *.so *java
