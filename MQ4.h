#ifndef MQ4_H_
#define MQ4_H_

#include "BaseMQ.h"

class MQ4 : public BaseMQ {
public: 
	MQ4(uint8_t pin);
	MQ4(uint8_t pin, uint8_t pinHeater);
	unsigned long readMethane();
private:
	// Резистор установленный на плату (кОм)
	virtual int getRL() const { return 20; }
	// коефициент чистого воздуха
	virtual float getRoInCleanAir() const { return 4.4; }
};

#endif  // MQ4_H_
