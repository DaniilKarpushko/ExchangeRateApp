#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <iostream>

#include "../include/Controller/RequestService.h"

ExchangeData RequsetService::getData(const std::string& code_to, const std::string& code_from)
{
    cpr::Url request = "https://www.alphavantage.co/query?function=CURRENCY_EXCHANGE_RATE&from_currency=" + code_from +
        "&to_currency=" + code_to + "&apikey=" + api_key_;

    cpr::Response response = cpr::Get(request);
    nlohmann::json jsonObj = nlohmann::json::parse(response.text);
    ExchangeData data{};
    try
    {
        std::string amount = jsonObj["Realtime Currency Exchange Rate"]["5. Exchange Rate"];
        data = ExchangeData{
            jsonObj["Realtime Currency Exchange Rate"]["3. To_Currency Code"],
            jsonObj["Realtime Currency Exchange Rate"]["1. From_Currency Code"],
            std::stof(amount), 1
        };
        data.details = "Done";
    }
    catch (nlohmann::detail::type_error& ex)
    {
        data.details = response.text;
    }
    return data;
}

MonthlyExchangeData RequsetService::getMonthlyData(const std::string& code_to, const std::string& code_from)
{
    cpr::Url request = "https://www.alphavantage.co/query?function=FX_MONTHLY&from_symbol=" + code_from + "&to_symbol="
        + code_to + "&apikey=" + api_key_;
    const cpr::Response response = cpr::GetAsync(request).get();
    nlohmann::json jsonObj = nlohmann::json::parse(response.text);
    MonthlyExchangeData data{};
    data.date = QDate::currentDate();
    try
    {
        data.currency_from.append(jsonObj["Meta Data"]["2. From Symbol"]);
        data.currency_to.append(jsonObj["Meta Data"]["3. To Symbol"]);
        for (auto [date, data_temp] : jsonObj["Time Series FX (Monthly)"].items())
        {
            data.monthly_data.emplace_back(date, std::stof(
                                               nlohmann::to_string(data_temp["4. close"]).substr(
                                                   1, nlohmann::to_string(data_temp["4. close"]).length() - 1)));
        }
        data.details = "Done";
    }
    catch (nlohmann::detail::type_error& ex)
    {
        std::cout << response.text << '\n';
        data.details = response.text;
    }
    return data;
}
