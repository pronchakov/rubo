#include "Arduino.h"
#include "Rubo.h"

#define LATCH_PIN 10
#define DATA_PIN 11
#define CLOCK_PIN 12

void setup() {
    Serial.begin(9600);

    rubo::confugure(CLOCK_PIN, LATCH_PIN, DATA_PIN);
}


void loop() {
    rubo::timer_run();
}
