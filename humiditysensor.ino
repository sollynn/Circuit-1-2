//HR202L , ESP 32 , 7 segment
//a = GPIO 25 ,b = GPIO 26 ,c= GPIO 27, d= GPIO 14 e= GPIO 13,g=GPIO 33
// 7-Segment (Common Cathode)
#include <Arduino.h>

#define HR202L_PIN 34  // ขา ADC ที่เชื่อมต่อกับ HR202L


const int segmentPins[7] = {25, 26, 27, 14, 12, 13, 33};


const byte digitPatterns[5][7] = {
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}  // 5
};

void displayDigit(int digit) {
    if (digit < 1 || digit > 5) return;  
    for (int i = 0; i < 7; i++) {
        digitalWrite(segmentPins[i], digitPatterns[digit - 1][i]);
    }
}

void setup() {
    Serial.begin(115200);
    for (int i = 0; i < 7; i++) {
        pinMode(segmentPins[i], OUTPUT);
        digitalWrite(segmentPins[i], LOW);
    }
}

void loop() {
    int sensorValue = analogRead(HR202L_PIN);  // อ่านค่า ADC
    int humidity = map(sensorValue, 1500, 3000, 100, 0);  // แปลงค่า ADC เป็น %

    Serial.print("HR202L Sensor Value: ");
    Serial.print(sensorValue);
    Serial.print(" - Humidity: ");
    Serial.print(humidity);
    Serial.println("%");

    int displayNumber = 1;

    if (humidity >= 0 && humidity <= 20) {
        displayNumber = 1;
    } else if (humidity > 20 && humidity <= 40) {
        displayNumber = 2;
    } else if (humidity > 40 && humidity <= 60) {
        displayNumber = 3;
    } else if (humidity > 60 && humidity <= 80) {
        displayNumber = 4;
    } else if (humidity > 80 && humidity <= 100) {
        displayNumber = 5;
    }

    displayDigit(displayNumber);  // แสดงตัวเลขที่กำหนด

    delay(1000); // หน่วงเวลา 1 วินาที
}
