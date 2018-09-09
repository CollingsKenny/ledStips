#include <Adafruit_NeoPixel.h>
#include <IRremote.h>

#define PIN 6

#define	IR_BPlus  0xFF3AC5	// 
#define	IR_BMinus 0xFFBA45	// 
#define	IR_ON 	  0xFF827D	// 
#define	IR_OFF 	  0xFF02FD	// 
#define	IR_R      0xFF1AE5	// 
#define	IR_G 	    0xFF9A65	// 
#define	IR_B  	  0xFFA25D	// 
#define	IR_W 	    0xFF22DD	// 
#define	IR_B1	    0xFF2AD5	// 
#define	IR_B2	    0xFFAA55	// 
#define	IR_B3	    0xFF926D	// 
#define	IR_B4	    0xFF12ED	// 
#define	IR_B5	    0xFF0AF5	// 
#define	IR_B6	    0xFF8A75	// 
#define	IR_B7	    0xFFB24D	// 
#define	IR_B8	    0xFF32CD	// 
#define	IR_B9	    0xFF38C7	// 
#define	IR_B10	  0xFFB847	// 
#define	IR_B11	  0xFF7887	// 
#define	IR_B12	  0xFFF807	// 
#define	IR_B13	  0xFF18E7	// 
#define	IR_B14	  0xFF9867	// 
#define	IR_B15	  0xFF58A7	// 
#define	IR_B16	  0xFFD827	// 
#define	IR_UPR 	  0xFF28D7	// 
#define	IR_UPG 	  0xFFA857	// 
#define	IR_UPB 	  0xFF6897	// 
#define	IR_QUICK  0xFFE817	// 
#define	IR_DOWNR  0xFF08F7	// 
#define	IR_DOWNG  0xFF8877	// 
#define	IR_DOWNB  0xFF48B7	// 
#define	IR_SLOW   0xFFC837	// 
#define	IR_DIY1   0xFF30CF	// 
#define	IR_DIY2   0xFFB04F	// 
#define	IR_DIY3   0xFF708F	// 
#define	IR_AUTO   0xFFF00F	// 
#define	IR_DIY4   0xFF10EF	// 
#define	IR_DIY5   0xFF906F	// 
#define	IR_DIY6   0xFF50AF	// 
#define	IR_FLASH  0xFFD02F	// 
#define	IR_JUMP3  0xFF20DF	// 
#define	IR_JUMP7  0xFFA05F	// 
#define	IR_FADE3  0xFF609F	// 
#define	IR_FADE7  0xFFE01F	// 

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_BRG);

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

const uint32_t red = strip.Color(255, 0, 0);
const uint32_t green = strip.Color(0, 255, 0);
const uint32_t blue = strip.Color(0, 0, 255);
const uint32_t white = strip.Color(255, 255, 255);
const uint32_t black = strip.Color(0, 0, 0);

const unsigned int IR_LOWER_BOUND = 0;
const unsigned int IR_UPPER_BOUND = 0xFFFFFF;

unsigned int brightness = 100;

unsigned long previousMillis = 0; 
unsigned long interval = 50;
unsigned int index = 0;

unsigned long key_value = 0;
unsigned long key_value_prev = 0;

bool isPaused = false;

// 1 if the key_value has changed in current loop
bool keyValueFlag = false;







void setup()
{

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(brightness);

  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  strip.setPixelColor(1, strip.Color(255, 0, 0));
  strip.setPixelColor(2, strip.Color(0, 255, 0));
  strip.setPixelColor(3, strip.Color(0, 0, 255));

  strip.show();
}

void loop()
{
  unsigned long currentMillis = millis();

  // IR decode
  if (irrecv.decode(&results))
  {
    keyValueFlag = true;
    Serial.println("Set keyValueFlag");
    if(key_value != results.value ) {
      index = 0;
      key_value_prev = key_value;
      key_value = results.value;
      Serial.println(key_value, HEX);
      
    }
    irrecv.resume();
  }

  if (IR_ON) {
    
  }
    // Remote Translate
    switch (key_value) {
      // Brightness Increase
      case IR_BPlus:
        ++brightness;
        strip.setBrightness(brightness);
        resetKey();
        break;
      // Brightness Decrease
      case IR_BMinus:
        --brightness;
        strip.setBrightness(brightness);
        resetKey();
        break;
      // Pause
      case IR_ON:
        if(keyValueFlag) {
          if(isPaused) {
            Serial.println("Resuming");
            isPaused = false;
            key_value = key_value_prev;
          }
          else {
            Serial.println("Pausing");
            isPaused = true;
          }
        }
        break;
      // Power
      case IR_OFF:
        colorWipe(black, index);
        break;
  // Color Section
    // Red
      case IR_R:
        colorWipe(red, index);
        break;
    // Green
      case IR_G:
        colorWipe(green, index);
        break;
    // Blue
      case IR_B:
        colorWipe(blue, index);
        break;

    // DIY 1
      case IR_DIY1:
        redBlue(index);
        break;
      case IR_DIY2:
        sprinkes(index);
        break;
      // Volume Up
        case 0x20DF40BF:
          // TODO: make this only run once.
          cops(index);
          break;
  }

  // index
  if (currentMillis - previousMillis >= interval and !isPaused) {
    previousMillis = currentMillis;
    ++index;

    // maintain bounds    
    index %= strip.numPixels();

    //Serial.println(index);
  }
  keyValueFlag = false;
}

void resetKey() {
  key_value = key_value_prev;
}

void colorWipe(uint32_t c,  uint16_t i)
{
    strip.setPixelColor(i, c);
    strip.show();
}

void cops(uint16_t i) {
  if(i%2 == 0) {
    strip.setPixelColor(i, red);
    strip.setPixelColor(i + 5, white);
    strip.setPixelColor(i + 10, blue);
    strip.setPixelColor(i + 15, red);
    strip.setPixelColor(i + 20, white);
    strip.setPixelColor(i + 25, blue);
  }
  else {
    strip.setPixelColor(i, red);
    strip.setPixelColor(i, red);
    strip.setPixelColor(i, blue);
  }
  strip.show();
}

void sprinkes(uint16_t i)
{
  static uint16_t j;
  j %= 256;
  strip.setPixelColor(i, Wheel((i + j) & 255));
  ++j;
  strip.show();
}

uint32_t Wheel(byte WheelPos)
{
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85)
  {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3, 0);
  }
  if (WheelPos < 170)
  {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3, 0);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0, 0);
}

void redBlue(uint16_t i) {
  for (uint16_t j = 0; j < strip.numPixels(); ++j) {
    strip.setPixelColor(j, red);
    
  }

  if( 0 == i % 3) {
    strip.setPixelColor(i, blue);
    strip.setPixelColor((i + 6) % strip.numPixels(), blue);
    
  }

  if ( 0 == i % 4) {
    strip.setPixelColor((i + 12) % strip.numPixels(), blue);
  }
    
      
    

  strip.show();
  

}




  /*void meander(uint32_t c, uint8_t wait) {
uint16_t i, j;

  for(j=0; j<10; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i,);
    }
    strip.show();
    delay(wait);
  } 
}
*/
