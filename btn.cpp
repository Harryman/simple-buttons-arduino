/* This library was created to make using buttons directly easier
to use when making menues with using delays or other blocking 
code. 

*** DO NOT USE BOTH FUNCTIONS IN THE SAME INSTANCE ***

Open source, attribution appreciated
Harrison Stahl / The Everything Corp
9/9/13 */

#include "Arduino.h"
#include "btn.h"



btn::btn(uint8_t pin, uint16_t repeatDelay){
	pinMode(pin, INPUT);
	digitalWrite(pin, HIGH);
	_pin = pin;
  _repeatDelay = repeatDelay;
  press = false;
  prev = false;
}

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

void btn::pinState(boolean clearMenu){
	if(digitalRead(_pin) == LOW){
		state(true,clearMenu);
	}
	else{
		state(false,clearMenu);
	}
}