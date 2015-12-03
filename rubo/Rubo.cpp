#include "Rubo.h"

SimpleTimer timer;
int left_timer_id;
int right_timer_id;

Rubo::Rubo(int lights_clock_pin, int lights_latch_pin, int lights_data_pin) {
    this->lights_clock_pin = lights_clock_pin;
    this->lights_latch_pin = lights_latch_pin;
    this->lights_data_pin = lights_data_pin;

    pinMode(lights_data_pin, OUTPUT);
    pinMode(lights_latch_pin, OUTPUT);
    pinMode(lights_clock_pin, OUTPUT);
    this->all_lights_off();

    left_timer_id = timer.setInterval(500, (timer_callback) &Rubo::left_turn_blink);
    right_timer_id = timer.setInterval(500, (timer_callback) &Rubo::right_turn_blink);
    timer.disable(left_timer_id);
    timer.disable(right_timer_id);
}

void Rubo::timer_run() {
    timer.run();
}

void Rubo::all_lights_off() {
    chenge_lights(led_bits_all_off);
}

void Rubo::alarm_on() {
    left_turn_off();
    right_turn_off();
    timer.enable(left_timer_id);
    timer.enable(right_timer_id);
}

void Rubo::alarm_off() {
    timer.disable(left_timer_id);
    timer.disable(right_timer_id);
    left_turn_off();
    right_turn_off();
}

void Rubo::left_turn_on() {
    set_bit(current_led_bits, BIT_LEFT_TURN_Q0, ON);
    set_bit(current_led_bits, BIT_RELAY_Q7, ON);
    chenge_lights(current_led_bits);
}

void Rubo::left_turn_off() {
    set_bit(current_led_bits, BIT_LEFT_TURN_Q0, OFF);
    chenge_lights(current_led_bits);
}


void Rubo::left_turn_blink() {
    inverse_bit(current_led_bits, BIT_LEFT_TURN_Q0);
    inverse_bit(current_led_bits, BIT_RELAY_Q7);
    chenge_lights(current_led_bits);
}

void Rubo::right_turn_on() {
    set_bit(current_led_bits, BIT_RIGHT_TURN_Q1, ON);
    set_bit(current_led_bits, BIT_RELAY_Q7, ON);
    chenge_lights(current_led_bits);
}

void Rubo::right_turn_off() {
    set_bit(current_led_bits, BIT_RIGHT_TURN_Q1, OFF);
    chenge_lights(current_led_bits);
}

void Rubo::right_turn_blink() {
    inverse_bit(current_led_bits, BIT_RIGHT_TURN_Q1);
    inverse_bit(current_led_bits, BIT_RELAY_Q7);
    chenge_lights(current_led_bits);
}

void Rubo::stop_signal_on() {

}

void Rubo::stop_signal_off() {

}

void Rubo::rear_light_on() {

}

void Rubo::rear_light_off() {

}

void Rubo::head_light_on() {

}

void Rubo::head_light_off() {

}

void Rubo::fog_light_on() {

}

void Rubo::fog_light_off() {

}

void Rubo::set_bit(unsigned int &_byte, int _bit, int _value) {
    _byte &= ~(1 << _bit);
    _byte |= _value << _bit;
}

void Rubo::inverse_bit(unsigned int &_byte, int _bit) {
    _byte ^= 1 << _bit;
}

void Rubo::chenge_lights(unsigned int value) {
    digitalWrite(lights_latch_pin, LOW);
    shiftOut(lights_data_pin, lights_clock_pin, LSBFIRST, value);
    digitalWrite(lights_latch_pin, HIGH);
}
