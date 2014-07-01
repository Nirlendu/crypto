
librijndael.so: lib/rijndael.c include/base64.h lib/base64.c
	gcc -c -Wall -Werror -fpic lib/base64.c
	gcc -c -Wall -Werror -fpic lib/rijndael.c
	gcc -shared -o librijndael.so rijndael.o base64.o
	rm *.o
	mv librijndael.so ./lib

test_main: c_test/test_main.c librijndael.so
	gcc -L./lib -I./include -o test_main c_test/test_main.c -lrijndael -Wl,-rpath=./lib

python: python_wrap/setup.py python_wrap/rijndael_python.c
	cd python_wrap && make
	cp python_wrap/*info .
	cp python_wrap/*so .


.PHONY: clean

clean:
	rm lib/librijndael.so test_main *so *fo
	cd python_wrap && make clean

