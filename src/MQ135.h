#ifndef MQ135_H_
#define MQ135_H_

#include "BaseMQ.h"

// резистор установленный на плату (кОм)
#define MQ135_RL_BOARD          10

// концентрация углекислого газа в сухом воздухе
#define PPM_CO2_IN_CLEAR_AIR    397.13

class MQ135 : public BaseMQ {
public: 
    MQ135(uint8_t pin);
    MQ135(uint8_t pin, uint8_t pinHeater);
    unsigned long readCO2();
private:
    virtual int getRL() const {
        return MQ135_RL_BOARD;
    }
    virtual float getRoInCleanAir() const {
        return exp((log(PPM_CO2_IN_CLEAR_AIR) * -0.42) + 1.92);
    }
};

#endif  // MQ135_H_
