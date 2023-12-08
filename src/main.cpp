

#include <Arduino.h>


// pin definitions //


#define POT_PIN 32
#define POT_POW_PIN 25
#define POT_GND_PIN 26

#define SWITCH_1_PIN 21
#define SWITCH_2_PIN 22


// USE 8 WIRE CABLE, 6 LASERS 2 GROUNDS

#define LED_PIN 4

#define LASERS_A_PIN 4
#define LASERS_B_PIN 16
#define LASERS_C_PIN 17
#define LASERS_D_PIN 5
#define LASERS_E_PIN 18
#define LASERS_F_PIN 23



// global variables //

const bool debugFlag = true;     // remove const if debugging to be changed interactively. 

uint16_t potVal = 0;

// function declaration //

void updateSpeed(void);
void triggerLasers(void);

void allLasersOn(void);
void allLasersOff(void);

void  lasersOnOffMode(void);
void  lasersBlinkLaderMode(void);


void setup() {

  // pins to be used as power for other devices //
  pinMode(POT_POW_PIN, OUTPUT);
  digitalWrite(POT_POW_PIN, HIGH);

  pinMode(POT_GND_PIN, OUTPUT);
  digitalWrite(POT_GND_PIN, LOW);

  // pins for inputs //

  pinMode(POT_PIN, INPUT);

  // pins for outputs //

  pinMode(LED_PIN,OUTPUT);

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

  pinMode(LASERS_F_PIN, OUTPUT);
  digitalWrite(LASERS_F_PIN, LOW);

  // serial port //
  Serial.begin(115200);




}

void loop() {
  // put your main code here, to run repeatedly:
  updateSpeed();
  triggerLasers();


}

// function implementation //

void updateSpeed(void) {

  static unsigned long dt = 200;          // period for this task
  static unsigned long t0 = millis();
  unsigned long t = millis();

  if(t-t0 >= dt){
    potVal = analogRead(POT_PIN);
    if(debugFlag == true){
      Serial.print("potVal: ");
      Serial.println(potVal);
      t0 = t;
    }
  }

}

void triggerLasers(void){

  if(potVal > 4000){
    allLasersOff();
  }
  else{
    // lasersOnOffMode();
    lasersBlinkLaderMode();
  }

}


void lasersOnoffMode(void){
  // basic all on / off //
  if(potVal > 2000){
    // Serial.println("on");
    allLasersOn();
  }
  else{
    // Serial.println("off");
    allLasersOff();
  }
}


void  lasersBlinkLaderMode(void){
  unsigned long dt = potVal >> 2;            // period for blink lader changes depending on pot val
  static unsigned long t0 = millis();
  unsigned long t = millis();

  static uint8_t stateFlag = 0;            // number of stair in the lader (up to 4)

  if(t-t0 >= dt){

    if(stateFlag == 0){
      allLasersOff();
      digitalWrite(LASERS_A_PIN, HIGH);

    }
    if(stateFlag == 1){
      allLasersOff();
      digitalWrite(LASERS_B_PIN, HIGH);
    }
    if(stateFlag == 2){
      allLasersOff();
      digitalWrite(LASERS_C_PIN, HIGH);
    }
    if(stateFlag == 3){
      allLasersOff();
      digitalWrite(LASERS_D_PIN, HIGH);
    }
    if(stateFlag == 4){
      allLasersOff();
      digitalWrite(LASERS_E_PIN, HIGH);
    }
    if(stateFlag == 5){
      allLasersOff();
      digitalWrite(LASERS_F_PIN, HIGH);
    }
    Serial.println(stateFlag);
    stateFlag = stateFlag + 1;
    stateFlag = stateFlag % 6;

    t0 = t;

  }



}


void allLasersOn(void){
  digitalWrite(LED_PIN, HIGH);
}
void allLasersOff(void){
  digitalWrite(LED_PIN,LOW);
  digitalWrite(LASERS_A_PIN, LOW);
  digitalWrite(LASERS_B_PIN, LOW);
  digitalWrite(LASERS_C_PIN, LOW);
  digitalWrite(LASERS_D_PIN, LOW);
  digitalWrite(LASERS_E_PIN, LOW);
  digitalWrite(LASERS_F_PIN, LOW);

}
