#pragma once
#include <string>

struct ExchangeData
{
    std::string currency_to;
    std::string currency_from;
    float amount_to;
    float amount_from;
    std::string details;
};
