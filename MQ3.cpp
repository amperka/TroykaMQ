#include "MQ3.h"

MQ3::MQ3(uint8_t pin)
  : BaseMQ(pin) {
}

MQ3::MQ3(uint8_t pin, uint8_t pinHeater)
  : BaseMQ(pin, pinHeater) {
}

float MQ3::readAlcoholMgL() {
  return readMgL(-0.66, -0.62);
}

float MQ3::readAlcoholPpm() {
  return readMgL(-0.66, -0.62)*2.2;
}

float MQ3::readMgL(float a, float b) {
  float ratio = readRs()/_ro;
  return pow(M_E, (log(ratio)-b)/a);
}
