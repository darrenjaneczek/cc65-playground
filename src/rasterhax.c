#include <stdio.h>
#include <stdlib.h>

#include "vic20.h"

// 7680 to 8185
// 36869 case: 240 upper 242 lower
// 38520 colors


#define byte unsigned char

#define SCREEN_CHARS ((unsigned char*)7680)
#define SCREEN_COLORS ((unsigned char*)38400)

void setChar(byte row, byte col, byte value, byte color) {
  unsigned int offset = row * ((byte)22) + col;
  SCREEN_CHARS[offset] = value;
  SCREEN_COLORS[offset] = color;
}



int main(void)
{

  while (1) {
    VIC.bg_border_color = VIC.rasterline;


  }

  return EXIT_SUCCESS;
}