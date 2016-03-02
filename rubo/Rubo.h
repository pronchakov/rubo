#ifndef RUBO_H
#define RUBO_H

#include "SimpleTimer.h"

namespace rubo {

#define BIT_reserved_Q6 0
#define BIT_FOG_LIGHT_Q3 1
#define BIT_RELAY_Q7 2
#define BIT_REAR_LIGHT_Q4 3
#define BIT_STOP_SIGNAL_Q5 4
#define BIT_HEAD_LIGHT_Q2 5
#define BIT_LEFT_TURN_Q0 6
#define BIT_RIGHT_TURN_Q1 7

#define ON 1
#define OFF 0

#define TURN_PERIOD 500

    void alarm_on();

    void alarm_off();

    void alarm();

    void left_turn_on();

    void left_turn_off();

    void left_turn_blink();

    void left_turn();

    void right_turn_on();

    void right_turn_off();

    void right_turn_blink();

    void right_turn();

    void alarm_blink();

    void stop_signal_on();

    void stop_signal_off();

    void stop_signal_blink();

    void rear_light_on();

    void rear_light_off();

    void rear_light_blink();

    void head_light_on();

    void head_light_off();

    void head_light_blink();

    void fog_light_on();

    void fog_light_off();

    void fog_light_blink();

    void all_lights_off();

    void confugure(int lights_clock_pin, int lights_latch_pin, int lights_data_pin);

    void timer_run();

    void set_bit(unsigned int &_byte, int _bit, int _value);

    void inverse_bit(unsigned int &_byte, int _bit);

    void change_lights(unsigned int value);

}
#endif //RUBO_H
