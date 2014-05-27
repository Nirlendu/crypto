/* example.i */
 %module rijndael
 %{
 /* Put header files here or function declarations like below */
 
 
  extern char * enc(char *password, char *filename);
  extern char * dec(char *password, char *filename);
 %}
   extern  char * enc(char *password, char *filename);
   extern char * dec(char *password, char * filename);

