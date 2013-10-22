/* this example has not been tested but it should work to some degree

This library was created to make using buttons directly easier
to use when making menues with using delays or other blocking 
code. 

*** DO NOT USE BOTH FUNCTIONS IN THE SAME INSTANCE ***

Open source, attribution appreciated
Harrison Stahl / The Everything Corp
9/9/13 

HARDWARE SETUP FOR EXAMPLE*************************
LEDS on digital pins 1,2,3(don't forget dropper resistors)
buttons on pins 4,5

*/

#include <btn.h>

btn btn1(4, 350);// name of btn(pin number, delay in milliseconds before it counts up)
btn btn2(5, 350);
btn both(5, 500);// just use an already used button if you are using the
// libaray to do combo of buttons feel free to fix this and send a pull request 

uint8_t menuLvl = 0;

void setup(){
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
}


void loop(){
btnChk(false);
mainMenu();
}


void btnChk(boolean cm){// checks button states
  btn1.pinState(cm);
  btn2.pinState(cm);
  both.state(btn1.press && btn2.press, cm);
}  

void mainMenu(){ // main menu for after start up
  digitalWrite(1,btn1.press);
  digitalWrite(2,btn2.press);
  if(both.hold){//When both are held for at least the ms defined in the setup (500)
    btnChk(true);//clears buttons states to false or unclicked
    menuLvl = 1;
    digitalWrite(3, HIGH);
  }

  // you could implement the different levels with if statements if you can't be blocking anything
  while(menuLvl == 1){//This is would be a higher level menu
    btnChk(false);
    digitalWrite(4 , btn1.press);
    digitalWrite(5 , btn2.press);   
    if(both.hold){
      menuLvl = 0;
      btnChk(true);
      digitalWrite(3,LOW);
    }
  }
}

// remember if you want to know how many times a button has pushed(how long, how many repeat times)
// just by using for example btn1 bt1.hold will tell you the number times its been repeated based
// on the delay for repeat specified in the intialization. 
