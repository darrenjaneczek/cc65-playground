#include <stdio.h>
#include <stdlib.h>

#include "vic20.h"


int main(void)
{
  int i;
  int j;
  char volume;

  volume = 15;
  
	printf("Hello, world!\n");

  VIC.volume_color = volume | (VIC.volume_color & 0xF0);

  printf("Hello noise.");

  for (i = 0; i < 10000; ++i) {
    char noise;

    noise = i;
    //VIC.noise = noise | 0b10000000; 
    //VIC.voice1 = noise | 0b10000000; 
    //VIC.voice2 = noise | 0b10000000; 
    for (j = 0; j < 10; ++j) {
      volume = j;
      if (volume < 8) {
        volume = 8;
      }
      VIC.volume_color = volume | (VIC.volume_color & 0xF0);
    }

    VIC.voice3 = noise | 0b10000000; 
    //printf("Hello %i\n", VIC.noise);
  }

  VIC.noise = 0;
  VIC.voice1 = 0;
  VIC.voice2 = 0;
  VIC.voice3 = 0;

  return EXIT_SUCCESS;
}