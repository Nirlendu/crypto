
#include <stdio.h>
#include "../lib/rijndael.c"

int main()
{
  char * password = "vickianandyadav";
  char * message = "This is some text, which is to be encrypted. Do work  man. please... please.... please.";
  char * cipher_text = enc(password, message);
  printf("\n%s\n\n", cipher_text);
  char * plain_text =  dec(password, cipher_text);
  printf("%s\n", plain_text);
}

