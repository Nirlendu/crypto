#include<stdio.h>
#include<string.h>
#include"final_license.c"
int main(int argc, char *argv[]){
	/*
	int i;	
	printf("yes, the hash value is ");
	//uint8_t* ans=hash_this("QA","NO","000010","000010","000010","000010","20140101","20141231",59265359);
	for (i=0; i<20; i++) {
		printf("%02x", ans[i]);
	}
	printf("\n");
	
	char **err;
	if(_read_license(argv[1], err)==1){
		printf("The license file is succesful and checked without any errors\n");
	}
	else{
		printf("Some problem exists\n");
	}
	*/
	char *err;
	printf("%s\n",_read_license(argv[1], err));
	return 0;
}
