#include"../../src/SHA/license.h"
#include<stdio.h>
int main(int argc, char *argv[]){
	char *err;
	printf("%s\n",_read_license(argv[1], &err));
	return 0;
}
