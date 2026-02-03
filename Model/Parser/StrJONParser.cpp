#include "StrJONParser.h"

#include <QJsonDocument>
#include <QJsonParseError>
#include <stdexcept>
#include <QByteArray>

QJsonObject StrJONParser::parse(const std::string& data) const{
    QByteArray byteData = QByteArray::fromStdString(data);

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(byteData, &error);

    if (error.error != QJsonParseError::NoError) {
        throw std::runtime_error("JSON Parse Error: " + error.errorString().toStdString());
    }

    if (!doc.isObject()) {
        throw std::runtime_error("JSON content is not an object");
    }

    return doc.object();
}
