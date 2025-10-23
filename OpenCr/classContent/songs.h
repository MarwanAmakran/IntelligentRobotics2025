#include "pitches.h"


// notes in the melody:
// Twinkle Twinkle Little Star (in C) — we houden de namen gelijk
int HappyBirthday[] = {
NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_C4,

  // Pre-chorus lift
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5,

  // Chorus (catchy, hoger register)
  NOTE_C5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5,
  NOTE_C5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_C4
};

int noteDurations_HappyBirthday[] = {
  4, 8, 8, 4, 8, 8, 4, 2,
  4, 8, 8, 4, 8, 8, 4, 2,

  // Pre-chorus
  8, 8, 8, 8, 4, 8, 8, 2,
  8, 8, 8, 8, 4, 2,

  // Chorus
  4, 8, 8, 4, 8, 8, 8, 4,
  4, 8, 8, 4, 8, 8, 4, 2
};


void playSequence(int melody[], int noteDurations[]){
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 25; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BDPIN_BUZZER, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(BDPIN_BUZZER);
  }
}