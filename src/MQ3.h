#ifndef MQ3_H_
#define MQ3_H_

#include "BaseMQ.h"

// резистор установленный на плату (кОм)
#define MQ3_RL_BOARD            200
// коефициент чистого воздуха из графика
#define MQ3_RO_IN_CLEAR_AIR     60

class MQ3 : public BaseMQ {
public: 
    MQ3(uint8_t pin);
    MQ3(uint8_t pin, uint8_t pinHeater);
    float readAlcoholMgL();
    float readAlcoholPpm();
private:
    virtual int getRL() const { return MQ3_RL_BOARD; }
    virtual float getRoInCleanAir() const { return MQ3_RO_IN_CLEAR_AIR; }
};

#endif  // MQ3_H_
