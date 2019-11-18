#define BUZZER P2_3
#define PHOTORES P6_6
#define LED P2_0

// define notes for buzzer
int notes[] = {440, 494, 554, 587, 659, 740, 831, 880};
int C_1 = notes[0];
int D_1 = notes[1];
int E_1 = notes[2];
int F_1 = notes[3];
int G_1 = notes[4];
int A_1 = notes[5];

int twinklestar[] = {
  C_1, C_1, G_1, G_1, A_1, A_1, G_1, G_1, F_1, F_1, E_1, E_1, D_1, D_1, C_1, C_1, 
  G_1, G_1, F_1, F_1, E_1, E_1, D_1, D_1, G_1, G_1, F_1, F_1, E_1, E_1, D_1, D_1, 
  C_1, C_1, G_1, G_1, A_1, A_1, G_1, G_1, F_1, F_1, E_1, E_1, D_1, D_1, C_1, C_1
};
int num_notes = sizeof(twinklestar) / sizeof(twinklestar[0]);

void setup() { 
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

  pinMode(PHOTORES, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

//   Running Part 1
//   blink_led(LED, 3, 200);
  
//   Running Part 2
//   fade_led(LED, 0, 255, 1000);
//   fade_led(LED, 255, 0, 1000);
  

//   Running Part 3
//   sensor_data(PHOTORES);
//   delay(200);

//   Running Part 4
//   play_buzzer(BUZZER, C_1, 200);
//   delay(1000);

//   Running Part 4.1
//   play_song(BUZZER, twinklestar, num_notes);
//   delay(5000);

//   Running Part 5
//   buzzer_tone_shift(BUZZER, PHOTORES);

}

void blink_led(int pin, int times, int delay_ms) {
  /*
   * PART 1: BLINK LED
   * In this part, you will be turning an LED on and off a specified number of times
   * Hint: Use digitalWrite(pin, value) and delay(milliseconds)
   */
  for (int i = 0; i < times; i++) {

    /* YOUR CODE HERE */
    
//     Uncomment below for solution code!
//     digitalWrite(pin, HIGH);
//     delay(delay_ms);
//     digitalWrite(pin, LOW);
//     delay(delay_ms);
  }
}

void fade_led(int pin, int start_brightness, int end_brightness, int total_time_ms) {
  /*
   * PART 2: FADE LED
   * In this part, you will be fading an LED over a specified time interval
   * You will be using analogWrite(pin, value) with a value from 0 to 255
   * 0 turns the LED completely off, and 255 turns the LED completely on
   */

  // Determines the delay after each stage of the fading process
  int delay_ms = total_time_ms / (abs(end_brightness - start_brightness) / 16);

  /* YOUR CODE HERE
   * HINT: make two for loops, one for when the brightness is increasing and one for when it is decreasing
   */
   
//  Uncomment below for solution code!
//  if (end_brightness > start_brightness) {
//    for (int i = start_brightness; i < end_brightness; i += 16) {
//      analogWrite(pin, i);
//      delay(delay_ms);
//    }
//  } else {
//    for (int i = start_brightness; i > end_brightness; i -= 16) {
//      analogWrite(pin, i);
//      delay(delay_ms);
//    }
//  }
   
}

int sensor_data(int pin) {
  /*
   * PART 3: read data from a photoresistor
   * You'll be using analogRead to get data and then 
   * print the data to the serial monitor using Serial.println(...)
   */

  /* YOUR CODE HERE */ 
//   Uncomment below for solution code!
//   int data = analogRead(pin);
//   Serial.println(data);
//   return data;
}

void play_buzzer(int pin, int tone_freq, int length_ms) {
  /*
   * PART 4: Play a sound using the buzzer
   * You'll use the tone(pin, freq) function, as well as a delay
   * Remember to call noTone before playing another note!
   */

   /* YOUR CODE HERE */

   // Uncomment below for solution code! 
//   tone(pin, tone_freq);
//   delay(length_ms);
//   noTone(pin);
}

void play_song(int pin, int* notes, int count) {
  /*
   * PART 4.1: play a sequence of notes to make a song!
   */
  for (int i = 0; i < count; i++) {
    /* YOUR CODE HERE
     *  HINT: Use play_buzzer here!
     */

//     Uncomment below for solution code!
//     Serial.println(i);
//     play_buzzer(pin, notes[i], 300);
//     delay(10);
  }

  /*
   * CHALLENGE: modify play_song to incorporate notes and rests!
   * (and/or notes of different lengths)
   */
   
}

void buzzer_tone_shift(int pin, int inputPin) {
  /* 
   * PART 5: Vary what tone the buzzer plays based on the photoresistor output
   */

   int photo = 0/* YOUR CODE HERE */;

   /* 
    * HINT: the photoresistor data will be between 0 and 4096.
    * The frequency should vary linearly between 400 and 900 for inputs in that range.
    */
   int freq = 0/* YOUR CODE HERE */;

//   Uncomment below for solution code! 
//   photo = analogRead(inputPin);
//   Serial.println(photo);
//   freq = photo + 400;
//
//  play_buzzer(pin, freq, 10);

}

