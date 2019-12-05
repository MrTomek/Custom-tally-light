#include <SPI.h>
#include <AltSoftSerial.h>
#include <Adafruit_NeoPixel.h>

#define WS2812_PIN 6  // PIN TO LED WS2812
#define WS2812_COUNT 2 // COUNT LED WS2812
#define CAM 4

AltSoftSerial altSerial;

int  t = 0; // test index
char sygnet[10+4] = "5A53455456"; // ZSETV -> HEX -> STRING HEX

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(WS2812_COUNT, WS2812_PIN, NEO_GRB + NEO_KHZ800);
 

void setup() {
  sygnet[10] = intToChar(CAM - 1); // Custom tally light receiver index (CAMERA index) (0 or 1 or 2 or 3)

  Serial.begin(9600);
  altSerial.begin(9600);
  Serial.println("Tally receiver (CAM:"+String(intToChar(CAM))+"[index:"+String(intToChar(CAM-1))+"],Serial) ");
  Serial.println("Create by Tomasz Osikowski <MrTomek.pl>");
  Serial.println("Custom tally light v0.3");
  altSerial.println("Tally receiver (CAM: "+String(intToChar(CAM))+"[index:"+String(intToChar(CAM-1))+"],altSerial) ");
  altSerial.println("Create by Tomasz Osikowski <MrTomek.pl>");
  altSerial.println("Custom tally light v0.3");

  
  pixels.begin();
  pixels.setPixelColor(0, 0, 0, 0);
  pixels.setPixelColor(1, 0, 0, 0);
  pixels.show();
}

void loop() {
  if (altSerial.available()) {
    char c = altSerial.read();
    if(t == 11){
      if('0' == c){ // Null
        pixels.setPixelColor(0, 0, 0, 0);
        pixels.setPixelColor(1, 0, 0, 0);
        pixels.show();
      }
      if('1' == c){ // Prewiew
        pixels.setPixelColor(0, 0, 255, 0);
        pixels.setPixelColor(1, 0, 255, 0);
        pixels.show();
      }
      if('2' == c){ // Live
        pixels.setPixelColor(0, 255, 0, 0);
        pixels.setPixelColor(1, 255, 0, 0);
        pixels.show();
      }
    }
    if(sygnet[t]==c){
      t++;
    }else{
      t=0;
    }
  }
}

char intToChar(int a){
  if(a == 0) return '0';
  if(a == 1) return '1';
  if(a == 2) return '2';
  if(a == 3) return '3';
  if(a == 4) return '4';
  if(a == 5) return '5';
  if(a == 6) return '6';
  if(a == 7) return '7';
  if(a == 8) return '8';
  if(a == 9) return '9';
}
