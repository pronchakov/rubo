#include "Rubo.h"

SimpleTimer timer;

int left_timer_id;
int right_timer_id;
int alarm_timer_id;

int lights_clock_pin;
int lights_latch_pin;
int lights_data_pin;

unsigned int led_bits_all_off = 0b00000100;
unsigned int current_led_bits = 0b00000100;


void confugure(int clock, int latch, int data) {
    lights_clock_pin = clock;
    lights_latch_pin = latch;
    lights_data_pin = data;

    pinMode(lights_data_pin, OUTPUT);
    pinMode(lights_latch_pin, OUTPUT);
    pinMode(lights_clock_pin, OUTPUT);
    all_lights_off();

    left_timer_id = timer.setInterval(500, left_turn_blink);
    right_timer_id = timer.setInterval(500, right_turn_blink);
    alarm_timer_id = timer.setInterval(500, alarm_blink);
    timer.disable(left_timer_id);
    timer.disable(right_timer_id);
    timer.disable(alarm_timer_id);
}

void timer_run() {
    timer.run();
}

void all_lights_off() {
    change_lights(led_bits_all_off);
}

// TODO: make relay revere only once
void alarm_on() {
    left_turn_off();
    right_turn_off();
    timer.enable(alarm_timer_id);
}

// TODO: make relay revere only once
void alarm_off() {
    timer.disable(alarm_timer_id);
    left_turn_off();
    right_turn_off();
}

void left_turn_on() {
    set_bit(current_led_bits, BIT_LEFT_TURN_Q0, ON);
    set_bit(current_led_bits, BIT_RELAY_Q7, ON);
    change_lights(current_led_bits);
}

void left_turn_off() {
    set_bit(current_led_bits, BIT_LEFT_TURN_Q0, OFF);
    change_lights(current_led_bits);
}


void left_turn_blink() {
    inverse_bit(current_led_bits, BIT_LEFT_TURN_Q0);
    inverse_bit(current_led_bits, BIT_RELAY_Q7);
    change_lights(current_led_bits);
}

void right_turn_on() {
    set_bit(current_led_bits, BIT_RIGHT_TURN_Q1, ON);
    set_bit(current_led_bits, BIT_RELAY_Q7, ON);
    change_lights(current_led_bits);
}

void right_turn_off() {
    set_bit(current_led_bits, BIT_RIGHT_TURN_Q1, OFF);
    change_lights(current_led_bits);
}

void right_turn_blink() {
    inverse_bit(current_led_bits, BIT_RIGHT_TURN_Q1);
    inverse_bit(current_led_bits, BIT_RELAY_Q7);
    change_lights(current_led_bits);
}

void alarm_blink() {
    inverse_bit(current_led_bits, BIT_RIGHT_TURN_Q1);
    inverse_bit(current_led_bits, BIT_LEFT_TURN_Q0);
    inverse_bit(current_led_bits, BIT_RELAY_Q7);
    change_lights(current_led_bits);
}

void stop_signal_on() {
    set_bit(current_led_bits, BIT_STOP_SIGNAL_Q5, ON);
    change_lights(current_led_bits);
}

void stop_signal_off() {
    set_bit(current_led_bits, BIT_STOP_SIGNAL_Q5, OFF);
    change_lights(current_led_bits);
}

void rear_light_on() {
    set_bit(current_led_bits, BIT_REAR_LIGHT_Q4, ON);
    change_lights(current_led_bits);
}

void rear_light_off() {
    set_bit(current_led_bits, BIT_REAR_LIGHT_Q4, OFF);
    change_lights(current_led_bits);
}

void head_light_on() {
    set_bit(current_led_bits, BIT_HEAD_LIGHT_Q2, ON);
    change_lights(current_led_bits);
}

void head_light_off() {
    set_bit(current_led_bits, BIT_HEAD_LIGHT_Q2, OFF);
    change_lights(current_led_bits);
}

void fog_light_on() {
    set_bit(current_led_bits, BIT_FOG_LIGHT_Q3, ON);
    change_lights(current_led_bits);
}

void fog_light_off() {
    set_bit(current_led_bits, BIT_FOG_LIGHT_Q3, OFF);
    change_lights(current_led_bits);
}

void set_bit(unsigned int &_byte, int _bit, int _value) {
    _byte &= ~(1 << _bit);
    _byte |= _value << _bit;
}

void inverse_bit(unsigned int &_byte, int _bit) {
    _byte ^= 1 << _bit;
}

void change_lights(unsigned int value) {
    digitalWrite(lights_latch_pin, LOW);
    shiftOut(lights_data_pin, lights_clock_pin, LSBFIRST, value);
    digitalWrite(lights_latch_pin, HIGH);
}
