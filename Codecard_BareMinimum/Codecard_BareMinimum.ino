// GxEPD2_BareMinimum.ino by Harrison Asmar for Robotics Playground
//Based off GxEPD2_MinimumExample.ino by Jean-Marc Zingg

// uncomment next line to use class GFX of library GFX_Root instead of Adafruit_GFX
//#include <Adafruit_GFX.h>

#define ENABLE_GxEPD2_GFX 0
#include <GxEPD2_BW.h> // including both doesn't hurt
#include <GxEPD2_3C.h> // including both doesn't hurt

#include <Fonts/FreeMonoBold24pt7b.h> //Font

// copy constructor for your e-paper from GxEPD2_Example.ino, and for AVR needed #defines
#define MAX_DISPLAY_BUFFER_SIZE 800 // 
#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8) ? EPD::HEIGHT : MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8))

GxEPD2_BW<GxEPD2_270, GxEPD2_270::HEIGHT> display(GxEPD2_270(/*CS=D8*/ 2, /*DC=D3*/ 0, /*RST=D4*/ 4, /*BUSY=D2*/ 5)); // 2.7" b/w 264x176

void setup()
{
  display.init(); //Start display
  display.setRotation(3); //Sets the display to be the right orientation. Range is 0 - 3
  //below section is required
  display.firstPage();
  do{
  //PUT YOUR CODE HERE
  }
  while (display.nextPage());
}

void loop() {}
