#include "MPU9250.h"

MPU9250 IMU(0x68, 0);  //we are not actually using MPU9250. We are using MP9255....REEEEEEEEEEE
                       //modified the library for the use of MP9255 accel

float ax, ay, az, t;
int beginStatus;

void setup() {
    Serial.begin(115200);

    //start communication with the IMU
    beginStatus = IMU.begin(ACCEL_RANGE_2G,GYRO_RANGE_250DPS);

}

void loop() {
    if(beginStatus < 0) {
    delay(1000);
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    delay(5000);
  }
   else{
    IMU.getAccel(&ax, &ay, &az);      //there are functions to get both the accel and gyro at the same time
    IMU.getTemp(&t);                  //that would be better to represent motion since there are no time lag  

    Serial.print(ax,6);
    Serial.print("\t");
    Serial.print(ay,6);
    Serial.print("\t");
    Serial.print(az,6);
    Serial.print("\t");
    Serial.println(t,6);
    delay(50);
  }
}
