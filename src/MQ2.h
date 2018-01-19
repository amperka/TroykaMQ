#ifndef MQ2_H_
#define MQ2_H_

#include "BaseMQ.h"

// резистор установленный на плату (кОм)
#define MQ2_RL_BOARD            5
// коефициент чистого воздуха из графика
#define MQ2_RO_IN_CLEAR_AIR     9.83

class MQ2 : public BaseMQ {
public:
    MQ2(uint8_t pin);
    MQ2(uint8_t pin, uint8_t pinHeater);
    unsigned long readLPG();
    unsigned long readMethane();
    unsigned long readSmoke();
    unsigned long readHydrogen();
private:
    virtual int getRL() const { return MQ2_RL_BOARD; }
    virtual float getRoInCleanAir() const { return MQ2_RO_IN_CLEAR_AIR; }
};

#endif  // MQ2_H_
