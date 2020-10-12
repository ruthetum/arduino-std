#include "pitches.h"

const int SPEAKER = 9;
const int DO = 8;
const int RAE = 7;
const int ME = 6;
const int FA = 5;
const int SOL = 4;
const int RA = 3;
const int SI = 2;

int notes[] = {
  NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_G4,
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, 0,
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4, 
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_C4, 0
};

int times[] = {
  250, 250, 250, 250, 250, 250,
  250, 250, 250, 500, 250,
  250, 250, 250, 250, 250, 250,
  250, 250, 250, 500, 250
};

int len = sizeof(notes) / sizeof(int);

void lightOn(int i) {
  int t_note;
  if (notes[i] == NOTE_C4) {
    t_note = DO;
  } else if (notes[i] == NOTE_D4) {
    t_note = RAE;
  } else if (notes[i] == NOTE_E4) {
    t_note = ME;
  } else if (notes[i] == NOTE_F4) {
    t_note = FA;
  } else if (notes[i] == NOTE_G4) {
    t_note = SOL;
  } else if (notes[i] == NOTE_A4) {
    t_note = RA;
  } else if (notes[i] == NOTE_B4) {
    t_note = SI;
  } else {
    t_note = -1;
  }
  if (t_note == -1) {
    delay(times[i]);
    return;
  }
  digitalWrite(t_note, HIGH);
  delay(times[i]);
  digitalWrite(t_note, LOW);
}

void setup() {
  pinMode(DO, OUTPUT);
  pinMode(RAE, OUTPUT);
  pinMode(ME, OUTPUT);
  pinMode(FA, OUTPUT);
  pinMode(SOL, OUTPUT);
  pinMode(RA, OUTPUT);
  pinMode(SI, OUTPUT);
}

void loop() {
  for (int i=0; i<len; i++) {
    tone(SPEAKER, notes[i], times[i]);
    lightOn(i);
  }
}
