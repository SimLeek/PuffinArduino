#include <Arduino.h>
#include <MPU9250_asukiaaa.h>

typedef union{
        float f;
        char bytes[4];
} SerialFloat;

MPU9250 mySensor;
SerialFloat aX, aY, aZ;
SerialFloat gX, gY, gZ;
SerialFloat mX, mY, mZ;

void setup() {
    Wire.begin();
    mySensor.setWire(&Wire);
    mySensor.beginAccel();
    mySensor.beginGyro();
    mySensor.beginMag();

    Serial.begin(9600);
    aX.f = 3.14159;
    Serial.write(aX.bytes, 4);
}

void loop() {
    mySensor.accelUpdate();
    aX.f = mySensor.accelX();
    aY.f = mySensor.accelY();
    aZ.f = mySensor.accelZ();
    mySensor.gyroUpdate();
    gX.f = mySensor.gyroX();
    gY.f = mySensor.gyroY();
    gZ.f = mySensor.gyroZ();
    mySensor.magUpdate();
    mX.f = mySensor.magX();
    mY.f = mySensor.magY();
    mZ.f = mySensor.magZ();

    Serial.write("I");
    Serial.write("\na");
    Serial.write(aX.bytes, 4);Serial.write(aY.bytes, 4);Serial.write(aZ.bytes, 4);
    Serial.write("\ng");
    Serial.write(gX.bytes, 4);Serial.write(gY.bytes, 4);Serial.write(gZ.bytes, 4);
    Serial.write("\nm");
    Serial.write(mX.bytes, 4);Serial.write(mY.bytes, 4);Serial.write(mZ.bytes, 4);
    Serial.write("\n");
}
