#include <Servo.h>
#include <IRremote.h>

// Blinds closed is 250
// Blinds open is 850

Servo myservo;
int val;
int recvPin = 11;

IRrecv irrecv(recvPin);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  
  val = analogRead(0);
  Serial.println(val);
  if(val > 800) {
     blindsClosed(); 
  } 
  
  if (val < 300) {
     blindsOpen(); 
  }
  
  //val = map(val,250,850,0,179);
  //myservo.write(val);
  delay(200);
}

void blindsClosed (){
  myservo.write(179); 
}

void blindsOpen (){
  myservo.write(0); 
}
