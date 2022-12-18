#include <stdio.h>
#include <stdlib.h>

#include "vic20.h"


int main(void)
{
  char c;

  printf(
    "%cHello, here are some \ncharacter codes via \nprintf.\n"
 	  "Press [RETURN] between each.\nSome have effects.\n"
    "Watch yourself!\n\n",
    147);
  c = 32;
  while (1) {
    // Pre-colourize each printout with char 31
    printf("%cChar %03d: [%c]...\n", 31, c, c);
    
    if (c == 255) {
      break;
    }

    getchar();

    c++;
  }


  return EXIT_SUCCESS;
}