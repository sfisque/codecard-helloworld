// GxEPD2_BareMinimum.ino by Harrison Asmar for Robotics Playground
//Based off GxEPD2_MinimumExample.ino by Jean-Marc Zingg

// uncomment next line to use class GFX of library GFX_Root instead of Adafruit_GFX
//#include <Adafruit_GFX.h>
#include <string>
#define ENABLE_GxEPD2_GFX 0
#include <GxEPD2_BW.h> // including both doesn't hurt
#include <GxEPD2_3C.h> // including both doesn't hurt

#include <Fonts/FreeMonoBold24pt7b.h> //Font
#include <Fonts/FreeMonoBold12pt7b.h> //Font

// copy constructor for your e-paper from GxEPD2_Example.ino, and for AVR needed #defines
#define MAX_DISPLAY_BUFFER_SIZE 800 // 
#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8) ? EPD::HEIGHT : MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8))

GxEPD2_BW<GxEPD2_270, GxEPD2_270::HEIGHT> display(GxEPD2_270(/*CS=D8*/ 2, /*DC=D3*/ 0, /*RST=D4*/ 4, /*BUSY=D2*/ 5)); // 2.7" b/w 264x176

//WIFI
#include <ESP8266WiFi.h>        // Include the Wi-Fi library

const char* ssid     = "ssid";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "password";     // The password of the Wi-Fi network


void setup()
{
  
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  
  display.init(); //start display stuff
  //display.hibernate(); //No idea what this does
  display.setRotation(3); //Sets the display to be the right orientation.
  // comment out next line to have no or minimal Adafruit_GFX code
  display.setTextColor(GxEPD_BLACK);
  display.firstPage();

  do
  {
    display.fillScreen(GxEPD_WHITE);
    // comment out next line to have no or minimal Adafruit_GFX code
    display.setFont(&FreeMonoBold12pt7b);
    display.setCursor(20, 85);
    //String var = "IP: "+WiFi.localIP();
    display.print("Connecting to:"); 
    display.setCursor(20, 100);
    display.print(ssid);
  }
  while (display.nextPage());
  
  delay(10);
  Serial.println('\n');

  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());

  
  do
  {
    display.fillScreen(GxEPD_WHITE);
    // comment out next line to have no or minimal Adafruit_GFX code
    display.setFont(&FreeMonoBold12pt7b);
    display.setCursor(20, 100);
    //String var = "IP: "+WiFi.localIP();
    display.print("IP: ");
    display.print(WiFi.localIP());
    
  }
  while (display.nextPage());
}

void loop() {}
