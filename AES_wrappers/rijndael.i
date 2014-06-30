%module rijndael
%{
  /* Put header files here or function declarations like below */
  char* encd(char *password, char *plain_text);
  char* decd(char *password, char *cipher_text);
%}
  %newobject encd;
  char* encd(char *password, char *plain_text);
  %newobject decd;
  char* decd(char *password, char *cipher_text);

