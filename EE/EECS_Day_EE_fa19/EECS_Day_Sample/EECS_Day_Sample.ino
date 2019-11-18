/*
 * File: EECS_Day_Sample.ino
 * 
 * This code takes readings from photoresistors and based on which are covered up, plays different tones.
 * 
 * You have five tasks to do in this file:
 * 1) Add in the value of PRESSED_CUTOFF. You can find this by running the provided script.
 * 2) Implement the for loop to iterate over the sensors (i.e., 0, 1, 2, 3, ..., NUM_SENSORS - 1).
 * 3) Use analogRead on the value of PHOTOS[i].
 * 4) Fill in the condition to check that an entry in the readings array is below PRESSED_CUTOFF.
 * 5) Create the tone.
 */
#define BUZZER P2_3
#define NUM_SENSORS 6
#define LED P2_0
#define PRESSED_CUTOFF /* Task 1: Fill me in! (was 500) */
const int PHOTOS[4] = {P6_1, P6_2, P6_3, P6_4};
const int NOTES[4] = {440, 554, 659, 880};

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < NUM_SENSORS; i++) {
    pinMode(PHOTOS[i], INPUT);
  }
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  noTone(BUZZER);

  int readings[NUM_SENSORS];

  // index of the note being played, will be used to control the LED
  int note = -1;

  // collect data from photoresistors
  for (/* Task 2: Fill me in to iterate over the sensors */) {
    readings[i] = ; /* Task 3: Call analogRead on PHOTOS[i] to get the ith reading */

    // play a note if the photoresistor is covered up (low reading)
    if (/* Task 4: Fill me in with the condition to check that readings[i] is below the cutoff */) {
      /* Task 5: Add a call to "tone(BUZZER, NOTES[i]);" here to create the tone! */

      // keep track of the current note being played
      if (note < 0 || readings[i] < readings[note]) {
        note = i;
      }
    }
  }

  // vary the LED brightness based on the note being played
  // -1 represents no note being played
  int led_output = 255 * (note + 1) / 6;
  analogWrite(LED, led_output);

  delay(10);
}
