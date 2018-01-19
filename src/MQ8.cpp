#include "MQ8.h"

MQ8::MQ8(uint8_t pin)
  : BaseMQ(pin) {
}

MQ8::MQ8(uint8_t pin, uint8_t pinHeater)
  : BaseMQ(pin, pinHeater) {
}

unsigned long MQ8::readHydrogen() {
  return readScaled(-1.52, 10.49);
}
