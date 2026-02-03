#ifndef STANDARTRULE_H
#define STANDARTRULE_H

#include "IRuleStrategy.h"

class StandartRule : public IRuleStrategy {
public:
    bool willBeAlive(bool currentState, uint8_t neighbors) const override;
};

#endif // STANDARTRULE_H
