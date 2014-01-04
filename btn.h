// file generated using https://github.com/Harryman/Arduino-header-keyword-creator

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

#ifndef btn_h
#define btn_h

#include "Arduino.h"

class btn{
  public:
    btn(uint8_t pin, uint16_t repeatDelay);
    void state(boolean state, boolean clearMenu);/*state: this is where you put your function i.e. digitalRead(pin), or btn1.press && btn2.press
  clearMenu: When true it will put a lock on the repeat counter and zeros it so it wont affect
  the repeat count until it is lifted and pressed again so if you hold to get into a menu it 
  won't go crazy because it sees the repeat count from getting into the menu. */
    void pinState(boolean clearMenu); //check the state of the pin defined in the setup funciton

    boolean press;
    boolean prev;
    uint32_t time;
    boolean lock;
    boolean commit;
    uint16_t hold;

  private:

    uint8_t _pin;
    uint16_t _repeatDelay;

};

#endif