#ifndef MQ4_H_
#define MQ4_H_

#include "BaseMQ.h"

// резистор установленный на плату (кОм)
#define MQ4_RL_BOARD            20
// коефициент чистого воздуха из графика
#define MQ4_RO_IN_CLEAR_AIR     4.4

class MQ4 : public BaseMQ {
public: 
    MQ4(uint8_t pin);
    MQ4(uint8_t pin, uint8_t pinHeater);
    unsigned long readMethane();
private:
    virtual int getRL() const { return MQ4_RL_BOARD ; }
    virtual float getRoInCleanAir() const { return MQ4_RO_IN_CLEAR_AIR; }
};

#endif  // MQ4_H_
