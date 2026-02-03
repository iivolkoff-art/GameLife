#ifndef IRULESTRATEGY_H
#define IRULESTRATEGY_H

#include <cstdint>

class IRuleStrategy {
public:
    virtual bool willBeAlive(bool currentState, uint8_t neighbors) const = 0;
    virtual ~IRuleStrategy() = default;
};

#endif // IRULESTRATEGY_H
