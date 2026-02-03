#ifndef AIRSTRIKEJSONCONFIGSTRUCTPARSER_H
#define AIRSTRIKEJSONCONFIGSTRUCTPARSER_H

#include "IParser.h"

#include <QJsonObject>
#include "../AirStrikeConfigStruct.h"

class AirStrikeJSONConfigStructParser : public IParser<AirStrikeConfigStruct, QJsonObject>
{
public:
    AirStrikeConfigStruct parse(const QJsonObject& data) const override;
};

#endif // AIRSTRIKEJSONCONFIGSTRUCTPARSER_H
