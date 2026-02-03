#ifndef AIRSTRIKECONFIGSTRUCT_H
#define AIRSTRIKECONFIGSTRUCT_H

#include <vector>
#include <cstdint>
#include <string>

struct AirStrikeConfigStruct {
    struct World {
        uint8_t height;
        uint8_t width;
        std::vector<std::string> cells;
    } world;

    struct Simulation {
        uint16_t fps;
        uint16_t cycles;
    } simulation;

    struct Airstrike {
        uint16_t cycle;
        uint8_t row;
        uint8_t col;
    };

    struct AirstrikeSettings {
        uint8_t radius = 0;
        std::vector<Airstrike> strikes;
    } airstrikeSettings;
};

#endif // AIRSTRIKECONFIGSTRUCT_H
