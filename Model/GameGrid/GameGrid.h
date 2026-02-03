#ifndef GAMEGRID_H
#define GAMEGRID_H

#include <cstdint>
#include <vector>


class GameGrid {
private:
    uint8_t rows;
    uint8_t cols;
    std::vector<std::vector<bool>> cells;

public:
    GameGrid(uint8_t r, uint8_t c);
    GameGrid(const GameGrid& other);

    uint8_t countNeighbors(uint8_t row, uint8_t col) const;

    const std::vector<std::vector<bool>>& getCells() const;
    void setCell(uint8_t rows, uint8_t cols, bool state);
    bool getCell(uint8_t rows, uint8_t cols) const;
    uint8_t getRows() const;
    uint8_t getCols() const;
};

#endif // GAMEGRID_H
