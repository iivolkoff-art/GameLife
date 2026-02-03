#ifndef DEFAULTWRITER_H
#define DEFAULTWRITER_H

#include <QJsonObject>
#include <string>

#include "IWriter.h"

class DefaultWriter : public IWriter<std::string>
{
private:
    std::string path;
public:
    DefaultWriter();
    void write(const std::string& data) const override;
    void setPath(const std::string& path) override;
};

#endif // DEFAULTWRITER_H
