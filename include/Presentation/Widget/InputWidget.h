#pragma once

#include <QWidget>

#include "Controller/ApiController.h"

class InputWidget : public QWidget
{
    Q_OBJECT

    ApiController* controller_;
    std::string current_code_from_;
    std::string current_code_to_;

public:
    explicit InputWidget(ApiController* controller, QWidget* parent = nullptr);
    std::string getCurrencyFrom() { return current_code_from_; };
    std::string getCurrencyTo() { return current_code_to_; };

public slots:
    void currencyCounted(float val);
    void countNewValue(const QString& text);
    void changedCurrentTextFrom(const QString& text);
    void changedCurrentTextTo(const QString& text);
signals:
    void valueCounted(const QString& text);
};
