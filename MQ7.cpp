#include "MQ7.h"

MQ7::MQ7(uint8_t pin)
  : BaseMQ(pin) {
}

MQ7::MQ7(uint8_t pin, uint8_t pinHeater)
  : BaseMQ(pin, pinHeater) {
}

unsigned long MQ7::readCarbonMonoxide() {
  return readPpm(-0.77, 3.38);
}

int MQ7::readPpm(float a, float b) {
  float ratio = readRs()/_ro;
  return pow(M_E, (log(ratio)-b)/a);
}
