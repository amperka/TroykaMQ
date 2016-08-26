#include "BaseMQ.h"

BaseMQ::BaseMQ(uint8_t pin) {
  _pin = pin;
}

BaseMQ::BaseMQ(uint8_t pin, uint8_t pinHeater) {
  _pin = pin;
  _pinHeater = pinHeater;
  pinMode(_pinHeater, OUTPUT);
  _prMillis = 0;
}

// калибровка датчика
void BaseMQ::calibrate(float ro) {
  _ro = ro;
  _stateCalibrate = true;
}

// калибровка датчика
void BaseMQ::calibrate() {
  float ro = 0;
  for (int i = 0; i < MQ_SAMPLE_TIMES; i++) {
    ro += calculateResistance(analogRead(_pin));
    delay(MQ_SAMPLE_INTERVAL);
  }
  ro = ro/MQ_SAMPLE_TIMES;
  ro = ro/getRoInCleanAir();
  calibrate (ro);
}

void BaseMQ::heaterPwrHigh() {
  digitalWrite(_pinHeater, HIGH);
  _heater = true;
  _prMillis = millis();
}

void BaseMQ::heaterPwrLow() {
  analogWrite(_pinHeater, 75);
  _heater = true;
  _cooler = true;
  _prMillis = millis();
}

void BaseMQ::heaterPwrOff() {
  digitalWrite(_pinHeater, LOW);
  _heater = false;
}

// сопротивление датчика
float BaseMQ::calculateResistance(int rawAdc) {
  float vrl = rawAdc*(5.0 / 1023);
  float rsAir = (5.0 - vrl)/vrl*getRL();
  return rsAir;
}

// считывание датчика
float BaseMQ::readRs() {
  float rs = 0;
  for (int i = 0; i < MQ_SAMPLE_TIMES; i++) {
    rs += calculateResistance(analogRead(_pin));
    delay(MQ_SAMPLE_INTERVAL);
  }
  rs = rs/MQ_SAMPLE_TIMES;
  return rs;
}

int readScaled(float a, float b) {
  float ratio = readRatio();
  return exp((log(ratio)-b)/a);
}

float BaseMQ::getRo() {
  return _ro;
}

bool BaseMQ::isCalibrated() {
  return _stateCalibrate;
}

float BaseMQ::readRatio() {
  return readRs()/getRo();
}

bool BaseMQ::heatingCompleted() {
  if ((_heater) && (!_cooler) && (millis() - _prMillis > 60000))
    return true;
  else
    return false;
}

bool BaseMQ::coolanceCompleted() {
  if ((_heater) && (_cooler) && (millis() - _prMillis > 90000))
    return true;
  else
    return false;
}

void BaseMQ::cycleHeat() {
  _heater = false;
  _cooler = false;
  heaterPwrHigh();
  Serial.println("Heated sensor");
}

bool BaseMQ::atHeatCycleEnd() {
  if (heatingCompleted()) {
    heaterPwrLow();
    Serial.println("Cool sensor");
    return false;
  } else if (coolanceCompleted()) {
    heaterPwrOff();
    return true;
  } else {
    return false;
  }
}
