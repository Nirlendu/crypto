
#include <stdio.h>
#include <rijndael.h>
#include <stdlib.h>
#include <string.h>

/*
int main()
{
  char * password1 = "vickianandyadav";
  char * password2 = "rohitanurag2";
  char * message1 = "This is some text, which is to be encrypted. Do work man. please... please.... please.";
  char * message2 = "This is a different. Lets see what happens to this...";
  char * cipher_text1 = enc(password1, message1);
  char * cipher_text2 = enc(password2, message2);
  printf("\n%s\n", cipher_text1);
  printf("%s\n", cipher_text2);
  char * plain_text1 = dec(password1, cipher_text1);
  char * plain_text2 = dec(password2, cipher_text2);
  printf("%s\n", plain_text1);
  printf("%s\n", plain_text2);
  free(cipher_text1);
  free(cipher_text2);
  free(plain_text1);
  free(plain_text2);
}
*/

int main()
{
  char * password1 = "vickianandyadav";
  char * password2 = "rohitanurag2";
  char * message1 = "This is some text, which is to be encrypted. Do work man. please... please.... please.";
  char * message2 = "This is a different. Lets see what happens to this...";
  char * cipher_text1 = enc(password1, message1);
  char * cipher_text2 = enc(password2, message2);
  printf("\n%s\n", cipher_text1);
  printf("%s\n\n", cipher_text2);
  char * plain_text1 = dec(password1, cipher_text1);
  char * plain_text2 = dec(password2, cipher_text2);
	
	int i, j;
	for(j=0; j<1000; j++)
	{
		char * c_t1 = enc(password1, message1);
		for(i=0; i<strlen(c_t1); i++)
			if(c_t1[i] != cipher_text1[i])
				{ printf("lol! you were under a very wrong perception... the infection goes deep within"); return 0; }
		char * c_t2 = enc(password2, message2);
		for(i=0; i<strlen(c_t2); i++)
			if(c_t2[i] != cipher_text2[i])
				{ printf("lol! you were under a very wrong perception... the infection goes deep within"); return 0; }
	}
	printf("everything went fine over here! better search other places for any bug!\n");
}


