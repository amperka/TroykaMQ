#include "MQ4.h"

MQ4::MQ4(uint8_t pin)
  : BaseMQ(pin) {
}

MQ4::MQ4(uint8_t pin, uint8_t pinHeater)
  : BaseMQ(pin, pinHeater) {
}

unsigned long MQ4::readMethane() {
  return readPpm(-0.36, 2.54);
}

int MQ4::readPpm(float a, float b) {
  float ratio = readRs()/_ro;
  return pow(M_E, (log(ratio)-b)/a);
}
