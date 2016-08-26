#ifndef MQ9_H_
#define MQ9_H_

#include "BaseMQ.h"

class MQ9 : public BaseMQ {
public: 
	MQ9(uint8_t pin);
	MQ9(uint8_t pin, uint8_t pinHeater);
	unsigned long readLPG();
	unsigned long readMethane();
	unsigned long readCarbonMonoxide();
private:
	// Резистор установленный на плату (кОм)
	virtual int getRL() const { return 10; }
	// коефициент чистого воздуха
	virtual float getRoInCleanAir() const { return 9.8; }
};

#endif  // MQ9_H_
