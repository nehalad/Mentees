#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager
#include <EEPROM.h>
#include <NeoPixelBus.h>

const uint16_t PixelCount = 1; // this example assumes 4 pixels, making it smaller will cause a failure
const uint8_t PixelPin = 4;  // make sure to set this to the correct pin, ignored for Esp8266
#define colorSaturation 128
NeoPixelBus<NeoGrbFeature, NeoEsp8266BitBang800KbpsMethod> strip(PixelCount, PixelPin);
RgbColor red(colorSaturation, 0, 0);
RgbColor black(0);

String IFTTT_KEY = "do7N3ibZVo254_ibYIYrY4"; 
// my api key  iYiYhj3KyPFEwyVRuJzEb(for testing)
const char* eventName  = "gas_sensor";
const char* IFTTT_URL = "maker.ifttt.com";


#define SLEEP_TIME 180*1*1000000     //change sleep time, 180 seconds for 3 minutes
#define WIFI_CONNECT_TIMEOUT_S 20                   // max time for wifi connect to router, if exceeded restart



int sensorPin = 5;
int buzzerPin = 0;
WiFiClient client;

        
void setup() 
    { 
      
      Serial.begin(115200);
      Serial.println();
      // this resets all the neopixels to an off state
      strip.Begin();
      strip.Show();
      pinMode(sensorPin, INPUT);
      pinMode(buzzerPin, OUTPUT);
      digitalWrite(buzzerPin, LOW);
      int sensorPinState = digitalRead(sensorPin);
      Serial.print("sensor Pin State: ");
      Serial.println(sensorPinState);
          WiFi.forceSleepBegin();  // send wifi to sleep to reduce power consumption
          yield();
          // scale.power_down();
          Serial.begin(115200);
          if(sensorPinState == 0)
            {
               WiFi.forceSleepWake();
               delay(500);
               wifi_set_sleep_type(MODEM_SLEEP_T);
               WiFi.mode(WIFI_STA);
               yield();

               WiFiManager wifiManager;
               // wifiManager.resetSettings();
               wifiManager.autoConnect("Gas Sensor");
               Serial.println("connected...yeey :)");
               Serial.println( WiFi.SSID().c_str());
               Serial.println(WiFi.psk().c_str());
               //String ssid1 = WiFi.SSID().c_str();
               wifiManager.setConfigPortalTimeout(180);
               // Define the WiFi Client
               WiFiClient client;
               // Set the http Port
               const int httpPort = 80;

               // Make sure we can connect
               if(!client.connect(IFTTT_URL, httpPort))
                 {
                   return;
                 }

               // We now create a URI for the request
               // String url = "/trigger/" + String(eventName) + "-"+String(eventCount)+ "/with/key/" + String(IFTTT_KEY);
               String url = "/trigger/" + String(eventName) + "/with/key/" + String(IFTTT_KEY);

               // Set some values for the JSON data depending on which event has been triggered
               IPAddress ip = WiFi.localIP();
               String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
               // String value_1 = String(t);
               //String value_2 = String(h);
               //String value_3 = "";
       


               // Build JSON data string
               String data = "";
               // data = data + "\n" + "{\"value1\":\"" + value_1 + "\"}"; //,"value2\":\""+ value_2 +"\"}";
 
               // Post the button press to IFTTT
               if(client.connect(IFTTT_URL, httpPort))
                 {
                   // Sent HTTP POST Request with JSON data
                   client.println("POST " + url + " HTTP/1.1");
                   Serial.println("POST " + url + " HTTP/1.1");
                   client.println("Host: " + String(IFTTT_URL));
                   Serial.println("Host: " + String(IFTTT_URL));
                   client.println("User-Agent: Arduino/1.0");
                   Serial.println("User-Agent: Arduino/1.0");
                   client.print("Accept: *");
                   Serial.print("Accept: *");
                   client.print("/");
                   Serial.print("/");
                   client.println("*");
                   Serial.println("*");
                   client.print("Content-Length: ");
                   Serial.print("Content-Length: ");
                   client.println(data.length());
                   Serial.println(data.length());
                   client.println("Content-Type: application/json");
                   Serial.println("Content-Type: application/json");
                   client.println("Connection: close");
                   Serial.println("Connection: close");
                   client.println();
                   Serial.println();
                   client.println(data);
                   Serial.println(data);
                   for(int i = 0; i < 15; i++)
                      {
                        //  Serial.println("Buzzer ON"); 
                        digitalWrite(buzzerPin, HIGH);
                        strip.SetPixelColor(0, red);
                        strip.Show();
                        delay(500);
                        //  Serial.println("Buzzer OFF");
                        digitalWrite(buzzerPin, LOW);
                        strip.SetPixelColor(0, black);
                        strip.Show();
                        delay(500);
                      }
            
               }
             WiFi.forceSleepBegin();
            }

   
         ESP.deepSleep(SLEEP_TIME, WAKE_RFCAL);
 

   
  }
 
void loop() {


  }

  



  

