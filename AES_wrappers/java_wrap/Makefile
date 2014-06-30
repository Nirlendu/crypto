all: callall

callall:swig compile lib java path 

swig: ../rijndael.i
	swig -java ../rijndael.i
	mv ../rijndael_wrap.c .
	mv ../*java .

compile: ../lib/rijndael.c rijndael_wrap.c
	gcc -Wall -fPIC -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -c ../lib/rijndael.c rijndael_wrap.c

lib: rijndael.o rijndael_wrap.o
	ld -shared rijndael.o rijndael_wrap.o -o librijndael.so 

java: main.java
	javac main.java
	
path: main.class main.java
	java -Djava.library.path=/home/rohit/id_crypto/AES_wrappers/java_wrap/ main

.PHONY: clean

clean:
	rm *.o *.so 
