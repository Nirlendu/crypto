/* example.i */
 %module rijndael
 %{
 /* Put header files here or function declarations like below */
   char* encd(char *password, char *filename);
   char* decd(char *password, char *filename);
 %}
   %newobject encd;
   char* encd(char *password, char *filename);
   %newobject decd;   
   char* decd(char *password, char *filename);
