#ifndef MQ6_H_
#define MQ6_H_

#include "BaseMQ.h"

// резистор установленный на плату (кОм)
#define MQ6_RL_BOARD            20
// коефициент чистого воздуха из графика
#define MQ6_RO_IN_CLEAR_AIR     10

class MQ6 : public BaseMQ {
public: 
    MQ6(uint8_t pin);
    MQ6(uint8_t pin, uint8_t pinHeater);
    unsigned long readLPG();
private:
    virtual int getRL() const { return MQ6_RL_BOARD ; }
    virtual float getRoInCleanAir() const { return MQ6_RO_IN_CLEAR_AIR; }
};

#endif  // MQ6_H_
