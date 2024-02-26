#pragma once
#include <string>
#include <map>

struct ExchangeData
{
    std::string base;
    std::map<std::string, float> exchange;
    long status_code;
};
