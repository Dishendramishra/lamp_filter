#include <Servo.h>

Servo servo;
int sol1 = 7;
int sol2 = 8;


void setup() {
  servo.attach(9);
  servo.write(0);
  Serial.begin(9600);

  
  pinMode(sol1, OUTPUT); 
  pinMode(sol2, OUTPUT);
  digitalWrite(sol1,HIGH);
  digitalWrite(sol2,HIGH); 
  
}
void loop() {

  while (Serial.available() > 0) {

    String str = Serial.readString();

    if(str.startsWith("nd")){
      int angle = str.substring(2).toInt();
      Serial.print("Moving degrees: ");
      Serial.print(angle);
      Serial.print(" ... ");
      servo.write(angle);
      Serial.println("done");
    }
    else if(str.startsWith("sol1")){
      digitalWrite(sol1, !digitalRead(sol1));   
    }
    else if(str.startsWith("sol2")){
      digitalWrite(sol2, !digitalRead(sol2));   
    }
    else{
      Serial.println("Invalid Command!");
    }
  }
}
