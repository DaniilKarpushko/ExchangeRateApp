#pragma once
#include "../ExchangeData/ExchangeData.h"

class ExchangeDataParser
{
public:
    ExchangeData ParsenJsonData(const std::string& json_string);
};
