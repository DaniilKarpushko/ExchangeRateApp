#pragma once
#include <string>

#include "RequestService.h"
#include "ExchangeData/ExchangeData.h"


class CurrentExchangeService
{
    ExchangeData current_exchange_data_{};
    MonthlyExchangeData current_monthly_exchange_data_{};
    RequsetService* requset_service_;

public:
    explicit CurrentExchangeService(RequsetService* requset_service)
        : requset_service_(requset_service){}

    float getData(const std::string& code_to, const std::string& code_from, float amount);
    std::vector<std::pair<std::string,float>> getMonthlyData(const std::string& code_to, const std::string& code_from);
};
