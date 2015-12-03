#ifndef ARDUINOEXAMPLE_RUBO_H
#define ARDUINOEXAMPLE_RUBO_H

#include "Arduino.h"
#include "SimpleTimer.h"

#define BIT_LEFT_TURN_Q0 7
#define BIT_RIGHT_TURN_Q1 6
#define BIT_HEAD_LIGHT_Q2 5
#define BIT_FOG_LIGHT_Q3 4
#define BIT_REAR_LIGHT_Q4 3
#define BIT_STOP_SIGNAL_Q5 2
#define BIT_reserved_Q6 1
#define BIT_RELAY_Q7 0

#define ON 1
#define OFF 0

class Rubo {

public:
    Rubo(int lights_clock_pin, int lights_latch_pin, int lights_data_pin);

    void alarm_on();

    void alarm_off();

    void left_turn_on();

    void left_turn_off();

    void left_turn_blink();

    void right_turn_on();

    void right_turn_off();

    void right_turn_blink();

    void stop_signal_on();

    void stop_signal_off();

    void rear_light_on();

    void rear_light_off();

    void head_light_on();

    void head_light_off();

    void fog_light_on();

    void fog_light_off();

    void all_lights_off();

    void timer_run();

private:
    void set_bit(unsigned int &_byte, int _bit, int _value);

    void inverse_bit(unsigned int &_byte, int _bit);

    void chenge_lights(unsigned int value);

    SimpleTimer timer;

    int lights_clock_pin;
    int lights_latch_pin;
    int lights_data_pin;

    unsigned int led_bits_all_off = 0b00000000;
    unsigned int current_led_bits = 0b00000000;

};

#endif //ARDUINOEXAMPLE_RUBO_H
