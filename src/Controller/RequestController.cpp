#include "Controller/RequestController.h"
#include <cpr/cpr.h>
#include<iostream>

void RequestController::Get()
{
    cpr::Url request = "https://openexchangerates.org/api/latest.json?app_id=" + api_id_;
    const cpr::Response response = cpr::Get(request);
    if(response.status_code == 200)
    {
        const auto res = exchange_data_parser_.ParsenJsonData(response.text);
        std::cout << res.Base << '\n';
        for(const auto& el : res.Exchange)
        {
            std::cout << el.first << " " << el.second << '\n';
        }
    }
}