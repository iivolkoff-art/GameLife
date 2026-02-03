#include <fstream>
#include <sstream>
#include <stdexcept>

#include "DefaultReader.h"

std::string DefaultReader::read(const std::string& filePath) const {

    std::ifstream file(filePath, std::ios::in | std::ios::binary);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filePath);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}
