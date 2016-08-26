#ifndef MQ2_H_
#define MQ2_H_

#include "BaseMQ.h"

class MQ2 : public BaseMQ {
public: 
	MQ2(uint8_t pin);
	MQ2(uint8_t pin, uint8_t pinHeater);
	unsigned long readLPG();
	unsigned long readMethane();
	unsigned long readSmoke();
	unsigned long readHydrogen();
private:
	// Резистор установленный на плату (кОм)
	virtual int getRL() const { return 5; }
	// коефициент чистого воздуха
	virtual float getRoInCleanAir() const { return 9.83; }
};

#endif  // MQ2_H_
