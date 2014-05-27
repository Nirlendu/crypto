test_main: test_main.c rijndael.o base64.o
	gcc -o test_main test_main.c rijndael.o base64.o

rijndael.o: ../lib/rijndael.c
	gcc -c ../lib/rijndael.c

base64.o: ../lib/base64.c
	gcc -c ../lib/base64.c

