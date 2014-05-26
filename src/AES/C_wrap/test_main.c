
#include <stdio.h>
#include "../include/rijndael.h"

int main()
{
  char * password1 = "vickianandyadav";
  char * password2 = "rohitanurag2";
  char * message1 = "This is some text, which is to be encrypted. Do work  man. please... please.... please.";
  char * message2 = "This is a different text. Lets see what hhappens to this";
  char * cipher_text1 = enc(password1, message1);
  char * cipher_text2 = enc(password2, message2);
  printf("\n%s\n", cipher_text1);
  printf("%s\n", cipher_text2);
  char * plain_text1 = dec(password1, cipher_text1);
  char * plain_text2 = dec(password2, cipher_text2);
  printf("%s\n", plain_text1);
  printf("%s\n", plain_text2);
}
