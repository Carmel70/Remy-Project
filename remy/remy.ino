#include <Servo.h>
bool simMode = true;
// Define pin numbers
int BUTTON_PIN = 13;
//const int servoLPin  = 3;
//const int servoRPin  = 5;
const int redOne = 12;
const int greenOne = 11;
const int redTwo = 9;
const int greenTwo = 10;

// Create servo object
Servo servoL;
Servo servoR;

void setup() {

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  Serial.begin(9600);
  
  pinMode(redOne, OUTPUT);
  pinMode(greenOne, OUTPUT);
  pinMode(redTwo, OUTPUT);
  pinMode(greenTwo, OUTPUT);
  
  // Attach the servo to its pin and set it to the starting position (0 degrees)
  /*
  servoL.attach(servoLPin);
  servoL.write(180);
  
  servoR.attach(servoRPin);
  servoR.write(0);
  */
  
  digitalWrite(redOne, LOW);
  analogWrite(greenOne, 0);
  digitalWrite(redTwo, LOW);
  analogWrite(greenTwo, 0);
}

void loop() {
  // Read the state of the copper button
  int buttonStateOne = digitalRead(BUTTON_PIN);
  
  // If the button reads LOW, it means contact has been made to GND
  if (buttonStateOne != LOW) {
    digitalWrite(redOne, HIGH);
    analogWrite(greenOne, 150);
    digitalWrite(redTwo, HIGH);
    analogWrite(greenTwo, 150);
    //servoL.write(135);
    //servoR.write(45);
    Serial.println("Button Pushed.");
  } 
  else {
    digitalWrite(redOne, LOW);
    analogWrite(greenOne, 0);
    digitalWrite(redTwo, LOW);
    analogWrite(greenTwo, 0);
    //servoL.write(180);
    //servoR.write(0);
    Serial.println("Button Released.");
  }
}
