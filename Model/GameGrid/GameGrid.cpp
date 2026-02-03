#include "GameGrid.h"


GameGrid::GameGrid(uint8_t r, uint8_t c) :
    rows(r), cols(c), cells(r, std::vector<bool>(c, false)){

}

GameGrid::GameGrid(const GameGrid& other) :
    rows(other.rows), cols(other.cols), cells(other.cells) {
}


uint8_t GameGrid::countNeighbors(uint8_t row, uint8_t col) const {
    uint8_t count = 0;

    int16_t r = static_cast<int16_t>(row);
    int16_t c = static_cast<int16_t>(col);

    for (int16_t dr = -1; dr <= 1; ++dr) {
        for (int16_t dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) continue;

            int16_t nr = r + dr;
            int16_t nc = c + dc;
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                if (cells[static_cast<size_t>(nr)][static_cast<size_t>(nc)]) {
                    count++;
                }
            }
        }
    }
    return count;
}


const std::vector<std::vector<bool>>& GameGrid::getCells() const {
    return this->cells;
}


void GameGrid::setCell(uint8_t rows, uint8_t cols, bool state){
    this->cells[rows][cols] = state;
}


bool GameGrid::getCell(uint8_t rows, uint8_t cols) const {
    return this->cells[rows][cols];
}


uint8_t GameGrid::getRows() const {
    return this->rows;
}


uint8_t GameGrid::getCols() const {
    return this->cols;
}
