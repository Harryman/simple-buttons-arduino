simple-buttons-arduino
======================

A simple library that will help you use button interfaces, doesn't do any debounce bounce. Makes it easier to do holds, repeats, combinations of buttons ie to get into other menus, button canceling make you let up before it will trigger agian, makes for really responsive and smooth menues. All while using not using interrupts or delays. 

## Class Variables
##### `press`
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`press = true` when `state = true`
    
##### `hold`
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`hold = 1` when `state = true` and is incremented by 1 for every duration of `repeatDelay` that `state = true` and is reset when to 0 when `state = false`
  
##### `lock`
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`lock = true` until `state = false` after `state()` is called with `clearMenu = true`. This is very useful for differentiating between press or start of a combo hold.

##### `commit`
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`commit = true` when `state` transitions from `true` to `false`. When `commit = true` `hold` will still have valid data until `state()` is called again. This is useful if you don't want to wear out an EEPROM address by writing values on every increment.

## Function usage
#####`btn(uint8 pin, uint16 repeatDelay) `

*  `pin`
  
  What pin you are you trying to monitor. If you are using the particular instance of this library for combo of button states or someother signal just reuse a pin used in another instance.

* `repeatDelay`
  
  This is the time in ms between increments of the class variable hold this allows you to adjust the grainularity of your hold time data


______________________________________
#####`state(bool state, bool clearMenu)`
  
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`state()` function will update the class variables `hold` and `press`. `hold` will return 1 if a button is pressed but has not been held for longer than `repeatDelay` it will then then increment by one for every duration of `repeatDelay` that that `state = true`. `press` varible will return true whenever `state = true`
* `state`
  
  All of the data is generated based on when this state changes to true, you could put in `btn1.press && btn2.press` to beable to determine if both are being pressed and how long both are held together.

* `clearnMenu`
 
  This should be set to true in situations that you want to make sure that all `btn.hold` values are zerod and will not increment again until `state = false` at which point it then operate as normal again. This is very useful when entering into a menu without having to set up new varibles or other messy flag solutions.


__________________
#####`pinState(bool clearMenu)`

  This function is the same as `state()` except it uses `digitalRead(pin)` for the state variable
  

-------------------------------------------------
Add beer to my beer fund(bitcoin): 1HGxiDZZPzj5ctKSni4xn9UVHYPu4BRuCQ

