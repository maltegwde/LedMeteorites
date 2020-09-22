#include <Adafruit_NeoPixel.h>
#include "ledmeteorites.h"

int farben_len = sizeof(farben) / sizeof(farben[0]);

//TODO: different speed for each meteor
//TODO: add virtual strip; allows longer sequences than just LED_COUNT

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(70); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
  bouncer(7, 2, rot);
  //rainbow_multi_meteor(40);
  /*
  meteor(strip.Color(50,123,255), 10, 50);
  regenbogen_meteor(70, 40);
  multi_meteor(strip.Color(50,123,255), 100, 15);
  */
}

void bouncer(int bouncer_length, int wait, uint32_t color){
  strip.clear();
  for(int i=bouncer_length; i<strip.numPixels(); i++) {
    strip.setPixelColor(i-bouncer_length, off); //set the pixel behind the bouncer to off
    for(int m=0; m<bouncer_length; m++) {
      strip.setPixelColor(i-m, color);
    }
    strip.show();
    delay(wait);
  }

  for(int i=strip.numPixels()-bouncer_length; i>=0; i--) {
    strip.setPixelColor(i+bouncer_length, off); //set the pixel behind the bouncer to off
    for(int m=0; m<bouncer_length; m++) {
      strip.setPixelColor(i+m, color);
    }
    strip.show();
    delay(wait);
  }
}

/*
void rainbow_multi_meteor_diff(int wait1, int wait2, int wait3, int wait4) {
  for(int i=0; i<strip.numPixels(); i++) {
    //strip.clear();
    single_rainbow_meteor(i, 16);
    single_rainbow_meteor(i + 33, 16);
    single_rainbow_meteor(i + 66, 16);
    single_rainbow_meteor(i + 99, 16);
    single_rainbow_meteor(i + 132, 16);
    single_rainbow_meteor(i + 165, 16);
    single_rainbow_meteor(i + 198, 16);
    single_rainbow_meteor(i + 231, 16);
    single_rainbow_meteor(i + 264, 16);
    for(int x=0; x<3; i++) {
      
    }
    strip.show();
    delay(wait1);
  }
}

void single_rainbow_meteor_diff(int pos, int meteor_length, int meteor_speed){
  for(int m=0; m<meteor_length; m++) {
      int pixel = pos-m;
      if(pixel >=0 ){
        strip.setPixelColor(pixel % strip.numPixels(), farben[m % farben_len]);
      }else{
        pixel = strip.numPixels() + 1 + pixel;
        strip.setPixelColor(pixel % strip.numPixels(), farben[m % farben_len]);
      }
  }
}
*/

void rainbow_multi_meteor(int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
    single_rainbow_meteor(i, 16);
    single_rainbow_meteor(i + 33, 16);
    single_rainbow_meteor(i + 66, 16);
    single_rainbow_meteor(i + 99, 16);
    single_rainbow_meteor(i + 132, 16);
    single_rainbow_meteor(i + 165, 16);
    single_rainbow_meteor(i + 198, 16);
    single_rainbow_meteor(i + 231, 16);
    single_rainbow_meteor(i + 264, 16);
    strip.show();
    delay(wait);
  }
}

void single_rainbow_meteor(int pos, int meteor_length){
  int last_pixel = pos-meteor_length % strip.numPixels();
  if(last_pixel < 0){
    last_pixel = strip.numPixels() + last_pixel;
    last_pixel = last_pixel % strip.numPixels();
  }
  strip.setPixelColor(last_pixel % strip.numPixels(), off);
  for(int m=0; m<meteor_length; m++) {
      int pixel = pos-m;
      if(pixel >=0 ){
        strip.setPixelColor(pixel % strip.numPixels(), farben[m % farben_len]);
      }else{
        pixel = strip.numPixels() + 1 + pixel;
        strip.setPixelColor(pixel % strip.numPixels(), farben[m % farben_len]);
      }
  }
}

void multi_meteor(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
    strip.clear();
    single_meteor(color, i, 5);
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
      strip.setPixelColor(pixel % strip.numPixels(), color);
  }
}

void regenbogen_meteor(int wait, int meteor_length){
  for(int i=0; i<strip.numPixels(); i++) {
    strip.clear();
    for(int m=0; m<meteor_length; m++) {
      int pixel = i-m;
      if (pixel >= 0){
        strip.setPixelColor(pixel % strip.numPixels(), farben[m % farben_len]);
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
        strip.setPixelColor(pixel % strip.numPixels(), color);
      }
    }
    strip.show();
    delay(wait);
  }
}
