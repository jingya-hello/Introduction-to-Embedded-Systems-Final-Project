#include <Arduino_FreeRTOS.h>
#include <Servo.h>

#define  C0 16.35
#define Db0 17.32
#define D0  18.35
#define Eb0 19.45
#define E0  20.60
#define F0  21.83
#define Gb0 23.12
#define G0  24.50
#define Ab0 25.96
#define LA0 27.50
#define Bb0 29.14
#define B0  30.87
#define C1  32.70
#define Db1 34.65
#define D1  36.71
#define Eb1 38.89
#define E1  41.20
#define F1  43.65
#define Gb1 46.25
#define G1  49.00
#define Ab1 51.91
#define LA1 55.00
#define Bb1 58.27
#define B1  61.74
#define C2  65.41
#define Db2 69.30
#define D2  73.42
#define Eb2 77.78
#define E2  82.41
#define F2  87.31
#define Gb2 92.50
#define G2  98.00
#define Ab2 103.83
#define LA2 110.00
#define Bb2 116.54
#define B2  123.47
#define C3  130.81
#define Db3 138.59
#define D3  146.83
#define Eb3 155.56
#define E3  164.81
#define F3  174.61
#define Gb3 185.00
#define G3  196.00
#define Ab3 207.65
#define LA3 220.00
#define Bb3 233.08
#define B3  246.94
#define C4  261.63
#define Db4 277.18
#define D4  293.66
#define Eb4 311.13
#define E4  329.63
#define F4  349.23
#define Gb4 369.99
#define G4  392.00
#define Ab4 415.30
#define LA4 440.00
#define Bb4 466.16
#define B4  493.88
#define C5  523.25
#define Db5 554.37
#define D5  587.33
#define Eb5 622.25
#define E5  659.26
#define F5  698.46
#define Gb5 739.99
#define G5  783.99
#define Ab5 830.61
#define LA5 880.00
#define Bb5 932.33
#define B5  987.77
#define C6  1046.50
#define Db6 1108.73
#define D6  1174.66
#define Eb6 1244.51
#define E6  1318.51
#define F6  1396.91
#define Gb6 1479.98
#define G6  1567.98
#define Ab6 1661.22
#define LA6 1760.00
#define Bb6 1864.66
#define B6  1975.53
#define C7  2093.00
#define Db7 2217.46
#define D7  2349.32
#define Eb7 2489.02
#define E7  2637.02
#define F7  2793.83
#define Gb7 2959.96
#define G7  3135.96
#define Ab7 3322.44
#define LA7 3520.01
#define Bb7 3729.31
#define B7  3951.07
#define C8  4186.01
#define Db8 4434.92
#define D8  4698.64
#define Eb8 4978.03
// DURATION OF THE NOTES
#define BPM 120    //  you can change this value changing all the others
#define H 2*Q //half 2/4
#define Q 60000/BPM //quarter 1/4 
#define E Q/2   //eighth 1/8
#define S Q/4 // sixteenth 1/16
#define W 4*Q // whole 4/4

int pr;
//Servo
Servo wipe1;
Servo wipe2;

