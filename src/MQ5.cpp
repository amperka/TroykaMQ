#include "MQ5.h"

MQ5::MQ5(uint8_t pin)
  : BaseMQ(pin) {
}

MQ5::MQ5(uint8_t pin, uint8_t pinHeater)
  : BaseMQ(pin, pinHeater) {
}

unsigned long MQ5::readLPG() {
  return readScaled(-0.39, 1.73);
}

unsigned long MQ5::readMethane() {
  return readScaled(-0.38, 1.97);
}
