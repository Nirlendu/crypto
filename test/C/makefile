hash.o:../../src/SHA/hash.c
	gcc -c ../../src/SHA/hash.c
license.o:../../src/SHA/license.c 
	gcc -c ../../src/SHA/license.c	 
test:test.c license.o hash.o
	gcc -o test test.c license.o hash.o
	./test ../assets/license
