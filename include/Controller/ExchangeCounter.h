#pragma once
#include <ExchangeData/ExchangeData.h>
#include <ExchangeDataParser/ExchangeDataTranslator.h>
class ExchangeCounter
{
public:
    static float countDifference(ExchangeData& data, const std::string& convert_from, const std::string& convert_to, float amount)
    {
        return data.exchange[convert_from]/data.exchange[convert_to] * amount;
    }
};