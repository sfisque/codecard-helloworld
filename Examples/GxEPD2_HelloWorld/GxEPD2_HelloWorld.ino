// GxEPD2_HelloWorld.ino by Jean-Marc Zingg

// uncomment next line to use class GFX of library GFX_Root instead of Adafruit_GFX
//#include <GFX.h>

#define ENABLE_GxEPD2_GFX 0
#include <GxEPD2_BW.h> // including both doesn't hurt
// #include <GxEPD2_3C.h> // including both doesn't hurt
#include <Fonts/FreeMonoBold9pt7b.h>

// copy the constructor for your e-paper from GxEPD2_Example.ino (and for AVR boards needed #defines for MAX_HEIGHT).
#define MAX_DISPLAY_BUFFER_SIZE 800 // 
#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8) ? EPD::HEIGHT : MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8))
//GxEPD2_BW<GxEPD2_154, MAX_HEIGHT(GxEPD2_154)> display(GxEPD2_154(/*CS=10*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7)); // GDEP015OC1 no longer available
//GxEPD2_BW<GxEPD2_154_D67, MAX_HEIGHT(GxEPD2_154_D67)> display(GxEPD2_154_D67(/*CS=10*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7)); // GDEH0154D67

// e.g. for Wemos D1 mini:
//GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display(GxEPD2_154_D67(/*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4)); // GDEH0154D67

GxEPD2_BW<GxEPD2_270, GxEPD2_270::HEIGHT> display(GxEPD2_270(/*CS=D8*/ 2, /*DC=D3*/ 0, /*RST=D4*/ 4, /*BUSY=D2*/ 5)); // 2.7" b/w 264x176

// alternately you can copy the constructor from GxEPD2_constructor_examples.h or GxEPD2_boards_added.h
// or you can uncomment the constructor line in one of these included headers
#include "GxEPD2_constructor_examples.h"
#include "GxEPD2_boards_added.h"

// see GxEPD2_wiring_examples.h for wiring suggestions, the wiring corresponding to the constructor examples.
// if you use a different wiring, you need to adapt the constructor parameters!

unsigned long startTime;
unsigned long currentTime;

int btn1State = LOW;
int btn2State = LOW;

#define WAKE_PIN 16
#define BUTTON1_PIN 10
#define BUTTON2_PIN 12


void print_message( char* msg )
{
    display.setRotation( 3 );
    display.setFont( &FreeMonoBold9pt7b );
    display.setTextColor( GxEPD_BLACK );
    int16_t tbx, tby; uint16_t tbw, tbh;
    display.getTextBounds( msg, 0, 0, &tbx, &tby, &tbw, &tbh);
    // center the bounding box by transposition of the origin:
    uint16_t x = ((display.width() - tbw) / 2) - tbx;
    uint16_t y = ((display.height() - tbh) / 2) - tby;

    display.setFullWindow();
    display.firstPage();
    
    // do
    // {
        display.fillScreen( GxEPD_WHITE );
        display.setCursor( x, y );
        display.println( msg );
    // }
    // while ( display.nextPage() );

    display.display();
}


void setup()
{
    startTime = millis();

    display.init();

    pinMode( WAKE_PIN, OUTPUT );
    pinMode( BUTTON1_PIN, INPUT_PULLUP );
    pinMode( BUTTON2_PIN, INPUT_PULLUP );

    print_message( "Start Up" );

    int running = 1;

    while( running )
    {
        yield();

        btn1State = digitalRead(BUTTON1_PIN);

        if( btn1State == HIGH )
        {
            print_message( "Button A pushed" );
        }
        else
        {
            print_message( "Waiting...." );
        }
    }

    // delay( 1000 );

    // print_message( "Continuing Starting Up" );

    // delay( 1000 );

    // print_message( "Finishing Starting Up" );
}


void loop() 
{
      // }
};
