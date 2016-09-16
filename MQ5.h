#ifndef MQ5_H_
#define MQ5_H_

#include "BaseMQ.h"

class MQ5 : public BaseMQ {
public: 
	MQ5(uint8_t pin);
	MQ5(uint8_t pin, uint8_t pinHeater);
	unsigned long readLPG();
	unsigned long readMethane();
private:
	// Резистор установленный на плату (кОм)
	virtual int getRL() const { return 20; }
	// коефициент чистого воздуха
	virtual float getRoInCleanAir() const { return 6.5; }
};

#endif  // MQ5_H_
