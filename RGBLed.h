#include <Arduino.h>

// Simple class to control an RGBLed

class RGBLed
{
public:
	enum eColor {
		RED,
		GREEN,
		BLUE,
		YELLOW,
		ORANGE,
		kLastColor
	};
	
	enum eMode {
		OFF,
		ON
	};
	
	typedef struct {
		unsigned char red;
		unsigned char green;
		unsigned char blue;
	} tColor;
	
	class state {
	protected:
		RGBLed* led;
		tColor last_color;
		eMode last_mode;
		float last_power; // 0 = off, 1 = on
		
	public:
		state(RGBLed* led, eColor color, eMode mode);
		~state();
	};

	RGBLed (int red_pin, int green_pin, int blue_pin);
	virtual ~RGBLed ();
	
	void update();
	void setColor(eColor color, eMode mode);
	void testLed();

private:
	int red_pin;
	int green_pin;
	int blue_pin;
	
	tColor color;
	
	eMode mode;
	float power; // 0 = off, 1 = on
};
