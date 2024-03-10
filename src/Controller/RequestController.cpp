#include "Controller/RequestController.h"
#include <ExchangeDataParser/ExchangeDataTranslator.h>
#include <cpr/cpr.h>
#include<iostream>

ExchangeData RequestController::getExchangeData()
{
    return current_data_;
}

float RequestController::valueConvertion(const std::string& val_to, const std::string& val_from, const std::string& amount)
{
    try
    {
        float amount_f = std::stof(amount);
        return ExchangeCounter::countDifference(current_data_,dictionary_reversed[val_from],dictionary_reversed[val_to], amount_f);
    }catch(const std::invalid_argument& ex)
    {
        std::cout << "Invalid Argument: " + amount << '\n';
    }
    return 0;
}

void RequestController::updateExchangeDate()
{
    cpr::Url request = "https://openexchangerates.org/api/latest.json?app_id=" + api_id_;
    const cpr::Response response = cpr::GetAsync(request).get();
    current_data_ = ExchangeData("", std::map<std::string, float>(), response.status_code);

    if (response.status_code == 200)
    {
        current_data_ = exchange_data_parser_.ParsenJsonData(response.text);
    }
}

