#include "MQ3.h"

MQ3::MQ3(uint8_t pin)
  : BaseMQ(pin) {
}

MQ3::MQ3(uint8_t pin, uint8_t pinHeater)
  : BaseMQ(pin, pinHeater) {
}

float MQ3::readAlcoholMgL() {
  return readScaled(-0.66, -0.62);
}

float MQ3::readAlcoholPpm() {
  return readScaled(-0.66, -0.62) * 2.2;
}
