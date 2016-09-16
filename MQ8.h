#ifndef MQ8_H_
#define MQ8_H_

#include "BaseMQ.h"

class MQ8 : public BaseMQ {
public: 
	MQ8(uint8_t pin);
	MQ8(uint8_t pin, uint8_t pinHeater);
	unsigned long readHydrogen();
private:
	// Резистор установленный на плату (кОм)
	virtual int getRL() const { return 10; }
	// коефициент чистого воздуха
	virtual float getRoInCleanAir() const { return 70; }
};

#endif  // MQ8_H_
