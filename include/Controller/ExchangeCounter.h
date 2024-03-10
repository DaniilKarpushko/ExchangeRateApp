#pragma once
#include <ExchangeData/ExchangeData.h>
class ExchangeCounter
{
public:
    static float countDifference(ExchangeData& data, const std::string& convert_from, const std::string& convert_to, float amount)
    {
        return data.exchange[convert_to]/data.exchange[convert_from]  * amount;
    }
};