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


byte dingVol = 0;


void setVolume(byte volume) {
  // Force volume to 0 to 15
  volume &= 0b00001111;
  VIC.volume_color = (VIC.volume_color & 0b11110000) | volume;
}

int main(void)
{
  byte color = 0;
  byte r = 0;
  byte c = 0;
  char dr = 1;
  char dc = 1;
  byte rasterActionOn = 0;
  while (1) {
    if (VIC.rasterline == 128 && !rasterActionOn) {
      rasterActionOn = 1;

      setChar(r, c, 0x4F, color);
      //setChar(r, c, 0x20, 0);
      r += dr;
      c += dc;

      if (r >= 23) { // Overflow to 255 so we don't need to check neg
        r -= dr;
        dr = -dr;
        ++color;
      }

      if (c >= 22) { // Overflow to 255 so we don't need to check neg
        c -= dc;
        dc = -dc;
        // ++color;
        dingVol = 127;
        VIC.voice3 = 0b10000000 | (127 - (r << 3)); // 23 x 4 should be enough range  
      }
      //setChar(r, c, 0x4F, color);

    } else {
      rasterActionOn = 0;
    }

    if (dingVol) {
      --dingVol;
      setVolume(dingVol >> 3);
      if (0b00001000 & dingVol) {
        --VIC.voice3;
      }
    }


  }

  return EXIT_SUCCESS;
}