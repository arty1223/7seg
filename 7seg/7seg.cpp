#include <Arduino.h>
#include "7seg.h"
#define dig1 0
#define dig2 1
#define dig3 2
#define dig4 3
const uint8_t digitTable[] = {
  0b00111111, //0
  0b00000110, //1
  0b01011011, //2
  0b01001111, //3
  0b01100110, //4
  0b01101101, //5
  0b01111101, //6
  0b00000111, //7
  0b01111111, //8
  0b01101111, //9
  0b00000000, //clear
};
const uint8_t digits[] = {
  0b00001110, //0
  0b00001101, //1
  0b00001011, //2
  0b00000111, //3
  0b00000000, //clear  
};

Seven_segment::Seven_segment(uint8_t data, uint8_t latch, uint8_t clock,char common){
  com = common;
  datapin = data;
  latchpin = latch;
  clockpin = clock;
  pinMode(clockpin, OUTPUT);
  pinMode(datapin, OUTPUT);
  pinMode(latchpin, OUTPUT);
}
void Seven_segment::update_register(byte digit, byte sprite){ //вывод на регистр
  digitalWrite(latchpin, LOW);    
  if (com == 'a'){
    digit = ~digit;   
    sprite = ~sprite;
  }  
  shiftOut(datapin, clockpin, MSBFIRST, digit);  
  shiftOut(datapin, clockpin, MSBFIRST, sprite); 
  digitalWrite(latchpin, HIGH); 
}

void Seven_segment::indicate(byte digit, byte sprite, bool comma){
  update_register(digits[4], digitTable[10]);//clear
  byte spr = digitTable[sprite];
  if (digits[digit] == 0b00001101 and comma){
  spr += 0b10000000;}
  update_register(digits[digit],spr);    
}

void Seven_segment::update(int numb, bool comma){  
  indicate(dig1, numb / 1000,comma);
  indicate(dig2, numb % 1000 / 100,comma);
  indicate(dig3, numb % 1000 % 100 / 10,comma);  
  indicate(dig4, numb % 1000 % 100 % 10,comma);
}
  