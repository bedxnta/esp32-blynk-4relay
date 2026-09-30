#define BLYNK_TEMPLATE_ID "TMPL3KAaAn0t7"
#define BLYNK_TEMPLATE_NAME "IOT LED 1"
#define BLYNK_AUTH_TOKEN "hcvxTuTRNmyUFb1VmFUV3sbu0PY-HqiA"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Replace with your WiFi credentials
char ssid[] = "DULA";
char pass[] = "1234567890";

// Relay pins
#define RELAY1_PIN 13
#define RELAY2_PIN 12
#define RELAY3_PIN 14
#define RELAY4_PIN 27

void setup()
{
  // Debug console
  Serial.begin(115200);

  // Setup relay pins
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  pinMode(RELAY3_PIN, OUTPUT);
  pinMode(RELAY4_PIN, OUTPUT);

  // Set relays OFF initially
  digitalWrite(RELAY1_PIN, LOW);
  digitalWrite(RELAY2_PIN, LOW);
  digitalWrite(RELAY3_PIN, LOW);
  digitalWrite(RELAY4_PIN, LOW);

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// Relay 1 control (V0)
BLYNK_WRITE(V0)
{
  int relayState = param.asInt();
  digitalWrite(RELAY1_PIN, relayState);
}

// Relay 2 control (V1)
BLYNK_WRITE(V1)
{
  int relayState = param.asInt();
  digitalWrite(RELAY2_PIN, relayState);
}

// Relay 3 control (V2)
BLYNK_WRITE(V2)
{
  int relayState = param.asInt();
  digitalWrite(RELAY3_PIN, relayState);
}

// Relay 4 control (V3)
BLYNK_WRITE(V3)
{
  int relayState = param.asInt();
  digitalWrite(RELAY4_PIN, relayState);
}

void loop()
{
  Blynk.run();
}
