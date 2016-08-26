#ifndef MQ3_H_
#define MQ3_H_

#include "BaseMQ.h"

class MQ3 : public BaseMQ {
public: 
	MQ3(uint8_t pin);
	MQ3(uint8_t pin, uint8_t pinHeater);
	float readAlcoholMgL();
	float readAlcoholPpm();
private:
	// Резистор установленный на плату (кОм)
	virtual int getRL() const { return 200; }
	// коефициент чистого воздуха
	virtual float getRoInCleanAir() const { return 60; }
};

#endif  // MQ3_H_
