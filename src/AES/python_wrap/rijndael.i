/* example.i */
 %module rijndael
 %{
 /* Put header files here or function declarations like below */
 
 
  int enc(char *password, char *filename);
  int dec(char *password, char *filename);
 %}
 
int enc(char *password, char *filename);
int dec(char *password, char *filename);

