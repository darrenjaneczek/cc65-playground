#include <stdio.h>
#include <stdlib.h>

#include "vic20.h"

// 7680 to 8185
// 36869 case: 240 upper 242 lower
// 38520 colors


#define byte unsigned char

#define SCREEN_CHARS ((unsigned char*)7680)
#define SCREEN_COLORS ((unsigned char*)38400)


byte HEX[] = {
  0x30, // 0 - 9
  0x31,
  0x32,
  0x33,
  0x34,
  0x35,
  0x36,
  0x37,
  0x38,
  0x39,
  0x41, // A - F
  0x42,    
  0x43,
  0x44,
  0x45,
  0x46
};

#define COL_OFFSET 6
#define ROW_OFFSET 4
#define WHOLE_LINE 22
 
void setChar(byte row, byte col, byte value, byte color) {
  // Multiplication is slow, so doing one char
  // at a time here is DUMBX
  unsigned int offset = row * ((byte)22) + col;
  SCREEN_CHARS[offset] = value;
  SCREEN_COLORS[offset] = color;
}

void dumbClear() {
  byte c;
  byte r;

  for (c = 0; c < 22; ++c) {
    for (r = 0; r < 23; ++r) {
      setChar(r, c, 0xE9, 3);
    }
  }

  for (c = 0; c < 22; ++c) {
    for (r = 0; r < 23; ++r) {
      setChar(r, c, 0x20, 0);
    }
  } 
}

void drawTable1();

void drawTable2();


byte* screenPtr = (byte*)7680; 
byte* colorPtr = (byte*)38400; 

// Turn these PTR methods into inline macros
void resetPtrs() {
  screenPtr = 7680; 
  colorPtr = 38400; 
}

void incPtrsBy(byte howMuch) {
  screenPtr += howMuch;
  colorPtr += howMuch;
}

void incPtrs() {
  ++screenPtr;
  ++colorPtr;
}

void setPtrChar(byte value, byte color) {
  (*screenPtr) = value;
  (*colorPtr) = color;
}

void drawFrame() {
  byte i;

  // Draw the top hex heading
  resetPtrs();
  incPtrsBy(COL_OFFSET + (ROW_OFFSET - 2) * WHOLE_LINE);

  for (i = 0; i < 16; ++i) {
    setPtrChar(HEX[i], 4);
    incPtrs();
  }

  // Draw the side hex heading
  resetPtrs();
  incPtrsBy(ROW_OFFSET * WHOLE_LINE + (COL_OFFSET - 2));

  for (i = 0; i < 16; ++i) {
    setPtrChar(HEX[i], 5);
    incPtrsBy(WHOLE_LINE);
  }

  // Draw horiz line
  resetPtrs();
  incPtrsBy((ROW_OFFSET - 1) * WHOLE_LINE);

  for (i = 0; i < WHOLE_LINE; ++i) {
    setPtrChar(0x40, 0); // Horiz line
    incPtrs();
  }

  // Draw vert line
  resetPtrs();
  incPtrsBy(COL_OFFSET - 1);

  for (i = 0; i < WHOLE_LINE; ++i) {
    setPtrChar(0x5D, 0); // Horiz line
    incPtrsBy(WHOLE_LINE);
  }

  // Cross at the joining point
  setChar(ROW_OFFSET - 1, COL_OFFSET - 1,0x5B,0);

}

int main(void)
{
  dumbClear();
  drawFrame();
  drawTable1();  
  drawTable2();  
  drawTable1();  
  drawTable2();  
  drawTable1();  
  drawTable2();  

  // TODO set cursor position to under the table

  return EXIT_SUCCESS;
}

void drawTable1() {

  byte value = 0;
  byte c;
  byte r;
  c = 0;
  r = 0;

  resetPtrs();

  for (r = 0; r < 16; ++r) {
    for (c = 0; c < 16; ++c) {
      byte row = r + ROW_OFFSET;
      byte col = c + COL_OFFSET;
      setChar(row, col, value, 0);
      ++value;
    }
  }  
}

void drawTable2() {
  byte* screenPtr = (byte*)7680; 
  byte* colorPtr = (byte*)38400; 


  byte value = 0;
  byte c;
  byte r;
  c = 0;
  r = 0;



  
  for (r = 0; r < ROW_OFFSET; ++r) {
    colorPtr += WHOLE_LINE;
    screenPtr += WHOLE_LINE;    
  }
  colorPtr += COL_OFFSET;
  screenPtr += COL_OFFSET;    

  for (r = 0; r < 16; ++r) {

    for (c = 0; c < 16; ++c) {

      (*screenPtr) = value;
      (*colorPtr) = 2;

      ++colorPtr;
      ++screenPtr;
      ++value;
    }
    #define NEXT_LINE ((byte)(WHOLE_LINE - 16))
    colorPtr += NEXT_LINE;
    screenPtr += NEXT_LINE;    
  }

}