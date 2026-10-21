/*
 *
 * This Arduino UNO R4 code is made available for public use without any restriction
 *
 */

#include <WiFiS3.h>
#include <MQTTClient.h>

const char WIFI_SSID[] = "ITFORGE_UFOxL";           // CHANGE TO YOUR WIFI SSID
const char WIFI_PASSWORD[] = "Ahhhhhhh";  // CHANGE TO YOUR WIFI PASSWORD

const char MQTT_BROKER_ADRRESS[] = "mqtt-dashboard.com";  // CHANGE TO MQTT BROKER'S ADDRESS
//const char MQTT_BROKER_ADRRESS[] = "192.168.0.11";  // CHANGE TO MQTT BROKER'S IP ADDRESS
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "arduino-uno-r4-ananya";  // CHANGE IT AS YOU DESIRE
const char MQTT_USERNAME[] = "";                        // CHANGE IT IF REQUIRED, empty if not required
const char MQTT_PASSWORD[] = "";                        // CHANGE IT IF REQUIRED, empty if not required

// The MQTT topics that Arduino should publish/subscribe
const char PUBLISH_TOPIC[] = "ananya/temp";  // CHANGE IT AS YOU DESIRE

const int PUBLISH_INTERVAL = 5000;  // 5 seconds

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

unsigned long lastPublishTime = 0;

void setup() {
  Serial.begin(9600);

  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED) {
    Serial.print("Arduino UNO R4 - Attempting to connect to SSID: ");
    Serial.println(WIFI_SSID);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    // wait 10 seconds for connection:
    delay(10000);
  }
  // print your board's IP address:
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  connectToMQTT();
}

void loop() {
  mqtt.loop();

  if (millis() - lastPublishTime > PUBLISH_INTERVAL) {
    sendPotentiometerData();
    lastPublishTime = millis();
  }
}

void connectToMQTT() {
  // Connect to the MQTT broker
  mqtt.begin(MQTT_BROKER_ADRRESS, MQTT_PORT, network);

  // Create a handler for incoming messages
  mqtt.onMessage(messageReceived);

  Serial.print("Arduino UNO R4 - Connecting to MQTT broker");

  while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();

  if (!mqtt.connected()) {
    Serial.println("Arduino UNO R4 - MQTT broker Timeout!");
    return;
  }

  // Subscribe to a topic, the incoming messages are processed by messageHandler() function
  // if (mqtt.subscribe(SUBSCRIBE_TOPIC))
  //   Serial.print("Arduino UNO R4 - Subscribed to the topic: ");
  // else
  //   Serial.print("Arduino UNO R4 - Failed to subscribe to the topic: ");

  // Serial.println(SUBSCRIBE_TOPIC);
  // Serial.println("Arduino UNO R4 - MQTT broker Connected!");
}

void sendPotentiometerData() {
  int val = analogRead(A0);

  String payload = String(val);
  mqtt.publish(ananya/temp, payload);

  Serial.print("Potentiometer Value: ");
  Serial.print(payload);
}

// void messageReceived(String &topic, String &payload) {
//   Serial.println("Arduino UNO R4 - received from MQTT:");
//   Serial.println("- topic: " + topic);
//   Serial.println("- payload:");
//   Serial.println(payload);

//   int anode = 0, r = 0, g = 0, b = 0;
//   sscanf(payload.c_str(), "%d,%d,%d,%d", &anode, &r, &g, &b);

//   analogWrite(9, anode * 2.55);
//   analogWrite(RED_PIN, 255 - (r * 2.55));
//   analogWrite(GREEN_PIN, 255 - (g * 2.55));
//   analogWrite(BLUE_PIN, 255 - (b * 2.55));

//   Serial.print("Anode: "); Serial.println(anode);
//   Serial.print("R: "); Serial.print(r);
//   Serial.print(" G: "); Serial.print(g);
//   Serial.print(" B: "); Serial.println(b);

//   // You can process the incoming data , then control something
//   /*
//   process something
//   */
// }
