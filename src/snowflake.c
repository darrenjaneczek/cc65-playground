// #include <stdio.h>
// #include <stdlib.h>

#include "vic20.h"

#define byte unsigned char

#define ASTERIX 0x2A

// Screen center
// 7680 + (11 * 22) + 10
#define SNOWFLAKE_CENTER 7932

#define DOWN_ONE_ROW 22
#define UP_ONE_ROW -22
#define LEFT_ONE_COLUMN -1
#define RIGHT_ONE_COLUMN 1

int main(void)
{
  byte* screenPtr;
  byte* verticalPtr;
  byte* horizontalPtr;

  signed char dy;
  signed char dx;

  byte i;
  byte j;
  byte direction = 0;


  // Clear screen, make screen pokes and border white
  __asm__ ("jsr $E55F");
  VIC.bg_border_color = 0b0001001;

  while (direction < 4) {

    i = 0;

    dy = (direction & 0b01) ?  DOWN_ONE_ROW : UP_ONE_ROW;
    dx = (direction & 0b10) ? RIGHT_ONE_COLUMN : LEFT_ONE_COLUMN;

    screenPtr = (byte*)SNOWFLAKE_CENTER;

    while (i < 5) {

      j = 0;

      (*screenPtr) = ASTERIX;
      verticalPtr = screenPtr;
      horizontalPtr = screenPtr;
      while (j < 4) {
        verticalPtr -= dy;
        horizontalPtr -= dx;
        (*verticalPtr) = ASTERIX;
        (*horizontalPtr) = ASTERIX;
        ++j;
      }

      screenPtr -= dy;
      screenPtr -= dx;

      ++i;
    }


    ++direction;
  }

  return 0;
}
