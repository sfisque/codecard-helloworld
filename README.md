# Codecard Session Resources

## Below is useful information for working with the Codecard provided by Oracle. 

## Notes for writing programs:

### Code must include the following line before ```void setup()``` :
```c++
GxEPD2_BW<GxEPD2_270, GxEPD2_270::HEIGHT> display(GxEPD2_270(/*CS=D8*/ 2, /*DC=D3*/ 0, /*RST=D4*/ 4, /*BUSY=D2*/ 5)); // 2.7" b/w 264x176
```

### To set font:
1. Go the the sketchbook folder where the library is installed (can be found in Arduino preferences)
2. Find the ```libraries``` folder
3. find the ```Adafruit_GFX_Library``` folder
4. Open the ```Fonts``` folder
5. Find the font you want and copy the filename
6. In your sketch, include the file 
```c++
 #include <Fonts/#FONT_FILE.h>
 ```
7. Set the font using the display.setFont command and appending the font name with & while also removing the .h extention 
```c++ 
display.setFont(&FONT_NAME);
```

### To set cursor position:
#### Note: The cursor automtically moves to the end of any text you display so it doesn't overlap

```c++
display.setCursor(x,y);
```
Valid ranges are: x: 0 - 264, y: 0 - 176

### Display text:
Once the position, font and colour are configured, text can be displayed with:
```c++
display.print('TEXT HERE');
```

### Valid Colours:
- GxEPD_WHITE
- GxEPD_BLACK

### Fill screen / blank with a colour:
```c++
display.fillScreen(<COLOR>);
```

