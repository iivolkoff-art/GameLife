#ifndef DEFAULTREADER_H
#define DEFAULTREADER_H

#include <string>

#include "IReader.h"


class DefaultReader : public IReader<std::string>
{
public:
    std::string read(const std::string& filePath) const override;
};

#endif // DEFAULTREADER_H
