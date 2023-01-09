// #include <stdio.h>
// #include <stdlib.h>

#include "vic20.h"

#pragma static-locals (on)
#pragma register-vars (on)
#pragma check-stack (off)

#define byte unsigned char

#define ASTERIX 0x2A

// Screen center // nudge it 3 more right so ready doesn't wipe it
// 7680 + (11 * 22) + 10 + 3
#define SNOWFLAKE_CENTER  7680 + (11 * 22) + 10 + 3
#define LEFT_UPPER_START_POINT SNOWFLAKE_CENTER - 4 - (22 * 3)

#define DOWN_ONE_ROW 22
#define UP_ONE_ROW -22
#define LEFT_ONE_COLUMN -1
#define RIGHT_ONE_COLUMN 1

#define DIAGONAL_DOWN_RIGHT DOWN_ONE_ROW + RIGHT_ONE_COLUMN
#define DIAGONAL_UP_RIGHT UP_ONE_ROW + RIGHT_ONE_COLUMN


static byte* screenPtr = LEFT_UPPER_START_POINT;

static byte* iterPtr;

static byte line = 2;
static byte i;
static byte j;
static byte dir;

static signed char DIRS[4] = {DOWN_ONE_ROW, UP_ONE_ROW, LEFT_ONE_COLUMN, RIGHT_ONE_COLUMN};

static signed char currentDir;
static signed char lineDir = DIAGONAL_DOWN_RIGHT;


void cdecl main(void)
{

  // Clear screen, make screen pokes and border white
  // __asm__ ("jsr $E55F");
  VIC.bg_border_color = 0b0001001;

  while (line) {
    --line;


    i = 9;
    
    while(i) {
      --i;


      dir = 4;
      while (dir) {
        --dir;
        iterPtr = screenPtr;

        currentDir = DIRS[dir];

        j = 5;
        while (j) {
          (*iterPtr) = ASTERIX;
          iterPtr += currentDir;
          --j;
        }

      }

      screenPtr += lineDir;


    }

    screenPtr -= (9 + 22); // LEAP LEFT 8 columns, up one row) to the new line start point
    lineDir = DIAGONAL_UP_RIGHT;
  }

  // return 0;
}
