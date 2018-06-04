
// This example shows how to connect to Cayenne using an ESP8266 and send/receive sample data.
// Make sure you install the ESP8266 Board Package via the Arduino IDE Board Manager and select the correct ESP8266 board before compiling. 

//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>

// WiFi network info.
char ssid[] = "";
char wifiPassword[] = "";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "ffa35370-2daf-11e7-9191-35e0db0bb6a6";
char password[] = "ec73d95f6d12ca5f0a0b2e015e6cb50e24094ae5";
char clientID[] = "e95fd190-5c9a-11e8-b127-8b73f01b49ff";

unsigned long lastMillis = 0;

int relayButton;  // variable to hold button state
const int relayPin = 5;  // constant variable to hold pin #

void setup()
{
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);
}

void loop()
{
  Cayenne.loop();

//Publish data every 10 seconds (10000 milliseconds). Change this value to publish at a different interval.
  if (millis() - lastMillis > 10000)
    {
      lastMillis = millis();
//Write data to Cayenne here. This example just sends the current uptime in milliseconds.
      Cayenne.virtualWrite(0, lastMillis);
//Some examples of other functions you can use to send data.
      Cayenne.celsiusWrite(1, 22.0);
    }



    if (relayButton == 1)  // checks if button is pressed or not
      {
        digitalWrite(relayPin, HIGH);
      }

    else  // if not pressed
      {
        digitalWrite(relayPin, LOW);
      }
}



CAYENNE_IN(10)  //channel 10 but can be any channel thats not used
{
 relayButton = getValue.asInt();  //sets variable to button state
}

