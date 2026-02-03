#ifndef VECTVECTBOOLRESULTPARSER_H
#define VECTVECTBOOLRESULTPARSER_H

#include <vector>
#include <string>

#include "IParser.h"

class VectVectBoolResultParser : public IParser<std::string, std::vector<std::vector<bool>>>
{
public:
    std::string parse(const std::vector<std::vector<bool>>& data) const override;
};

#endif // VECTVECTBOOLRESULTPARSER_H
