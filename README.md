RGBLed
======

Simple Arduino class to control an RGB Led.

Here is a sample code on how to use this code

	RGBLed led(24, 25, 26);
	
	void setup()
	{
		// Will test all the colors
		led.testLed();
	}

	void loop()
	{
		// Set the color to yellow
		led.setColor(RGBLed::YELLOW, RGBLed::ON);

		if (test)
		{
			// Set the color to orange until process() is finished and the led will come back to the state it was before
			RGBLed::state st(&led, RGBLed::ORANGE, RGBLed::ON);
			process();
		}
	}

