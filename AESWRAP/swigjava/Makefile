all: callall

callall:swig compile lib java path

swig: cryp.i
	swig -java cryp.i

compile: cryp.c cryp_wrap.c
	gcc -Wall -fPIC -I/usr/java/jdk1.8.0_05/include/ -I/usr/java/jdk1.8.0_05/include/linux -c cryp.c cryp_wrap.c

lib: cryp.o cryp_wrap.o
	ld -shared cryp.o cryp_wrap.o -o libcryp.so 

java: main.java
	javac main.java

path: main.class main.java
	java -Djava.library.path=/home/rohit/swigjava main
