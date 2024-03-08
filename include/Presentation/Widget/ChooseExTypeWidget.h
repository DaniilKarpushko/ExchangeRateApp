//
// Created by antikill on 26.02.2024.
//
#pragma once

#ifndef EXCHANGEWIDGET_H
#define EXCHANGEWIDGET_H

#include <QTextEdit>
#include "Controller/RequestController.h"


namespace Ui
{
    class ExchangeWidget;
}


class ChooseExTypeWidget : public QWidget
{
    Q_OBJECT

private:
    QStringList list_;

public:
    explicit ChooseExTypeWidget(QWidget* parent = nullptr);

    ~ChooseExTypeWidget() override;

// public slots:
//     void GetExchangeData();

private:
    Ui::ExchangeWidget* ui{};

    static QString ConfigureText(const ExchangeData& data);
};


#endif //EXCHANGEWIDGET_H
