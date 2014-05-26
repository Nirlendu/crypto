
#include <stdio.h>

//following functions enc(), dec() are there in ../lib/rijndael.c
//int enc( char *password, char *file_name);
//int dec( char *password, char *file_name);


#include "../include/rijndael.h"

int main(int argc, char **argv)
{
  if(argc < 4)
  {
    fputs("Missing argument\n", stderr);
    return 1;
  }
  if( *argv[1] == 'd' || ( *argv[1] == '-' && *(argv[1]+1) == 'd') )
    return dec( *(argv+2), *(argv+3) );
  else if( *argv[1] == 'e' || ( *argv[1] == '-' && *(argv[1]+1) == 'e') )
    return enc( *(argv+2), *(argv+3) );
  else
  {
    fputs("Missing or inappropriate first argument\n", stderr);
    return 1;
  }
}
