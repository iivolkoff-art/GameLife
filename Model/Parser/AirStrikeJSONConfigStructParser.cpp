#include <QJsonDocument>
#include <QJsonArray>

#include "AirStrikeJSONConfigStructParser.h"

AirStrikeConfigStruct AirStrikeJSONConfigStructParser::parse(const QJsonObject& data) const {

    AirStrikeConfigStruct config;

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

    if (data.contains("airstrike_settings")) {
        QJsonObject strikeSettingsObj = data["airstrike_settings"].toObject();
        config.airstrikeSettings.radius = strikeSettingsObj["radius"].toInt();
    }

    if (data.contains("airstrikes")) {
        QJsonArray strikesArray = data["airstrikes"].toArray();
        for (const auto& value : strikesArray) {
            QJsonObject strikeObj = value.toObject();
            AirStrikeConfigStruct::Airstrike strike;
            strike.cycle = strikeObj["cycle"].toInt();
            strike.row = strikeObj["row"].toInt();
            strike.col = strikeObj["col"].toInt();

            config.airstrikeSettings.strikes.push_back(strike);
        }
    }

    return config;
}
