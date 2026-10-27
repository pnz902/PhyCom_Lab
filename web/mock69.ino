#include <WiFiS3.h>
#include <MQTTClient.h>
#include <math.h>

const char WIFI_SSID[] = "imp";           // CHANGE TO YOUR WIFI SSID
const char WIFI_PASSWORD[] = "12345678";  // CHANGE TO YOUR WIFI PASSWORD

const char MQTT_BROKER_ADRRESS[] = "phycom.it.kmitl.ac.th";  // CHANGE TO MQTT BROKER'S ADDRESS
//const char MQTT_BROKER_ADRRESS[] = "192.168.0.11";  // CHANGE TO MQTT BROKER'S IP ADDRESS
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "ananya";  // CHANGE IT AS YOU DESIRE
const char MQTT_USERNAME[] = "";         // CHANGE IT IF REQUIRED, empty if not required
const char MQTT_PASSWORD[] = "";         // CHANGE IT IF REQUIRED, empty if not required

// The MQTT topics that Arduino should publish/subscribe
const char PUBLISH_TOPIC[] = "";  // CHANGE IT AS YOU DESIRE
const char SUBSCRIBE_TOPIC1[] = "68070197/venus";
const char SUBSCRIBE_TOPIC2[] = "68070197/prob_stat";

const int PUBLISH_INTERVAL = 5000;  // 5 seconds

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

unsigned long lastPublishTime = 0;

const int RED_PIN = 7;
const int GREEN_PIN = 6;
const int BLUE_PIN = 5;


void setup() {

  //3rd pub
  // pinMode(3, OUTPUT);
  // pinMode(2, INPUT);

  //4th pub button
  // pinMode(4, INPUT);

  //1st sub
  // pinMode(9, OUTPUT);
  // pinMode(RED_PIN, OUTPUT);
  // pinMode(GREEN_PIN, OUTPUT);
  // pinMode(BLUE_PIN, OUTPUT);

  //2nd sub
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

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

//2 3 4 5 6 7 8
//E D C B A F G

byte seg_7[7] = {2, 3, 4, 5, 6, 7, 8};

int num[10][7] = {
  {1,1,1,1,1,1,0},
  {0,0,1,1,0,0,0},
  {1,1,0,1,1,0,1},
  {0,1,1,1,1,0,1},
  {0,0,1,1,0,1,1},
  {0,1,1,0,1,1,1},
  {1,1,1,0,1,1,1},
  {0,0,1,1,1,0,0},
  {1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1}
};

void showNum(int n){
  if (n < 0 || n > 9) {
    return;
  }
  
  for (int i=0; i<7; i++) {
    digitalWrite(seg_7[i], num[n][i]);
  }
}

void clearDisplay() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(seg_7[i], LOW);
  }
}

void loop() {
  mqtt.loop();

  if (!mqtt.connected()) {
    connectToMQTT();
  }

  if (millis() - lastPublishTime >= PUBLISH_INTERVAL) {
    sendToMQTT();
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

  //Subscribe to a topic, the incoming messages are processed by messageHandler() function
  if (mqtt.subscribe(SUBSCRIBE_TOPIC2))
    Serial.print("Arduino UNO R4 - Subscribed to the topic: ");
  else
    Serial.print("Arduino UNO R4 - Failed to subscribe to the topic: ");

  Serial.println(SUBSCRIBE_TOPIC2);
  Serial.println("Arduino UNO R4 - MQTT broker Connected!");
}

void sendToMQTT() {  //publish
  //1.
  // int adc = analogRead(A0);

  // float R = 10000.0 * adc / (1023.0 - adc);

  // float temp = 1.0 / (log(R / 10000.0) / 3950.0 + 1.0 / 298.15) - 273.15;

  // double volt = (analogRead(A4) / 1023.0) * 4.5; 
  // double temp2 = (volt-0.5)/0.01;

  // Serial.print("Temp_Thermistor: ");
  // Serial.print(temp);
  // Serial.print(" -- Temp_9700: ");
  // Serial.print(temp2);
  // mqtt.publish("68070197/temp", String(temp2));
  
  //2.
  // Serial.print(" -- Potentionmeter: ");
  // Serial.println(analogRead(A2));
  // mqtt.publish("68070197/light", String(analogRead(A2)));


  //3.
  // digitalWrite(3, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(3, LOW);

  // double pulseWidth = pulseIn(2, HIGH);
  // double distance = pulseWidth/29/2;

  // Serial.print("Distance: ");
  // Serial.print(distance);
  // if (distance > 20){
  //   Serial.println(" ON!");
  //   mqtt.publish("68070197/food", String("on"));
  // } else{
  //   Serial.println(" OFF!");
  //   mqtt.publish("68070197/food", String("off"));
  // }


  //4.
  // digitalWrite(3, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(3, LOW);

  // double pulseWidth = pulseIn(2, HIGH);
  // double distance = pulseWidth/29/2;

  // int val = digitalRead(4);

  // Serial.print("Distance: ");
  // Serial.print(distance);
  // Serial.print(" -- Val: ");
  // Serial.print(val);
  // if (distance >= 20 && val == HIGH){
  //   Serial.println(" ON!");
  //   mqtt.publish("68070197/door", String("on"));
  // } else{
  //   Serial.println(" OFF!");
  //   mqtt.publish("68070197/door", String("off"));
  // }
}

void messageReceived(String &topic, String &payload) {  //subscribe
  // 1.
  // int temp = payload.toInt();

  // Serial.print("Temp: ");
  // Serial.print(temp);

  // if (temp >= 36 && temp <= 50) {
  //   digitalWrite(RED_PIN, !HIGH);
  //   digitalWrite(BLUE_PIN, !LOW);
  //   digitalWrite(GREEN_PIN, !LOW);
  //   Serial.println(" - RED 36-50");
  // } else if (temp >= 26 && temp <= 35) {
  //   digitalWrite(BLUE_PIN, !HIGH);
  //   digitalWrite(RED_PIN, !LOW);
  //   digitalWrite(GREEN_PIN, !LOW);
  //   Serial.println(" - BLUE 26-35");
  // } else if (temp >= 10 && temp <= 25) {
  //   digitalWrite(GREEN_PIN, !HIGH);
  //   digitalWrite(RED_PIN, !LOW);
  //   digitalWrite(BLUE_PIN, !LOW);
  //   Serial.println(" - GREEN 10-25");
  // } else {
  //   Serial.println("");
  //   digitalWrite(GREEN_PIN, !LOW);
  //   digitalWrite(RED_PIN, !LOW);
  //   digitalWrite(BLUE_PIN, !LOW);
  // }


  //2.
  int num = payload.toInt();
  showNum(num);
}
