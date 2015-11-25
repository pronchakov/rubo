#include "Arduino.h"
#include "Rubo.h"

Rubo rubo;

void setup() {
    pinMode(DATA_PIN, OUTPUT);
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
    rubo.turn_off_all_lights();

    pinMode(LEFT_BUTTON, INPUT);
    pinMode(RIGHT_BUTTON, INPUT);

    Serial.begin(9600);
}

boolean left_pressed = false;
boolean right_pressed = false;

void loop() {
    rubo.timer.run();

    boolean left = digitalRead(LEFT_BUTTON);
    boolean right = digitalRead(RIGHT_BUTTON);

}
