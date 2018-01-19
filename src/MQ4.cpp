#include "MQ4.h"

MQ4::MQ4(uint8_t pin)
  : BaseMQ(pin) {
}

MQ4::MQ4(uint8_t pin, uint8_t pinHeater)
  : BaseMQ(pin, pinHeater) {
}

unsigned long MQ4::readMethane() {
  return readScaled(-0.36, 2.54);
}
