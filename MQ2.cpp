#include "MQ2.h"

MQ2::MQ2(uint8_t pin)
  : BaseMQ(pin) {
}

MQ2::MQ2(uint8_t pin, uint8_t pinHeater)
  : BaseMQ(pin, pinHeater) {
}

unsigned long MQ2::readLPG() {
  return readScaled(-0.45, 2.95);
}

unsigned long MQ2::readMethane() {
  return readScaled(-0.38, 3.21);
}

unsigned long MQ2::readSmoke() {
  return readScaled(-0.42, 3.54);
}

unsigned long MQ2::readHydrogen() {
  return readScaled(-0.48, 3.32);
}
