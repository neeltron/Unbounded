#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Trikuldham";
const char* password = "jaihanuman1981";
const int lF = 5;
const int lB = 4;
const int rF = 0;
const int rB = 2;

void setup() {
  Serial.begin(9600);
  pinMode(lF, OUTPUT);
  pinMode(lB, OUTPUT);
  pinMode(rF, OUTPUT);
  pinMode(rB, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Connecting..");
    delay(100);
  }
}
void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://tangled.ae/Spellbound-Robot/exit.php");
    int httpCode = http.GET();
    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println(payload);
      if(payload == "0") {
        digitalWrite(lF, LOW);
        digitalWrite(lB, LOW);
        digitalWrite(rF, LOW);
        digitalWrite(rB, LOW);
      }
      else if (payload == "1") {
        digitalWrite(lF, LOW);
        digitalWrite(lB, HIGH);
        digitalWrite(rF, LOW);
        digitalWrite(rB, HIGH);
      }
      else if(payload == "2") {
        digitalWrite(lF, HIGH);
        digitalWrite(lB, LOW);
        digitalWrite(rF, LOW);
        digitalWrite(rB, HIGH);
      }
      else if(payload == "3") {
        digitalWrite(lF, LOW);
        digitalWrite(lB, HIGH);
        digitalWrite(rF, HIGH);
        digitalWrite(rB, LOW);
      }
      else if(payload == "4") {
        digitalWrite(lF, HIGH);
        digitalWrite(lB, LOW);
        digitalWrite(rF, HIGH);
        digitalWrite(rB, LOW);
      }
    }
    http.end();
  }
  delay(1000);
}
