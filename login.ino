#include "esp_wpa2.h"
#include <WiFi.h>
String line;
const char* ssid = "INTRAK"; // wifi siet
#define EAP_IDENTITY "meno.priezvisko" //eap identita 
#define EAP_PASSWORD "heslo" //heslo
#define MENOPC "MenoPCzUSERPANELU" //https://userpanel.pcklub.sk/

void setup() {
    Serial.begin(115200);
    delay(10);
    Serial.println();
    Serial.print("Pripajam sa na: ");
    Serial.println(ssid);
    WiFi.disconnect(true); 
    esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY));
    esp_wifi_sta_wpa2_ent_set_username((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY));
    esp_wifi_sta_wpa2_ent_set_password((uint8_t *)EAP_PASSWORD, strlen(EAP_PASSWORD));
    esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT();
    esp_wifi_sta_wpa2_ent_enable(&config);
   Serial.println("MAC adresa: ");
   Serial.println(WiFi.macAddress());
    WiFi.begin(ssid); //pripajanie
 WiFi.setHostname(MENOPC);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi pripojene");
    Serial.println("IP addresa: ");
    Serial.println(WiFi.localIP());
}
const char* host = "arduino.php5.sk"; //server na ktory sa pripajame (domena)

void loop() {
    delay(5000);

    Serial.print("Pripajam sa na server: ");
    Serial.println(host);

    WiFiClient client;
    if (!client.connect(host, 80)) { //pripajanie na server pod HTTP
        Serial.println("connection failed");
    }
    String url = "/rele/rele1.txt";    //request na subor pod serverom
    Serial.print("Requesting URL: ");
    Serial.println(url);
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
        if (millis() - timeout > 5000) {
            Serial.println(">>> Timeout prebehol, response sa nevratila !");
            client.stop();
        }
    }
    while(client.available()) {
         line = client.readStringUntil('\n'); //citanie po posledny riadok
        Serial.println(line); //ulozenie premennej z response
    
    }
    
    if (line=="VYP"){
      Serial.println("Vypnuty spotrebic");
      }else if (line=="ZAP"){
      Serial.println("Zapnuty spotrebic");
      }
    Serial.println();
    Serial.println("Ukoncene spojenie");
}
