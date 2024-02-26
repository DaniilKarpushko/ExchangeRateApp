#include "Controller/RequestController.h"
#include <cpr/cpr.h>
#include<iostream>

ExchangeData RequestController::GetExchangeData()
{
    cpr::Url request = "https://openexchangerates.org/api/latest.json?app_id=" + api_id_;
    const cpr::Response response = cpr::Get(request);
    long status_code = response.status_code;

    if (response.status_code == 200)
    {
        return exchange_data_parser_.ParsenJsonData(response.text);
    }

    return ExchangeData("", std::map<std::string, float>(), status_code);
}
