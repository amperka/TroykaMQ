#include "MQ6.h"

MQ6::MQ6(uint8_t pin)
  : BaseMQ(pin) {
}

MQ6::MQ6(uint8_t pin, uint8_t pinHeater)
  : BaseMQ(pin, pinHeater) {
}

unsigned long MQ6::readLPG() {
  return readScaled(-0.42, 2.91);
}
