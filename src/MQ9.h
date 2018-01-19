#ifndef MQ9_H_
#define MQ9_H_

#include "BaseMQ.h"

// резистор установленный на плату (кОм)
#define MQ9_RL_BOARD            10
// коефициент чистого воздуха из графика
#define MQ9_RO_IN_CLEAR_AIR     9.8

class MQ9 : public BaseMQ {
public: 
    MQ9(uint8_t pin);
    MQ9(uint8_t pin, uint8_t pinHeater);
    unsigned long readLPG();
    unsigned long readMethane();
    unsigned long readCarbonMonoxide();
private:
    // Резистор установленный на плату (кОм)
    virtual int getRL() const { return MQ9_RL_BOARD; }
    // коефициент чистого воздуха
    virtual float getRoInCleanAir() const { return MQ9_RO_IN_CLEAR_AIR; }
};

#endif  // MQ9_H_
