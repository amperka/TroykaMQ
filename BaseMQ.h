#ifndef BaseMQ_H
#define BaseMQ_H
#include <Arduino.h>
// кол-во считываний значений в цикле
#define MQ_SAMPLE_TIMES 5
// задержка после каждого считывания датчика
#define MQ_SAMPLE_INTERVAL 20

class BaseMQ {
public:
	BaseMQ(uint8_t pin);
	BaseMQ(uint8_t pin, uint8_t pinHeater);
	void calibrate();
	void calibrate(float ro);
	void heaterPwrHigh();
	void heaterPwrLow();
	void heaterPwrOff();
	void cycleHeat();
	bool heatingCompleted();
	bool coolanceCompleted();
	bool isCalibrated();
	bool atHeatCycleEnd();
	float getRo();
	float readRatio();
protected:
	bool _heater = false;
	bool _cooler = false;
	bool _stateCalibrate = false;
	unsigned long _prMillis;
	float _ro;
	uint8_t _pin;
	uint8_t _pinHeater;
	float readRs();
	float calculateResistance(int rawAdc);
	virtual float getRoInCleanAir() const = 0;
	virtual int getRL() const = 0;
};

#endif 