#ifndef INPUT_H
#define INPUT_H

#include "Arduino.h"
#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

namespace input {
    void configure();
    boolean data_ready();
    void read(uint8_t *c);
}

#endif //INPUT_H
