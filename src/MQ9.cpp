#include "MQ9.h"

MQ9::MQ9(uint8_t pin)
  : BaseMQ(pin) {
}

MQ9::MQ9(uint8_t pin, uint8_t pinHeater)
  : BaseMQ(pin, pinHeater) {
}

unsigned long MQ9::readLPG() {
  return readScaled(-0.48, 3.33);
}

unsigned long MQ9::readMethane() {
  return readScaled(-0.38, 3.21);
}

unsigned long MQ9::readCarbonMonoxide() {
  return readScaled(-0.48, 3.10);
}
