/* example.i */
 %module cryp
 %{
 /* Put header files here or function declarations like below */
 
 
  extern int enc_dec(char *password, char *filename);

 %}

   extern int enc_dec(char *password, char *filename);
