#include "input.h"

void input::configure() {
    ::Mirf.spi = &::MirfHardwareSpi;
    ::Mirf.init();
    ::Mirf.setRADDR((byte *)"serv1");
    ::Mirf.payload = sizeof(uint8_t);
    ::Mirf.channel = 90;
    ::Mirf.config();
}

boolean input::data_ready() {
    return ::Mirf.dataReady();
}

void input::read(uint8_t *c) {
    ::Mirf.getData(c);
}