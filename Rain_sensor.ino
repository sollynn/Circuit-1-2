#include <Arduino.h>
//rain sensor
#define RAIN_SENSOR_DIGITAL 32 // ขา Digital (D0)

void setup() {
    Serial.begin(115200);
    pinMode(RAIN_SENSOR_DIGITAL, INPUT); // ตั้งค่า D0 เป็นอินพุต
}

void loop() {
    int rainStatus = digitalRead(RAIN_SENSOR_DIGITAL); // อ่านค่าจาก D0

    if (rainStatus == LOW) {
        Serial.println("Detected");
    } else {
        Serial.println("Dry");
    }

    delay(1000); 
}
