#ifndef AIRSTRIKEEVENT_H
#define AIRSTRIKEEVENT_H

#include <cstdint>

#include "IGameEvent.h"
#include "../AirStrikeConfigStruct.h"
#include "../GameGrid/GameGrid.h"

class AirstrikeEvent : public IGameEvent {
private:
    AirStrikeConfigStruct::AirstrikeSettings settings;

public:
    explicit AirstrikeEvent(const AirStrikeConfigStruct::AirstrikeSettings& s);
    void execute(GameGrid& grid, uint16_t currentCycle) override;

protected:
    void apply(GameGrid& grid, uint8_t rw, uint8_t cl);
};

#endif // AIRSTRIKEEVENT_H
