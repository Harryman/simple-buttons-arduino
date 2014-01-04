simple-buttons-arduino
======================

A simple library that will help you use button interfaces, doesn't do any debounce bounce. Makes it easier to do holds, repeats, combinations of buttons ie to get into other menus, button canceling make you let up before it will trigger agian, makes for really responsive and smooth menues. All while using not using interrupts or delays. 

## Function usage
#####`btn(uint8 pin, uint16 repeatDelay) `

*  `pin`
  
  What pin you are you trying to monitor. If you are using the particular instance of this library for combo of button states or someother signal just reuse a pin used in another instance.

* `repeatDelay`
  
  This is the time in ms between increments of the class variable hold this allows you to adjust the grainularity of your hold time data


______________________________________
#####`state(bool state, bool clearMenu)`
  
  `state()` function will update the class variables `hold` and `press`. `hold` will return 1 if a button is pressed but has not been held for longer than `repeatDelay` it will then then increment by one for every duration of `repeatDelay` that that `state = true`. `press` varible will return true whenever `state = true`
* `state`
  
  All of the data is generated based on when this state changes to true, you could put in `btn1.press && btn2.press` to beable to determine if both are being pressed and how long both are held together.

* `clearnMenu`
 
  This should be set to true in situations that you want to make sure that all `btn.hold` values are zerod and will not increment again until `state = false` at which point it then operate as normal again. This is very useful when entering into a menu without having to set up new varibles or other messy flag solutions.


__________________
#####`pinState(bool clearMenu)`

  This function is the same as `state()` except it uses `digitalRead(pin)` for the state variable
  

-------------------------------------------------
Add beer to my beer fund(bitcoin): 1HGxiDZZPzj5ctKSni4xn9UVHYPu4BRuCQ