// RGB pin
const int R = 3;
const int G = 5;
const int B = 6;
void setup() {
  pinMode(8, OUTPUT);
  //light
  pinMode(A2, INPUT);

  //Servo
  wipe1.attach(A0);

  //servo
  wipe2.attach(A1);

  xTaskCreate(singing, (const portCHAR *)"singing", 128, NULL, 1, NULL);
  xTaskCreate(wiping1, (const portCHAR *)"wiping1", 128, NULL, 1, NULL);
  xTaskCreate(wiping2, (const portCHAR *)"wiping2", 128, NULL, 1, NULL);
  xTaskCreate(light, (const portCHAR *)"light", 80, NULL, 1, NULL);
}
void loop() {

}
void light(void *pvParameters) {
  (void) pvParameters;
  for ( ;; ) {
    pr = analogRead(A2);
    if (pr > 800) {
      analogWrite(R, 0);
      analogWrite(G, 0);
      analogWrite(B, 0);
    }
    else {
      rainbow();
    }
  }
}
void rainbow() {
  //red
  analogWrite(R, 255);
  analogWrite(G, 0);
  analogWrite(B, 0);
  delay(50);
  //orange
  analogWrite(R, 255);
  analogWrite(G, 165);
  analogWrite(B, 0);
  delay(50);
  //yellow
  analogWrite(R, 255);
  analogWrite(G, 255);
  analogWrite(B, 0);
  delay(50);
  //green
  analogWrite(R, 0);
  analogWrite(G, 255);
  analogWrite(B, 0);
  delay(50);
  //blue
  analogWrite(R, 0);
  analogWrite(G, 0);
  analogWrite(B, 255);
  delay(50);
  //indigo
  analogWrite(R, 43);
  analogWrite(G, 0);
  analogWrite(B, 255);
  delay(50);
  //purple
  analogWrite(R, 87);
  analogWrite(G, 0);
  analogWrite(B, 255);
  delay(50);
}
void wiping1(void *pvParameters) {
  (void) pvParameters;
  for ( ;; ) {
    for (int i = 0; i < 180; i++) {
      wipe1.write(i);
      delay(2);
      //delay(2);
    }
    for (int i = 180; i > 0; i--) {
      wipe1.write(i);
      delay(2);
      //delay(2);
    }
  }
}
void wiping2(void *pvParameters) {
  (void) pvParameters;
  for ( ;; ) {

    for (int i = 0; i < 180; i++) {
      wipe2.write(i);
      delay(2);
      //delay(2);
    }
    for (int i = 180; i > 0; i--) {
      wipe2.write(i);
      delay(2);
      //delay(2);
    }
  }
}
void singing(void *pvParameters) {
  (void) pvParameters;
  for ( ;; ) {
    tone(8, LA3, Q);
    delay(1 + Q);
    tone(8, LA3, Q);
    delay(1 + Q);
    tone(8, LA3, Q);
    delay(1 + Q);
    tone(8, F3, E + S);
    delay(1 + E + S);
    tone(8, C4, S);
    delay(1 + S);

    tone(8, LA3, Q);
    delay(1 + Q);
    tone(8, F3, E + S);
    delay(1 + E + S);
    tone(8, C4, S);
    delay(1 + S);
    tone(8, LA3, H);
    delay(1 + H);

    tone(8, E4, Q);
    delay(1 + Q);
    tone(8, E4, Q);
    delay(1 + Q);
    tone(8, E4, Q);
    delay(1 + Q);
    tone(8, F4, E + S);
    delay(1 + E + S);
    tone(8, C4, S);
    delay(1 + S);

    tone(8, Ab3, Q);
    delay(1 + Q);
    tone(8, F3, E + S);
    delay(1 + E + S);
    tone(8, C4, S);
    delay(1 + S);
    tone(8, LA3, H);
    delay(1 + H);

    tone(8, LA4, Q);
    delay(1 + Q);
    tone(8, LA3, E + S);
    delay(1 + E + S);
    tone(8, LA3, S);
    delay(1 + S);
    tone(8, LA4, Q);
    delay(1 + Q);
    tone(8, Ab4, E + S);
    delay(1 + E + S);
    tone(8, G4, S);
    delay(1 + S);

    tone(8, Gb4, S);
    delay(1 + S);
    tone(8, E4, S);
    delay(1 + S);
    tone(8, F4, E);
    delay(1 + E);
    delay(1 + E);
    tone(8, Bb3, E);
    delay(1 + E);
    tone(8, Eb4, Q);
    delay(1 + Q);
    tone(8, D4, E + S);
    delay(1 + E + S);
    tone(8, Db4, S);
    delay(1 + S);

    tone(8, C4, S);
    delay(1 + S);
    tone(8, B3, S);
    delay(1 + S);
    tone(8, C4, E);
    delay(1 + E);
    delay(1 + E);
    tone(8, F3, E);
    delay(1 + E);
    tone(8, Ab3, Q);
    delay(1 + Q);
    tone(8, F3, E + S);
    delay(1 + E + S);
    tone(8, LA3, S);
    delay(1 + S);

    tone(8, C4, Q);
    delay(1 + Q);
    tone(8, LA3, E + S);
    delay(1 + E + S);
    tone(8, C4, S);
    delay(1 + S);
    tone(8, E4, H);
    delay(1 + H);

    tone(8, LA4, Q);
    delay(1 + Q);
    tone(8, LA3, E + S);
    delay(1 + E + S);
    tone(8, LA3, S);
    delay(1 + S);
    tone(8, LA4, Q);
    delay(1 + Q);
    tone(8, Ab4, E + S);
    delay(1 + E + S);
    tone(8, G4, S);
    delay(1 + S);

    tone(8, Gb4, S);
    delay(1 + S);
    tone(8, E4, S);
    delay(1 + S);
    tone(8, F4, E);
    delay(1 + E);
    delay(1 + E);
    tone(8, Bb3, E);
    delay(1 + E);
    tone(8, Eb4, Q);
    delay(1 + Q);
    tone(8, D4, E + S);
    delay(1 + E + S);
    tone(8, Db4, S);
    delay(1 + S);

    tone(8, C4, S);
    delay(1 + S);
    tone(8, B3, S);
    delay(1 + S);
    tone(8, C4, E);
    delay(1 + E);
    delay(1 + E);
    tone(8, F3, E);
    delay(1 + E);
    tone(8, Ab3, Q);
    delay(1 + Q);
    tone(8, F3, E + S);
    delay(1 + E + S);
    tone(8, C4, S);
    delay(1 + S);

    tone(8, LA3, Q);
    delay(1 + Q);
    tone(8, F3, E + S);
    delay(1 + E + S);
    tone(8, C4, S);
    delay(1 + S);
    tone(8, LA3, H);
    delay(1 + H);

    delay(2 * H);
  }
}
