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
	bool atHeatCycleEnd();
	bool heatingCompleted() const;
	bool coolanceCompleted() const;
	float readRatio() const;
	inline bool isCalibrated() const {
		return _stateCalibrate;
	};
	inline float getRo() const {
		return _ro;
        };

protected:
	unsigned long readScaled(float a, float b) const;
	virtual float getRoInCleanAir() const = 0;
	virtual int getRL() const = 0;

private:
	bool _heater = false;
	bool _cooler = false;
	bool _stateCalibrate = false;
	unsigned long _prMillis = 0;
	float _ro = 1.0f;
	uint8_t _pin;
	uint8_t _pinHeater;
	float readRs() const;
	float calculateResistance(int rawAdc) const;
};

#endif 
