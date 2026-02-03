#ifndef STRJONPARSER_H
#define STRJONPARSER_H

#include <string>
#include <QJsonObject>

#include "IParser.h"

class StrJONParser : public IParser<QJsonObject, std::string>
{
public:
    QJsonObject parse(const std::string& data) const override;
};

#endif // STRJONPARSER_H
