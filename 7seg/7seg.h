#ifndef seven_segment_h
#define seven_segment_h
#include <Arduino.h>
class Seven_segment
{
public:
    Seven_segment(uint8_t data, uint8_t latch, uint8_t clock,char common = 'c');
    void update(int num = 0, bool comma = 0);
    void update_register(byte digit, byte sprite);
    void indicate(byte digit, byte sprite, bool comma);
private:        
    char com;        
    uint8_t datapin;
    uint8_t latchpin;
    uint8_t clockpin;
};
#endif