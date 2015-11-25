#include "Rubo.h"

SimpleTimer timer;
int left_timer_id;
int right_timer_id;

unsigned int clear_led_state = 0b00000000;
unsigned int led_state = 0b00000000;

Rubo::Rubo() {
//    void (*timer_callback)(void) = &Rubo::turn_left;
    left_timer_id = timer.setInterval(500, (timer_callback) &Rubo::turn_left);
    right_timer_id = timer.setInterval(500, (timer_callback) &Rubo::turn_right);
    timer.disable(left_timer_id);
    timer.disable(right_timer_id);
}

void Rubo::timer_run() {
    timer.run();
}

void Rubo::turn_off_all_lights() {
    chenge_lights(clear_led_state);
}

void Rubo::turn_alarm() {
    turn_left_off();
    turn_right_off();
    timer.enable(left_timer_id);
    timer.enable(right_timer_id);
}

void Rubo::turn_left() {
    inverse_bit(led_state, BIT_LEFT_TURN);
    inverse_bit(led_state, BIT_RELAY);
    chenge_lights(led_state);
}

void Rubo::turn_left_off() {
    set_bit(led_state, BIT_LEFT_TURN, OFF);
    chenge_lights(led_state);
}

void Rubo::turn_right() {
    inverse_bit(led_state, BIT_RIGHT_TURN);
    inverse_bit(led_state, BIT_RELAY);
    chenge_lights(led_state);
}

void Rubo::turn_right_off() {
    set_bit(led_state, BIT_RIGHT_TURN, OFF);
    chenge_lights(led_state);
}

void Rubo::set_bit(unsigned int &_byte, int _bit, int _value) {
    _byte &= ~(1 << _bit);
    _byte |= _value << _bit;
}

void Rubo::inverse_bit(unsigned int &_byte, int _bit) {
    _byte ^= 1 << _bit;
}

void Rubo::chenge_lights(unsigned int value) {
    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, value);
    digitalWrite(LATCH_PIN, HIGH);
}
