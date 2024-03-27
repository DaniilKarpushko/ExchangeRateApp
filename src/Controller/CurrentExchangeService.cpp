#include <iostream>

#include "../include/Controller/CurrentExchangeService.h"


float CurrentExchangeService::getData(const std::string& code_to, const std::string& code_from, float amount)
{
    if (code_to == current_exchange_data_.currency_to && code_from == current_exchange_data_.currency_from)
    {
        return current_exchange_data_.amount_to * amount;
    }

    current_exchange_data_ = requset_service_->getData(code_to, code_from);
    if (current_exchange_data_.details == "Done")
    {
        return current_exchange_data_.amount_to * amount;
    }
    std::cout << current_exchange_data_.details << '\n';
    return -1;
}

std::vector<std::pair<std::string, float>> CurrentExchangeService::getMonthlyData(const std::string& code_to,
    const std::string& code_from)
{
    if (current_monthly_exchange_data_.currency_from == code_from &&
        current_monthly_exchange_data_.currency_to == code_to &&
        current_monthly_exchange_data_.date == QDate::currentDate())
    {
        return current_monthly_exchange_data_.monthly_data;
    }

    current_monthly_exchange_data_ = requset_service_->getMonthlyData(code_to, code_from);
    if (current_monthly_exchange_data_.details == "Done")
    {
        return current_monthly_exchange_data_.monthly_data;
    }

    std::cout << current_monthly_exchange_data_.details;
    return current_monthly_exchange_data_.monthly_data;
}
