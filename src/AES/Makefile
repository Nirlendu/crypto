
librijndael.so: lib/rijndael.c include/base64.h lib/base64.c
	gcc -c -Wall -Werror -fpic lib/base64.c
	gcc -c -Wall -Werror -fpic lib/rijndael.c
	gcc -shared -o librijndael.so rijndael.o base64.o
	rm *.o
	mv librijndael.so ./lib

test_main: C_wrap/test_main.c librijndael.so
	gcc -L./lib -I./include -o test_main C_wrap/test_main.c -lrijndael -Wl,-rpath=./lib

.PHONY: clean

clean:
	rm lib/librijndael.so test_main
