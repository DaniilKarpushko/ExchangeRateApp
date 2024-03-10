#pragma once

#include <QWidget>

#include "Controller/RequestController.h"

class InputWidget : public QWidget
{
    Q_OBJECT

    RequestController* controller_;
    std::string current_code_from_;
    std::string current_code_to_;

public:
    explicit InputWidget(RequestController* controller, QWidget* parent = nullptr);

public slots:
    void countNewValue(const QString& text);
    void changedCurrentTextFrom(const QString& text);
    void changedCurrentTextTo(const QString& text);
signals:
    void valueCounted(const QString& text);
};
