#include <CustomBut.h>

#define DB_TIME 50
#define LONG_PRESS_INTERVAL 600
CustomBut but(2, DB_TIME, LONG_PRESS_INTERVAL);

int push = 0;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  push = but.update();
  if (push == 2){
    digitalWrite(13, LOW);
    Serial.println(push);
  }
  else if (push == 1) {
    digitalWrite(13, HIGH);
    Serial.println(push);
  }
  delay(20);
}
