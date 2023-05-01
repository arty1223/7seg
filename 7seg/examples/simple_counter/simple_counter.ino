//simple counter example
#include "7seg.h"
//Seven_segment display(datapin, latchpin, clockpin, common pin (cathode by default, anode:'a'));
Seven_segment disp(PB2,PB1,PB0);
void setup() {
}
void loop(){
  static uint32_t tmr;
  static bool tick;
  static int curt;
  if (millis()- tmr > 50){
    tmr = millis();
    tick = !tick;
    curt+=1;
    if (curt>9999)curt = 0;    
  }
  //disp.update(integer to show < 9999,middle dot boolean,pov timeout < 255)
  disp.update(curt,tick);   
}