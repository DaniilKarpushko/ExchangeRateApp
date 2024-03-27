#pragma once
#include <string>
#include <vector>
#include "CurrentExchangeService.h"
#include "RequestService.h"


class ApiController : public QObject
{
    Q_OBJECT
    CurrentExchangeService* current_exchange_service_;

public:
    explicit ApiController(CurrentExchangeService* requset_service, QObject *parent = nullptr)
        : current_exchange_service_(requset_service)
    {
    }

public slots:
    void getCurrencyExchange(const std::string& val_to, const std::string& val_from, const std::string& amount);
    void getMonthlyCurrencyExchange(
        const std::string& code_to, const std::string& code_from);
signals:
    void currencyExchangeReady(float result);
    void monthlyCurrencyExchangeReady(std::vector<std::pair<std::string, float>> result);
};
