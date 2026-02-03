#include "VectVectBoolResultParser.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

std::string VectVectBoolResultParser::parse(const std::vector<std::vector<bool>>& data) const{
    if (data.empty()) return "{}";

    int height = data.size();
    int width = data[0].size();

    QJsonArray cellsArray;

    for (const auto& row : data) {
        std::string rowString;
        rowString.reserve(width);

        for (const bool& cell : row) {
            rowString += (cell ? '*' : '.');
        }

        cellsArray.append(QString::fromStdString(rowString));
    }

    QJsonObject resultData;
    resultData["cells"] = cellsArray;
    resultData["width"] = width;
    resultData["height"] = height;

    QJsonObject root;
    root["result"] = resultData;

    QJsonDocument doc(root);

    return doc.toJson(QJsonDocument::Indented).toStdString();
}
