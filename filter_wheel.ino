#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(9);
  servo.write(0);
  Serial.begin(9600);
  
}
void loop() {

  while (Serial.available() > 0) {
    int angle = Serial.parseInt();
    servo.write(angle);
    Serial.print("Moved degrees: ");
    Serial.println(angle);
    }
}
