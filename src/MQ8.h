#ifndef MQ8_H_
#define MQ8_H_

#include "BaseMQ.h"

// резистор установленный на плату (кОм)
#define MQ8_RL_BOARD            10
// коефициент чистого воздуха из графика
#define MQ8_RO_IN_CLEAR_AIR     27

class MQ8 : public BaseMQ {
public: 
    MQ8(uint8_t pin);
    MQ8(uint8_t pin, uint8_t pinHeater);
    unsigned long readHydrogen();
private:
    virtual int getRL() const { return MQ8_RL_BOARD; }
    virtual float getRoInCleanAir() const { return MQ8_RO_IN_CLEAR_AIR ; }
};

#endif  // MQ8_H_
