#include "ConsoleRender.h"
#include <iostream>
//#include <cstdlib>


void ConsoleRender::render(const std::vector<std::vector<bool>>& grid){
    for (const auto& row : grid) {
        for (const bool& cell : row) {
            std::cout << (cell ? "*" : ".");
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

