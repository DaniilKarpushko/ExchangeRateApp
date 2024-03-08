#pragma once
#include <iostream>

#include "ChooseExTypeWidget.h"

class InsertExAmountWidget : public QWidget
{
public:
    explicit InsertExAmountWidget(QWidget* parent = nullptr);
private slots:
    void SendText();
};