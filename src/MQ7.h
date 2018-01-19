#ifndef MQ7_H_
#define MQ7_H_

#include "BaseMQ.h"

// резистор установленный на плату (кОм)
#define MQ7_RL_BOARD            10
// коефициент чистого воздуха из графика
#define MQ7_RO_IN_CLEAR_AIR     27

class MQ7 : public BaseMQ {
public: 
    MQ7(uint8_t pin);
    MQ7(uint8_t pin, uint8_t pinHeater);
    unsigned long readCarbonMonoxide();
private:
    virtual int getRL() const { return MQ7_RL_BOARD; }
    virtual float getRoInCleanAir() const { return MQ7_RO_IN_CLEAR_AIR; }
};

#endif  // MQ7_H_
