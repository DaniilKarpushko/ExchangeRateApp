#pragma once
#include <string>

#include "ExchangeData/ExchangeData.h"
#include "ExchangeData/MonthlyExchangeData.h"


class RequsetService
{
    std::string api_key_;

public:
    explicit RequsetService(const std::string& key)
        : api_key_(key)
    {
    }

    ExchangeData getData(const std::string& code_to, const std::string& code_from);

    MonthlyExchangeData getMonthlyData(const std::string& code_to, const std::string& code_from);
};
