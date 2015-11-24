#include <SimpleTimer.h>

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

SimpleTimer timer;
int left_timer_id;
int right_timer_id;

byte led_state = 0b00000000;

void setup() {
  pinMode(DATA_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  chenge_lights(led_state);

  pinMode(LEFT_BUTTON, INPUT);
  pinMode(RIGHT_BUTTON, INPUT);

  Serial.begin(9600);

  left_timer_id = timer.setInterval(500, turn_left);
  right_timer_id = timer.setInterval(500, turn_right);
  timer.disable(left_timer_id);
  timer.disable(right_timer_id);
}

void loop() {
  timer.run();

  process_buttons();

}

boolean left_pressed = false;
boolean right_pressed = false;
void process_buttons() {
  boolean left = digitalRead(LEFT_BUTTON);
  boolean right = digitalRead(RIGHT_BUTTON);

  if (!left_pressed && left) {
    left_pressed = true;
  } else if (left_pressed && !left) {
    if (timer.isEnabled(left_timer_id)) {
      timer.disable(left_timer_id);
      turn_left_off();
    } else {
      timer.enable(left_timer_id);
    }
    left_pressed = false;
  }

  if (!right_pressed && right) {
    right_pressed = true;
  } else if (right_pressed && !right) {
    if (timer.isEnabled(right_timer_id)) {
      timer.disable(right_timer_id);
      turn_right_off();
    } else {
      timer.enable(right_timer_id);
    }
    right_pressed = false;
  }
}

void turn_alarm() {
  turn_left_off();
  turn_right_off();
  timer.enable(left_timer_id);
  timer.enable(right_timer_id);
}

void turn_left() {
  inverse_bit(led_state, BIT_LEFT_TURN);
  inverse_bit(led_state, BIT_RELAY);
  chenge_lights(led_state);
}

void turn_left_off() {
  set_bit(led_state, BIT_LEFT_TURN, OFF);
  chenge_lights(led_state);
}

void turn_right() {
  inverse_bit(led_state, BIT_RIGHT_TURN);
  inverse_bit(led_state, BIT_RELAY);
  chenge_lights(led_state);
}

void turn_right_off() {
  set_bit(led_state, BIT_RIGHT_TURN, OFF);
  chenge_lights(led_state);
}

void set_bit(byte &_byte, int _bit, int _value) {
  _byte &= ~(1 << _bit);
  _byte |= _value << _bit;
}

void inverse_bit(byte &_byte, int _bit) {
  _byte ^= 1 << _bit;
}

void chenge_lights(byte value) {
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, value);
  digitalWrite(LATCH_PIN, HIGH);
}
