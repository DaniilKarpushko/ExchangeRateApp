#pragma once
#include <string>

#include "ExchangeCounter.h"
#include "ExchangeDataParser/ExchangeDataParser.h"

class RequestController
{
    std::string api_id_;
    ExchangeData current_data_;
    ExchangeDataParser exchange_data_parser_;

public:
    RequestController(const std::string& api_id, const ExchangeDataParser ep)
        : api_id_(api_id), exchange_data_parser_(ep)
    {
    }

    ExchangeData getExchangeData();
    float valueConvertion(const std::string& val_to, const std::string& val_from, float amount);
};
