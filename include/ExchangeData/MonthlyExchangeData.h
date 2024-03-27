#pragma once
#include <QDate>
#include <vector>

struct MonthlyExchangeData
{
    std::string currency_to;
    std::string currency_from;
    QDate date;
    std::vector<std::pair<std::string,float>> monthly_data;
    std::string details;
};
