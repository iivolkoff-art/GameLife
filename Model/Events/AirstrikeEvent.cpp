#include "AirstrikeEvent.h"

AirstrikeEvent::AirstrikeEvent(const AirStrikeConfigStruct::AirstrikeSettings& s)
    : settings(s)
{
}

void AirstrikeEvent::execute(GameGrid& grid, uint16_t currentCycle) {
    for (const auto& strike : settings.strikes) {
        if (strike.cycle == currentCycle) {
            apply(grid, strike.row, strike.col);
        }
    }
}

void AirstrikeEvent::apply(GameGrid& grid, uint8_t rw, uint8_t cl) {
    int16_t centerRow = static_cast<int16_t>(rw) - 1;
    int16_t centerCol = static_cast<int16_t>(cl) - 1;
    int16_t rad = static_cast<int16_t>(settings.radius);

    int16_t startRow = centerRow - rad;
    int16_t endRow   = centerRow + rad;
    int16_t startCol = centerCol - rad;
    int16_t endCol   = centerCol + rad;

    for (int16_t i = startRow; i <= endRow; ++i) {
        for (int16_t j = startCol; j <= endCol; ++j) {
            if (i >= 0 && i < static_cast<int16_t>(grid.getRows()) && j >= 0 && j < static_cast<int16_t>(grid.getCols())) {

                grid.setCell(static_cast<uint8_t>(i), static_cast<uint8_t>(j), false);
            }
        }
    }
}
