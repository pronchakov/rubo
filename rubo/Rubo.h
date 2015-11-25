#ifndef ARDUINOEXAMPLE_RUBO_H
#define ARDUINOEXAMPLE_RUBO_H

#include "SimpleTimer.h"

#define DATA_PIN 13
#define LATCH_PIN 12
#define CLOCK_PIN 11

#define LEFT_BUTTON 7
#define RIGHT_BUTTON 2

#define BIT_LEFT_TURN 7
#define BIT_RIGHT_TURN 6
#define BIT_RELAY 1

#define ON 1
#define OFF 0

class Rubo {

public:
    Rubo();

    void turn_alarm();
    void turn_left();
    void turn_right();
    void turn_left_off();
    void turn_right_off();
    void turn_off_all_lights();
    void timer_run();
    SimpleTimer timer;

private:
    void set_bit(unsigned int &_byte, int _bit, int _value);
    void inverse_bit(unsigned int &_byte, int _bit);
    void chenge_lights(unsigned int value);

};


#endif //ARDUINOEXAMPLE_RUBO_H
