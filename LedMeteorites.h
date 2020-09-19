#include <Adafruit_NeoPixel.h>

#define LED_PIN 5     //pin connected to led strip
#define LED_COUNT 297  //number of leds

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

uint32_t rot = strip.Color(255,0,0);
uint32_t trinidad = strip.Color(194,82,46);
uint32_t kacke = strip.Color(110,61,0);
//uint32_t tangerine = strip.Color(245,128,15);
uint32_t orange = strip.Color(255,153,0);
uint32_t gelb = strip.Color(255,255,93);
uint32_t chartreuse = strip.Color(129,255,26);
uint32_t gruen = strip.Color(0,255,0);
uint32_t babyblau = strip.Color(53,208,243);
uint32_t blau = strip.Color(0,0,255);
//uint32_t indigo = strip.Color(75,0,130);
uint32_t violet = strip.Color(136,0,255);
uint32_t pink = strip.Color(245,0,159);
  
uint32_t farben[] = {rot, kacke, orange, gelb, chartreuse, gruen, babyblau, blau, violet, pink};
