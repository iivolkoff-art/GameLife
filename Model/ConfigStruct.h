#ifndef CONFIGSTRUCT_H
#define CONFIGSTRUCT_H

#include <cstdint>

struct ConfigStruct {
    struct World {
        uint8_t height;
        uint8_t width;
        std::vector<std::string> cells;
    } world;

    struct Simulation {
        uint16_t fps;
        uint16_t cycles;
    } simulation;
};

#endif // CONFIGSTRUCT_H
