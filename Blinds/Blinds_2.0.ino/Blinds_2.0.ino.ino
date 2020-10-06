#include <Servo.h>
Servo myServo;

int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13;
int angle;

void setup() {
  // tell the board what pin the servo is plugged into
  myServo.attach(9);
  // tell the board to output to the serial monitor and at what rate
  Serial.begin(9600);

  // Turn on the LED on the board during setup
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // Callibrate before starting
  while (millis() < 5000){
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    } 

    if (sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }
  // Now that setup is done turn off the LED and let it begin
  digitalWrite(ledPin, LOW);
}

void loop() {

  // Capture the input of the light sensor and put it into the variable sensorValue
  sensorValue = analogRead(A0);

  // Output the sensorValue to the serial monitor
  Serial.print("sensorValue: ");
  Serial.print(sensorValue);

  // Set the angle of the servo motor based on the value in the variable sensorValue. 
  // This takes 5 arguments.  
  // The first is the current value in sensorValue
  // The second and third are the range of values that could be found
  // The fourth and fifth are the values to map the the sensorValue
  // The sensorValue that could be between 0 and 1023 are then mapped to its equivalent value in the range of 0 and 359
  angle = map(sensorValue,0,1023,0,359);

  // Output the angle to the serial monitor
  Serial.print(", angle: ");
  Serial.print(angle);
  Serial.print('\n');

  // Tell the servo what angle to move to
  myServo.write(angle);
  delay(15);
}
