// This source code file was initially created by an AI
// It had many errors, so I corrected them, and altered their
// original melody.
// This is very much a hackjob.

#include <peekpoke.h>
#include <stdio.h>
#include <conio.h>

// Define SID register addresses
#define SID_FREQ_LO 0xD400
#define SID_FREQ_HI 0xD401
#define SID_PULSE_WAVE_DUTY_CYCLE_LO 0xD402
#define SID_PULSE_WAVE_DUTY_CYCLE_HI 0xD403
#define SID_CONTROL_VOICE_1 0xD404
#define SID_ATTACK_DECAY 0xD405
#define SID_SUSTAIN_RELEASE 0xD406

#define SID_FILTER_MODE_AND_VOLUME 0xd418

// Define notes and corresponding frequencies
#define C4 262
#define CS4 277
#define D4 294
#define DS4 311
#define E4 330
#define F4 349
#define FS4 370
#define G4 392
#define GS4 415
#define A4 440
#define AS4 466
#define B4 494

#define C5 523
#define CS5 555
#define D5 588
#define DS5 623
#define E5 660
#define F5 699
#define FS5 740
#define G5 784
#define GS5 831
#define A5 880
#define AS5 933
#define B5 988

// Define note duration in milliseconds
#define QUARTER_NOTE 250

#define byte unsigned char

#define poke POKE

#define CYCLES_FOR_WAIT_TIME 16

void delay(unsigned short waitTime) {
  unsigned char cycles = CYCLES_FOR_WAIT_TIME;

  while (waitTime) {

    cycles--;
    if (!cycles) {
      // printf("Wait %d\n", waitTime);
      waitTime--;
      cycles = CYCLES_FOR_WAIT_TIME;
    }
  }
}

void play_note(unsigned short freq, unsigned short duration) {



byte loFreq = freq & (byte)0xFF;
byte hiFreq = freq >> 8;

(*((byte*) 0xD020))++;


// Set frequency registers
//poke(0xD021, 0);


poke(SID_FREQ_LO, loFreq);
poke(SID_FREQ_HI, hiFreq);

// Set attack, decay, sustain, and release values
poke(SID_ATTACK_DECAY, 0x08);
poke(SID_SUSTAIN_RELEASE, 0x21);

// Set waveform to saw
// Enable voice and set volume
poke(SID_CONTROL_VOICE_1, 0b00100001);
// pluck quick



// Wait for duration
delay(duration);
poke(SID_CONTROL_VOICE_1, 0b00100000);
// Disable voice




}

void main() {

byte octave = 1;

poke(SID_FILTER_MODE_AND_VOLUME,0x0f);

for (octave = 5; octave < 16; ++octave) {

  printf("Octave %d\n", octave - 1 + 4);
// Play C4, G4, A4, F4, E4, D4
play_note(F4*octave, 4*QUARTER_NOTE);
play_note(C4*octave, QUARTER_NOTE);
play_note(E4*octave, QUARTER_NOTE);
play_note(G4*octave, QUARTER_NOTE);
play_note(C5*octave, QUARTER_NOTE);
play_note(F4*octave, 4*QUARTER_NOTE);

play_note(D4*octave, QUARTER_NOTE * 2);
play_note(E4*octave, QUARTER_NOTE * 2);
play_note(A4*octave, QUARTER_NOTE * 2);
play_note(D4*octave, QUARTER_NOTE * 6);

play_note(C4*octave, QUARTER_NOTE / 2);
play_note(E4*octave, QUARTER_NOTE / 2);
play_note(G4*octave, QUARTER_NOTE / 2);
play_note(C5*octave, QUARTER_NOTE / 2);

play_note(C4*octave, QUARTER_NOTE / 4);
play_note(E4*octave, QUARTER_NOTE / 4);
play_note(G4*octave, QUARTER_NOTE / 4);
play_note(C5*octave, QUARTER_NOTE / 4);

play_note(C4*octave, QUARTER_NOTE / 4);
play_note(E4*octave, QUARTER_NOTE / 4);
play_note(G4*octave, QUARTER_NOTE / 4);
play_note(C5*octave, QUARTER_NOTE / 4);

play_note(C4*octave, QUARTER_NOTE / 4);
play_note(E4*octave, QUARTER_NOTE / 4);
play_note(G4*octave, QUARTER_NOTE / 4);
play_note(C5*octave, QUARTER_NOTE / 4);

play_note(C4*octave, QUARTER_NOTE / 4);
play_note(E4*octave, QUARTER_NOTE / 4);
play_note(G4*octave, QUARTER_NOTE / 4);
play_note(C5*octave, QUARTER_NOTE / 4);

play_note(C4*octave, QUARTER_NOTE / 4);
play_note(E4*octave, QUARTER_NOTE / 4);
play_note(G4*octave, QUARTER_NOTE / 4);
play_note(C5*octave, QUARTER_NOTE / 4);

play_note(C4*octave, QUARTER_NOTE / 4);
play_note(E4*octave, QUARTER_NOTE / 4);
play_note(G4*octave, QUARTER_NOTE / 4);
play_note(C5*octave, QUARTER_NOTE / 4);

play_note(F4*octave, QUARTER_NOTE);
play_note(E4*octave, QUARTER_NOTE);
play_note(D4*octave, QUARTER_NOTE);
play_note(C4*octave, QUARTER_NOTE);

play_note(C4*octave, QUARTER_NOTE / 2);
play_note(C4*octave, QUARTER_NOTE / 2);

play_note(F4*octave, QUARTER_NOTE * 4);

play_note(D4*octave, QUARTER_NOTE / 2);
play_note(D4*octave, QUARTER_NOTE / 2);

play_note(C4*octave, QUARTER_NOTE * 4);

play_note(E4*octave, QUARTER_NOTE / 2);
play_note(E4*octave, QUARTER_NOTE / 2);

play_note(C5*octave, QUARTER_NOTE * 4);


// Play G4, F4, E4, D4
play_note(G4*octave, QUARTER_NOTE);
play_note(F4*octave, QUARTER_NOTE);
play_note(E4*octave, QUARTER_NOTE);
play_note(D4*octave, QUARTER_NOTE);

// Play G4, A4, F4, E4, D4, C4
play_note(G4*octave, QUARTER_NOTE);
play_note(A4*octave, QUARTER_NOTE);
play_note(F4*octave, QUARTER_NOTE);
play_note(E4*octave, QUARTER_NOTE);
play_note(D4*octave, QUARTER_NOTE);
play_note(C4*octave, QUARTER_NOTE);
}


}