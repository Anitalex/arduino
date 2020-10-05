const int valve = 13;
const int sensor = A0;
int input_val;

void setup() {
  Serial.begin(9600);
  pinMode(valve, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop() {
 input_val = analogRead(sensor);
 Serial.print("input sensor reads");
 Serial.println(input_val);
 if (input_val <= 10)
 {digitalWrite(valve, HIGH);}
 else
 {digitalWrite(valve, LOW);}


}

