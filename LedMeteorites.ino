#include <Adafruit_NeoPixel.h>
#include "ledmeteorites.h"

int farben_len = sizeof(farben) / sizeof(farben[0]);

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(70); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
  rainbow_multi_meteor(100);
  /*
  meteor(strip.Color(50,123,255), 10, 50);
  regenbogen_meteor(70, 40);
  multi_meteor(strip.Color(50,123,255), 100, 15);
  */
}

void rainbow_multi_meteor(int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
    strip.clear();
    single_rainbow_meteor(i, 20);
    single_rainbow_meteor(i + 40, 20);
    single_rainbow_meteor(i + 80, 20);
    single_rainbow_meteor(i + 140, 20);
    single_rainbow_meteor(i + 180, 20);
    single_rainbow_meteor(i + 220, 20);
    single_rainbow_meteor(i + 260, 20);
    strip.show();
    delay(wait);
  }
}

void single_rainbow_meteor(int pos, int meteor_length){
  for(int m=0; m<meteor_length; m++) {
      int pixel = pos-m;
      if (pixel >= 0){
        strip.setPixelColor(pixel % LED_COUNT, farben[m % farben_len]);
      }else{
        strip.setPixelColor(pixel % LED_COUNT+pixel, farben[m % farben_len]);
      }
  }
}

void multi_meteor(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
    strip.clear();
    single_meteor(color, i + 1, 5);
    single_meteor(color, i + 15, 10);
    single_meteor(color, i + 60, 3);
    single_meteor(color, i + 150, 15);
    strip.show();
    delay(wait);
  }
}

void single_meteor(uint32_t color, int pos, int meteor_length){
  for(int m=0; m<meteor_length; m++) {
      int pixel = pos-m;
      if (pixel >= 0){
        strip.setPixelColor(pixel % LED_COUNT, color);
      }
  }
}

void regenbogen_meteor(int wait, int meteor_length){
  for(int i=0; i<strip.numPixels(); i++) {
    strip.clear();
    for(int m=0; m<meteor_length; m++) {
      int pixel = i-m;
      if (pixel >= 0){
        strip.setPixelColor(pixel % LED_COUNT, farben[m % farben_len]);
      }
    }
    strip.show();
    delay(wait);
  }
}

void meteor(uint32_t color, int wait, int meteor_length) {
  for(int i=0; i<strip.numPixels(); i++) {
    strip.clear();
    for(int m=0; m<meteor_length; m++) {
      int pixel = i-m;
      if (pixel >= 0){
        strip.setPixelColor(pixel % LED_COUNT, color);
      }
    }
    strip.show();
    delay(wait);
  }
}
