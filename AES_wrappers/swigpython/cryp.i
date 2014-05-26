/* example.i */
 %module cryp
 %{
 /* Put header files here or function declarations like below */
 
 
  extern void enc_dec(char *password, char *filename);

 %}
 
 extern void enc_dec(char *password, char *filename);

