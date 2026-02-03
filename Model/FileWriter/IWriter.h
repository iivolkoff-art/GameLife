#ifndef IWRITER_H
#define IWRITER_H

#include <string>

template<typename T>
class IWriter{
public:
    virtual void write(const T& data) const = 0;
    virtual void setPath(const std::string& path) = 0;
    virtual ~IWriter() = default;
};

#endif // IWRITER_H
