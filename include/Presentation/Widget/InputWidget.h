#pragma once

#include <QWidget>

#include "Controller/RequestController.h"

class InputWidget : public QWidget
{
    Q_OBJECT
private:
    RequestController* controller_;
    // QString current_code_from_;
    // QString current_code_to_;

public:
    explicit InputWidget(RequestController* controller, QWidget* parent = nullptr);
};
