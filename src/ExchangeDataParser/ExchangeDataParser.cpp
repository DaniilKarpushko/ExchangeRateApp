#include "ExchangeDataParser/ExchangeDataParser.h"
#include "nlohmann/json.hpp"

ExchangeData ExchangeDataParser::ParsenJsonData(const std::string& json_string)
{
    nlohmann::json jsonObj = nlohmann::json::parse(json_string);
    return ExchangeData{jsonObj["base"],jsonObj["rates"],200};
}
