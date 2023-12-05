

#include <Arduino.h>


// pin definitions //

#define POT_PIN 32
#define POT_POW_PIN 35
#define POT_GND_PIN 33

#define SWITCH_1_PIN 21
#define SWITCH_2_PIN 22


// USE 8 WIRE CABLE, 6 LASERS 2 GROUNDS
#define LASERS_A_PIN 4
#define LASERS_B_PIN 16
#define LASERS_C_PIN 17
#define LASERS_D_PIN 5
#define LASERS_E_PIN 18


// global variables //

const bool debugFlag = true;     // remove const if debugging to be changed interactively. 

uint16_t potVal = 0;

// function declaration //

void updateSpeed(void);
void triggerLasers(void);


void setup() {

  // pins to be used as power for other devices //
  pinMode(POT_POW_PIN, OUTPUT);
  digitalWrite(POT_POW_PIN, HIGH);

  pinMode(POT_GND_PIN, OUTPUT);
  digitalWrite(POT_POW_PIN, LOW);

  // pins for inputs //

  pinMode(POT_PIN, INPUT);

  // pins for outputs //

  pinMode(LASERS_A_PIN, OUTPUT);
  digitalWrite(LASERS_A_PIN, LOW);

  pinMode(LASERS_B_PIN, OUTPUT);
  digitalWrite(LASERS_B_PIN, LOW);

  pinMode(LASERS_C_PIN, OUTPUT);
  digitalWrite(LASERS_C_PIN, LOW);

  pinMode(LASERS_D_PIN, OUTPUT);
  digitalWrite(LASERS_D_PIN, LOW);

  pinMode(LASERS_E_PIN, OUTPUT);
  digitalWrite(LASERS_E_PIN, LOW);

  // serial port //
  Serial.begin(115200);




}

void loop() {
  // put your main code here, to run repeatedly:
  updateSpeed();


}

// function implementation //

void updateSpeed(void) {

  // static unsigned long t0 = millis();

  potVal = analogRead(POT_PIN);
  if(debugFlag == true){
    Serial.print("potVal: ");
    Serial.println(potVal);
  }

  delay(10);

}

void triggerLasers(void){

// basic all on / off //




}