#ifndef IREADER_H
#define IREADER_H

#include <string>

template<typename T>
class IReader{
public:
    virtual T read(const std::string& filePath) const = 0;
    virtual ~IReader() = default;
};

#endif // IREADER_H
