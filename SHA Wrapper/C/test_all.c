#include<stdio.h>
#include"../src/final_license.c"
int main(int argc, char *argv[]){
	char **err;
	printf("The authentication says : \n %s\n",_read_license(argv[1], *err));
	return 0;
}
