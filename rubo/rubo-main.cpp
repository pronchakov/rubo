#include "Arduino.h"
#include "Rubo.h"

#define DATA_PIN 13
#define LATCH_PIN 12
#define CLOCK_PIN 11

#define LEFT_BUTTON 7
#define RIGHT_BUTTON 2

Rubo rubo(CLOCK_PIN, LATCH_PIN, DATA_PIN);

void setup() {
    pinMode(LEFT_BUTTON, INPUT);
    pinMode(RIGHT_BUTTON, INPUT);

    Serial.begin(9600);
}

void loop() {
    rubo.timer_run();
}
