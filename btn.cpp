/* This library was created to make using buttons directly easier
to use when making menues with using delays or other blocking 
code. 

supports combos or anything you put that evals to a boolean

look at the example for usage. 

Do not use both functions in the same instance, it will break eaisly so be careful if you do

Open source, attribution appreciated
Harrison Stahl / The Everything Corp
Beerfund(bitcoin): 1HGxiDZZPzj5ctKSni4xn9UVHYPu4BRuCQ
9/9/13 */

#include "btn.h"
#include "Arduino.h"


btn::btn(uint8_t pin, uint16_t repeatDelay){// when intialized it sets the pin to input and turns on the internal pull up.
	pinMode(pin, INPUT);
	digitalWrite(pin, HIGH);
	_pin = pin;
  _repeatDelay = repeatDelay;
  press = false;
  prev = false;
}

/*state: this is where you put your function i.e. digitalRead(pin), or btn1.press && btn2.press
  clearMenu: When true it will put a lock on the repeat counter and zeros it so it wont affect
  the repeat count until it is lifted and pressed again so if you hold to get into a menu it 
  won't go crazy because it sees the repeat count from getting into the menu. */
void btn::state(boolean state, boolean clearMenu){
	if(state){
    if(press == false){
      time = millis();
      press = true;
    }
    if(clearMenu == true){
      lock = true;
    }
  }
  else{
   	press = false;
    if(lock == false){ //this will delay one round so commit!=true
      if(press == prev){ //if there is a change in state commit will
        time = 0;				 // be true, so you can read the value before 
        commit = false;	 // it zeros
      }
      else{
        commit = true;   // store value when commit is true
      }
    }
    else{
      lock = false; // set lock back to false, next round it will 
    }								// zero the time and not change commit to true
  }
  if(press == true){
    hold = press + ((millis()-time) / _repeatDelay); // press = 1
  }	// hold is 1 + number of times it has go through repeatDelay time
  else if(!commit){// this will only 0 the value after commit
    hold = 0;
  }
  
  if(lock){
    hold = 0; 
  }
  prev = press;
}

void btn::pinState(boolean clearMenu){ //check the state of the pin defined in the setup funciton
	if(digitalRead(_pin) == LOW){ // do not use this if you are using it for combos use state instead
		state(true,clearMenu);
	}
	else{
		state(false,clearMenu);
	}
}