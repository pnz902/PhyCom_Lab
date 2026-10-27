#include <WiFiS3.h>
#include <MQTTClient.h>
#include <LiquidCrystal_I2C.h>


const char WIFI_SSID[] = "imp";           // CHANGE TO YOUR WIFI SSID
const char WIFI_PASSWORD[] = "phxne355";  // CHANGE TO YOUR WIFI PASSWORD

const char MQTT_BROKER_ADRRESS[] = "phycom.it.kmitl.ac.th";  // CHANGE TO MQTT BROKER'S ADDRESS
//const char MQTT_BROKER_ADRRESS[] = "192.168.0.11";  // CHANGE TO MQTT BROKER'S IP ADDRESS
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "ananya";  // CHANGE IT AS YOU DESIRE
const char MQTT_USERNAME[] = "";                        // CHANGE IT IF REQUIRED, empty if not required
const char MQTT_PASSWORD[] = "";                        // CHANGE IT IF REQUIRED, empty if not required

// The MQTT topics that Arduino should publish/subscribe
const char PUBLISH_TOPIC[] = "68070197/taxi_model";  // CHANGE IT AS YOU DESIRE
// const char SUBSCRIBE_TOPIC[] = "68070197/prob_stat"; 
const char TOPIC1[] = "68070197/queue_chotiphat"; 
const char TOPIC2[] = "68070197/queue_lapas"; 
const char TOPIC3[] = "68070197/queue_sumet"; 

const int PUBLISH_INTERVAL = 5000;  // 5 seconds

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

unsigned long lastPublishTime = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int RED_PIN = 6;
const int GREEN_PIN = 5;
const int BLUE_PIN = 4;

void setup() {
  
  pinMode(9, OUTPUT);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  // lcd.print("Taxi Model:");

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
  // if (mqtt.subscribe(SUBSCRIBE_TOPIC))
  //   Serial.print("Arduino UNO R4 - Subscribed to the topic: ");
  // else
  //   Serial.print("Arduino UNO R4 - Failed to subscribe to the topic: ");

  // Serial.println(SUBSCRIBE_TOPIC);
  // Serial.println("Arduino UNO R4 - MQTT broker Connected!");

  // last question
  // mqtt.subscribe(TOPIC1);
  // mqtt.subscribe(TOPIC2);
  // mqtt.subscribe(TOPIC3);
}

void sendToMQTT() {

  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(9, LOW);

  double pulseWidth = pulseIn(8, HIGH);
  double distance = pulseWidth/29/2;

  int choose = 0;
  char car[3][10] = {"Accord", "Altis", "Yaris"};
  char con[3][10] = {"(>30)", "(15-30)", "(<15)"};

  if (distance >= 15 && distance <= 30){
    choose = 1;
  } else if (distance < 15){
    choose = 2;
  }

  mqtt.publish(PUBLISH_TOPIC, String(car[choose]));
  lcd.setCursor(0,1);
  lcd.print(car[choose]);
  lcd.print("          "); 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("-- Car: ");
  Serial.print(car[choose]);
  Serial.println(con[choose]);

}

void messageReceived (String &topic, String &payload){
  // last question
  // not finish n not sure

  // char place[3][10] = {"Universal", "Aquarium", "Luge"};
  // int time[3] = {};
  // int choose = 0;
  // int min = 0;
  // double avg = 0;
  
  // if (topic == TOPIC1){
  //   choose = 0;
  //   time[0] = payload.toInt();
  //   min = time;
  //   avg += time/3.0;
  // }

  // if (topic == TOPIC2){
  //   time[1] = payload.toInt();
  //   if (time < min){
  //     choose = 1;
  //     minimum = time;
  //   }
  //   avg += time/3.0;
  // }

  // if (topic == TOPIC3){
  //   time[2] = payload.toInt();
  //   if (time < min){
  //     choose = 2;
  //     minimum = time;
  //   }
  //   avg += time/3.0;
  // }

  // lcd.print(place[choose]);
  // lcd.print(" (");
  // lcd.print(time[choose]);
  // lcd.print("m)");
  
  // digitalWrite(9, HIGH);
  // if (avg > 60){
  //   digitalWrite(RED_PIN, !HIGH);
  // } else if (avg > 30){
  //   analogWrite(RED_PIN, 0);
  //   analogWrite(GREEN_PIN, 128);
  // } else {
  //   analogWrite(BLUE_PIN, 0);
  //   analogWrite(GREEN_PIN, 0);
  // }

  // lcd.print("               ");
}
