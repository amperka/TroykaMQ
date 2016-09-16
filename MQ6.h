#ifndef MQ6_H_
#define MQ6_H_

#include "BaseMQ.h"

class MQ6 : public BaseMQ {
public: 
	MQ6(uint8_t pin);
	MQ6(uint8_t pin, uint8_t pinHeater);
	unsigned long readLPG();
private:
	// Резистор установленный на плату (кОм)
	virtual int getRL() const { return 20; }
	// коефициент чистого воздуха
	virtual float getRoInCleanAir() const { return 10; }
};

#endif  // MQ6_H_
