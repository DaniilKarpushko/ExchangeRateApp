//
// Created by antikill on 26.02.2024.
//
#pragma once

#ifndef EXCHANGEWIDGET_H
#define EXCHANGEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include "Controller/RequestController.h"


namespace Ui
{
    class ExchangeWidget;
}


class ExchangeWidget : public QWidget
{
    Q_OBJECT

private:
    int _lenght;
    int _width;
    RequestController* request_controller_;
    QTextEdit* text_edit_;

public:
    explicit ExchangeWidget(RequestController* request_controller, QWidget* parent = nullptr);

    ~ExchangeWidget() override;

public slots:
    void GetExchangeData();

private:
    Ui::ExchangeWidget* ui{};

    static QString ConfigureText(const ExchangeData& data);
};


#endif //EXCHANGEWIDGET_H
