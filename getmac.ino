//sketch na zistenie MAC adresy dosky ESP32
#include <WiFi.h>

void setup() {
    Serial.begin(115200);
    delay(10);
    Serial.println();
}

void loop() {
 Serial.println("MAC adresa: ");
   Serial.println(WiFi.macAddress());
}
