//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>

// WiFi network info.
char ssid[] = "";
char wifiPassword[] = "";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "ffa35370-2daf-11e7-9191-35e0db0bb6a6";
char password[] = "ec73d95f6d12ca5f0a0b2e015e6cb50e24094ae5";
char clientID[] = "3d0cd860-d2ac-11e8-810f-075d38a26cc9";


#define VIRTUAL_CHANNELrec1 5
#define rec1 5
#define VIRTUAL_CHANNELrec2 4
#define rec2 4
#define VIRTUAL_CHANNELrec3 2
#define rec3 2
#define VIRTUAL_CHANNELrec4 0
#define rec4 0
#define VIRTUAL_CHANNELrec5 16
#define rec5 16









void setup()
{
  Serial.begin(9600);
  pinMode(rec1, OUTPUT);
  pinMode(rec2, OUTPUT);
  pinMode(rec3, OUTPUT);
  pinMode(rec4, OUTPUT);
  pinMode(rec5, OUTPUT);




  
  
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);
}

void loop()
{
  Cayenne.loop();

}

CAYENNE_IN(VIRTUAL_CHANNELrec1)
{
  int valrec1 = getValue.asInt();
  CAYENNE_LOG("Channel %d, pin %d, value %d", VIRTUAL_CHANNELrec1, rec1, valrec1);
  // Write the value received to the digital pin.
  digitalWrite(rec1,valrec1);
  
 }

 CAYENNE_IN(VIRTUAL_CHANNELrec2)
{
  int valrec2 = getValue.asInt();
  CAYENNE_LOG("Channel %d, pin %d, value %d", VIRTUAL_CHANNELrec2, rec2, valrec2);
  // Write the value received to the digital pin.
  digitalWrite(rec2,valrec2);
  
 }

 CAYENNE_IN(VIRTUAL_CHANNELrec3)
{
  int valrec3 = getValue.asInt();
  CAYENNE_LOG("Channel %d, pin %d, value %d", VIRTUAL_CHANNELrec3, rec3, valrec3);
  // Write the value received to the digital pin.
  digitalWrite(rec3,valrec3);
  
 }

 CAYENNE_IN(VIRTUAL_CHANNELrec4)
{
  int valrec4 = getValue.asInt();
  CAYENNE_LOG("Channel %d, pin %d, value %d", VIRTUAL_CHANNELrec4, rec4, valrec4);
  // Write the value received to the digital pin.
  digitalWrite(rec4,valrec4);
  
 }

 CAYENNE_IN(VIRTUAL_CHANNELrec5)
{
  int valrec5 = getValue.asInt();
  CAYENNE_LOG("Channel %d, pin %d, value %d", VIRTUAL_CHANNELrec5, rec5, valrec5);
  // Write the value received to the digital pin.
  digitalWrite(rec5,valrec5);
  
 }
