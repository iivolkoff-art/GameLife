#include "StandartRule.h"

bool StandartRule::willBeAlive(bool currentState, uint8_t neighbors) const {
    if (currentState){
        return (neighbors == 2 || neighbors == 3);
    }

    return (neighbors == 3);
}
