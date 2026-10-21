#include <WiFiS3.h>
#include <MQTTClient.h>

const char WIFI_SSID[] = "ITFORGE_UFOxL";       // CHANGE TO YOUR WIFI SSID
const char WIFI_PASSWORD[] = "Ahhhhhhh";       // CHANGE TO YOUR WIFI PASSWORD

const char MQTT_BROKER_ADRRESS[] = "mqtt-dashboard.com"; 
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "arduino-uno-r4-ananya"; 
const char MQTT_USERNAME[] = "";                
const char MQTT_PASSWORD[] = "";                

const char PUBLISH_TOPIC[] = "ananya/temp"; 

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

const int colPins[4] = {5, 4, 3, 2};
const int rowPins[4] = {9, 8, 7, 6};

const char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

void setup() {
  Serial.begin(9600);

  for (int c = 0; c < 4; c++) {
    pinMode(colPins[c], INPUT_PULLUP);
  }
  
  for (int r = 0; r < 4; r++) {
    pinMode(rowPins[r], OUTPUT);
    digitalWrite(rowPins[r], HIGH);
  }

  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(WIFI_SSID);
    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    delay(10000);
  }

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Initialize MQTT driver once in setup
  mqtt.begin(MQTT_BROKER_ADRRESS, MQTT_PORT, network);
  connectToMQTT();
}

void loop() {
  // Auto-reconnect if connection drops
  if (!mqtt.connected()) {
    connectToMQTT();
  }
  mqtt.loop();

  // Scan Keypad
  for (int r = 0; r < 4; r++) {
    digitalWrite(rowPins[r], LOW); // Activate active row

    for (int c = 0; c < 4; c++) {
      if (digitalRead(colPins[c]) == LOW) {
        char input = keys[r][c];
        sendNum(input);

        delay(50); // Debounce delay

        // Wait until key is released so we only publish once per press
        while (digitalRead(colPins[c]) == LOW) {
          mqtt.loop();
        }
      }   
    }

    digitalWrite(rowPins[r], HIGH); // Deactivate row before checking next row
  }
}

void connectToMQTT() {
  if (mqtt.connected()) return;

  Serial.print("Connecting to MQTT broker");
  while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
    Serial.print(".");
    delay(1000); // Retry every 1s instead of 0.1s
  }
  Serial.println("\nMQTT Connected!");
}

void sendNum(char key) {
  String payload = String(key);
  mqtt.publish(PUBLISH_TOPIC, payload);

  Serial.print("Key Pressed & Published: ");
  Serial.println(payload);
}
