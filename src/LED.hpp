#pragma once
#include <stdint.h>
#include "stm32f1xx_hal.h"
#include <math.h>

class LED
{
public:
	LED();
	LED(TIM_HandleTypeDef *tim);

	void updateNeopixels();

	void animateSine(uint8_t *baseColor, float speed, float scaling, float dimming);

	void setNeopixel(uint8_t *rgb, uint8_t led);
	void setNeopixel(uint8_t red, uint8_t green, uint8_t blue, uint8_t led);

	void setAllNeopixels(uint8_t *rgb);
	void setAllNeopixels(uint8_t red, uint8_t green, uint8_t blue);

	uint32_t _updateCNT = 0;

private:
	void setNEOPin(bool on);
	void toggleNEOPin();
	void setNeopixelNOUP(uint8_t *rgb, uint8_t led);
	void setNeopixelNOUP(uint8_t red, uint8_t green, uint8_t blue, uint8_t led);

	static const uint8_t _neoLEDS = 8;

	uint8_t ledBufferRED[_neoLEDS];
	uint8_t ledBufferGREEN[_neoLEDS];
	uint8_t ledBufferBLUE[_neoLEDS];
	TIM_HandleTypeDef *_tim;
};
