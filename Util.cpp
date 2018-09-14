
#include <Adafruit_NeoPixel.h>
#include <IRremote.h>



void colorWipe(Adafruit_NeoPixel strip, uint32_t c, uint16_t i) {
   strip.setPixelColor(i, c);
   strip.show();
}

void colorWholeStrip(Adafruit_NeoPixel strip, uint32_t c) {
	for (int i = 0; i < strip.numPixels(); ++i) {
		strip.setPixelColor(i, c);
	}
	strip.show();
}


void turnOff(Adafruit_NeoPixel strip) {
	colorWholeStrip(strip, strip.Color(0, 0, 0));
}


uint32_t Wheel(Adafruit_NeoPixel strip, byte WheelPos) {
	WheelPos = 255 - WheelPos;
	if (WheelPos < 85) {
		return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3, 0);
	}
	if (WheelPos < 170) {
		WheelPos -= 85;
		return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3, 0);
	}
	WheelPos -= 170;
	return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0, 0);
}

void sprinkes(Adafruit_NeoPixel strip, uint16_t i) {
	static uint16_t j;
	j %= 256;
	strip.setPixelColor(i, Wheel(strip, (i + j) & 255));
	++j;
	strip.show();
}

