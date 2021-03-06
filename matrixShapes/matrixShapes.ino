// Based on Adafruit_NeoMatrix example for single NeoPixel Shield. Modified by A.Kleindolph 10-2015.

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>#endif

#define PIN 12

// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)


// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
                            NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
                            NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
                            NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255), matrix.Color(255, 0, 255)
};

void setup() {
  matrix.begin();
  matrix.setBrightness(40);
}

void loop() {
  matrix.drawPixel(4, 4, colors[0]);    //draw pixel at x=4 and y=4 using first color in array
  matrix.show();                        //show data on matrix
  delay(1000);
  matrix.fillScreen(0);                 //clear screen

  matrix.drawRect(0, 0, 5, 8, colors[1]);  //draw rectangle from x=0 and y=0 with a width of 5 pixels and height of 8
  matrix.show();
  delay(1000);
  matrix.fillScreen(0);

  matrix.drawLine(0, 0, 8, 8, colors[2]); //draw line from x=0 and y=0 to x=8 and y=8;
  matrix.show();
  delay(1000);
  matrix.fillScreen(0);

  matrix.fillCircle(4, 4, 2, colors[3]); //draw filled circle with center at x=4 and y=4 with radius of 2 pixels
  matrix.show();
  delay(1000);
  matrix.fillScreen(0);

  matrix.drawCircle(4, 4, 3, colors[2]); //draw circle with center at x=4 and y=4 with radius of 3 pixels
  matrix.show();
  delay(1000);
  matrix.fillScreen(0);

  matrix.drawTriangle(1, 1, 3, 3, 1, 5, colors[3]); //plot three x and y triangle points
  matrix.show();
  delay(1000);
  matrix.fillScreen(0);

}

