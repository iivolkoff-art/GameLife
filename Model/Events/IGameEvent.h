#ifndef IGAMEEVENT_H
#define IGAMEEVENT_H

#include "../GameGrid/GameGrid.h"

class IGameEvent {
public:
    virtual void execute(GameGrid& grid, uint16_t currentCycle) = 0;
    virtual ~IGameEvent() = default;
};

#endif // IGAMEEVENT_H
