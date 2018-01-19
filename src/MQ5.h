#ifndef MQ5_H_
#define MQ5_H_

#include "BaseMQ.h"

// резистор установленный на плату (кОм)
#define MQ5_RL_BOARD            20
// коефициент чистого воздуха из графика
#define MQ5_RO_IN_CLEAR_AIR     6.5

class MQ5 : public BaseMQ {
public: 
    MQ5(uint8_t pin);
    MQ5(uint8_t pin, uint8_t pinHeater);
    unsigned long readLPG();
    unsigned long readMethane();
private:
    virtual int getRL() const { return MQ5_RL_BOARD; }
    virtual float getRoInCleanAir() const { return MQ5_RO_IN_CLEAR_AIR; }
};

#endif  // MQ5_H_
