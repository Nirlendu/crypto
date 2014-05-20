
#include <stdio.h>
#include "rijndael.h"

int main(int argc, char **argv)
{
  if(argc < 4)
  {
    fputs("Missing argument\n", stderr);
    return 1;
  }
  if( *argv[1] == 'd' || ( *argv[1] == '-' && *(argv[1]+1) == 'd') )
    return decrypt( *(argv+2), *(argv+3) );
  else if( *argv[1] == 'e' || ( *argv[1] == '-' && *(argv[1]+1) == 'e') )
    return encrypt( *(argv+2), *(argv+3) );
  else
  {
    fputs("Missing or inappropriate first argument\n", stderr);
    return 1;
  }
}
