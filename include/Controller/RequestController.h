#pragma once
#include <string>

#include "ExchangeDataParser/ExchangeDataParser.h"

class RequestController
{
    std::string api_id_;
    ExchangeDataParser exchange_data_parser_;

public:
    RequestController(const std::string& api_id, const ExchangeDataParser ep)
        : api_id_(api_id), exchange_data_parser_(ep)
    {
    }

    void Get();
};
