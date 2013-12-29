#include "RGBLed.h"

static RGBLed::tColor kColors[RGBLed::kLastColor] =
{
	{0xFF, 0x00, 0x00},
	{0x00, 0xFF, 0x00},
	{0x00, 0x00, 0xFF},
	{0xFF, 0xFF, 0x00},
	{0xFF, 0x7F, 0x00},
};

RGBLed::RGBLed(int _red_pin, int _green_pin, int _blue_pin):
	red_pin(_red_pin), green_pin(_green_pin), blue_pin(_blue_pin),
	mode(OFF), power(0.0f)
{
	pinMode(red_pin, OUTPUT);
	pinMode(green_pin, OUTPUT);
	pinMode(blue_pin, OUTPUT);  
}

RGBLed::~RGBLed()
{}

void RGBLed::setColor(eColor c, eMode m)
{
	color = kColors[c];
	mode = m;
	update();
}

void RGBLed::update()
{
	bool need_change = false;
	if (mode == ON && power != 1.0)
	{
		power = 1.0;
		need_change = true;
	}
	if (mode == OFF && power != 0.0)
	{
		power = 0.0;
		need_change = true;
	}
	
	analogWrite(red_pin, color.red * power);
	analogWrite(green_pin, color.green * power);
	analogWrite(blue_pin, color.blue * power);
}

void RGBLed::testLed()
{
	for(size_t i = 0; i < kLastColor; ++i)
	{
		setColor((eColor)i, ON);
		delay(500);
	}
}

RGBLed::state::state(RGBLed* _led, RGBLed::eColor _color, RGBLed::eMode _mode)
{
	led = _led;
	last_color = led->color;
	last_mode = led->mode;
	last_power = led->power;

	led->setColor(_color, _mode);
}

RGBLed::state::~state()
{
	led->color = last_color;
	led->mode = last_mode;
	led->power = last_power;
	led->update();
}
