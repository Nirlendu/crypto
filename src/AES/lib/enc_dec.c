#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/rijndael.h"
#include "../include/base64.h"

#define KEYBITS 256

typedef unsigned long u32;
typedef unsigned char u8;


char *encd( char *password, char * input) {
  unsigned long rk[RKLENGTH(KEYBITS)];
  unsigned char key[KEYLENGTH(KEYBITS)];
  int i, flen;
  int nrounds;
  char *output; char *c_t; char * b64;
  unsigned char plaintext[16] = {0};
  unsigned char ciphertext[16] = {0};
  int j;
  int c;
  int c_t_len;

  c_t_len = (strlen(input)/16 + 1)*24 + 1;
  output = (char *)malloc(c_t_len);
  if (output == NULL) {
    return NULL;
  }

  c_t = output;
  for (i = 0; i < sizeof(key); i++) {
    key[i] = *password != '\0' ? *password++ : '\0';
  }

  nrounds = rijndaelSetupEncrypt(rk, key, 256);
  while ( *input != 0 ) {

    for (j = 0; j < sizeof(plaintext); j++) {
      c = *input;
      plaintext[j] = c;
      input++;
      if (*input == 0)
        break;
    }

    for (j++; j < sizeof(plaintext); j++) {
      plaintext[j] = 0;
    }

    rijndaelEncrypt(rk, nrounds, plaintext, ciphertext);
    b64 = base64((void *)ciphertext, sizeof(ciphertext), &flen);

    for(i=0; i<flen; i++) {
      c_t[i] = b64[i];
    }

    c_t = c_t + flen;

    free(b64);
  }
  *c_t = '\0';
  return output;
}




char * decd( char *password, char *cipher_text)
{
  unsigned long rk[RKLENGTH(KEYBITS)];
  unsigned char key[KEYLENGTH(KEYBITS)];
  int i, flen;
  int nrounds;
  int p_t_len;
  char * plain_text; char * p_t; unsigned char * ub64;
  unsigned char plaintext[16];
  char ciphertext[24];

  p_t_len = (strlen(cipher_text)/24 + 1)*16 +1;
  plain_text = (char *)malloc(p_t_len);

  if (plain_text == NULL) {
    return NULL;
  }

  p_t = plain_text;

  for (i = 0; i < sizeof(key); i++) {
    key[i] = *password != '\0' ? *password++ : '\0';
  }

  nrounds = rijndaelSetupDecrypt(rk, key, 256);

  while (*cipher_text != 0) {

    for(i=0; i<sizeof(ciphertext); i++) {

      if(*cipher_text == '\0') {
        fprintf(stderr, "Error : Something Wrong with the provided cipher text! ");
        return NULL;
      }

      ciphertext[i] = *cipher_text;
      cipher_text++;
    }

    ub64 = unbase64(ciphertext, sizeof(ciphertext), &flen);
    rijndaelDecrypt(rk, nrounds, ub64, plaintext);

    for(i=0; i<flen; i++) {
      p_t[i] = plaintext[i];
    }

    p_t = p_t + flen;
    free(ub64);
  }

  *p_t = '\0';
  return plain_text;
}
