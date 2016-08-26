#ifndef MQ7_H_
#define MQ7_H_

#include "BaseMQ.h"

class MQ7 : public BaseMQ {
public: 
	MQ7(uint8_t pin);
	MQ7(uint8_t pin, uint8_t pinHeater);
	unsigned long readCarbonMonoxide();
private:
	// Резистор установленный на плату (кОм)
	virtual int getRL() const { return 10; }
	// коефициент чистого воздуха
	virtual float getRoInCleanAir() const { return 27; }
};

#endif  // MQ7_H_
