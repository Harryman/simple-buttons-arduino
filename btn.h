/* Open source, but please
give attribution to Harrison
Stahl and/or The Everything Corp
9/9/13 */

#ifndef btn_h
#define btn_h

#include "Arduino.h"

class btn
{
public:
	btn(uint8_t pin,uint16_t repeatDelay);
	void state(boolean state, boolean clearMenu);
	void pinState(boolean clearMenu);
	uint16_t hold;
	uint16_t repeateDelay;
	boolean press;
	boolean prev;
	boolean commit;
	boolean lock;
	uint32_t time;

private:
	uint8_t _pin;
	uint16_t _repeatDelay;
};

#endif
