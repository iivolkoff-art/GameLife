#include "JSONConfigStructParser.h"
#include <QJsonDocument>
#include <QJsonArray>


ConfigStruct JSONConfigStructParser::parse(const QJsonObject& data) const{
    ConfigStruct config;

    QJsonObject worldObj = data["world"].toObject();
    config.world.height = worldObj["height"].toInt();
    config.world.width = worldObj["width"].toInt();

    QJsonArray cellsArray = worldObj["cells"].toArray();
    for (const auto& value : cellsArray) {
        config.world.cells.push_back(value.toString().toStdString());
    }

    QJsonObject simObj = data["simulation"].toObject();
    config.simulation.fps = simObj["fps"].toInt();
    config.simulation.cycles = simObj["cycles"].toInt();

    return config;
}
