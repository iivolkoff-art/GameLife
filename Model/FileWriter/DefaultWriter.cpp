#include "DefaultWriter.h"
#include <fstream>
#include <filesystem>

DefaultWriter::DefaultWriter() : path("output.txt"){
}

void DefaultWriter::write(const std::string& data) const {
    std::string tmpPath = this->path + ".tmp";

    std::ofstream file(tmpPath);
    file << data;
    file.close();

    std::filesystem::rename(tmpPath, this->path);
}


void DefaultWriter::setPath(const std::string& path){
    this->path = path;
}
