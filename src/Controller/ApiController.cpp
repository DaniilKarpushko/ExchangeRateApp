#include <cpr/cpr.h>
#include<iostream>
#include <QApplication>

#include "Controller/ApiController.h"
#include "ExchangeDataParser/ExchangeDataTranslator.h"


void ApiController::getCurrencyExchange(const std::string& val_to, const std::string& val_from,
                                        const std::string& amount)
{
    try
    {
        auto amount_temp = std::stof(amount);
        emit(currencyExchangeReady(current_exchange_service_->getData(dictionary_reversed[val_to],
                                                                      dictionary_reversed[val_from],
                                                                      amount_temp)));
    }
    catch (std::invalid_argument& ex)
    {
        std::cout << "Wrong amount input: " << amount << '\n';
    }
}

void ApiController::getMonthlyCurrencyExchange(const std::string& code_to,
                                               const std::string& code_from)
{
    emit(monthlyCurrencyExchangeReady(
        current_exchange_service_->getMonthlyData(dictionary_reversed[code_to], dictionary_reversed[code_from])));
}
