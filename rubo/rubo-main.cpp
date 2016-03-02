#include "Arduino.h"
#include "input.h"
#include "Rubo.h"

#define LATCH_PIN 4
#define DATA_PIN 5
#define CLOCK_PIN 6

void setup() {
    Serial.begin(9600);

    input::configure();

    rubo::confugure(CLOCK_PIN, LATCH_PIN, DATA_PIN);
}

void loop() {
    rubo::timer_run();




    if (input::data_ready()) {
        uint8_t data;
        input::read(&data);
        Serial.print("Read command: ");
        Serial.println(data);

        switch (data) {
            case 3: {
                rubo::alarm();
                break;
            }
            case 4: {
                rubo::left_turn();
                break;
            }
            case 5: {
                rubo::right_turn();
                break;
            }
            case 6: {
                rubo::head_light_blink();
                break;
            }
            case 7: {
                rubo::fog_light_blink();
                break;
            }
            case 8: {
                rubo::stop_signal_blink();
                break;
            }
            case 9: {
                rubo::rear_light_blink();
                break;
            }

        }
    }
}
