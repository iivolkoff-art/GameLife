#ifndef JSONCONFIGSTRUCTPARSER_H
#define JSONCONFIGSTRUCTPARSER_H

#include "IParser.h"

#include <QJsonObject>
#include "../ConfigStruct.h"

class JSONConfigStructParser : public IParser<ConfigStruct, QJsonObject>
{
public:
    ConfigStruct parse(const QJsonObject& data) const override;
};

#endif // JSONCONFIGSTRUCTPARSER_H
