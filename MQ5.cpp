#include "MQ5.h"

MQ5::MQ5(uint8_t pin)
  : BaseMQ(pin) {
}

MQ5::MQ5(uint8_t pin, uint8_t pinHeater)
  : BaseMQ(pin, pinHeater) {
}

unsigned long MQ5::readLPG() {
  return readPpm(-0.39, 1.73);
}

unsigned long MQ5::readMethane() {
  return readPpm(-0.38, 1.97);
}

int MQ5::readPpm(float a, float b) {
  float ratio = readRs()/_ro;
  return pow(M_E, (log(ratio)-b)/a);
}
