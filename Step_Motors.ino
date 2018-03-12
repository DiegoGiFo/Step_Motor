#define EN        8

//Direction pin
#define X_DIR     5
#define Y_DIR     6
//#define Z_DIR     7

//Step pin
#define X_STP     2
#define Y_STP     3
//#define Z_STP     4


//DRV8825
int delayTime=600; //Delay between each pause (uS)
int stps=2000;// Steps to move


void step(boolean dir, byte dirPin, byte stepperPin, int steps)

{

  digitalWrite(dirPin, dir);

  delay(100);

  for (int i = 0; i < steps; i++) {

    digitalWrite(stepperPin, HIGH);

    delayMicroseconds(delayTime);

    digitalWrite(stepperPin, LOW);

    delayMicroseconds(delayTime);

  }

}

void setup(){

  pinMode(X_DIR, OUTPUT); pinMode(X_STP, OUTPUT);

  pinMode(Y_DIR, OUTPUT); pinMode(Y_STP, OUTPUT);


  pinMode(EN, OUTPUT);

  digitalWrite(EN, LOW);

}

void loop(){

  step(false, X_DIR, X_STP, stps); //X, Clockwise
  step(false, Y_DIR, Y_STP, stps);


  delay(100);

  step(true, X_DIR, X_STP, stps); //X, Counterclockwise
  step(true, Y_DIR, Y_STP, stps); //Y, Counterclockwise


  delay(100);

}
