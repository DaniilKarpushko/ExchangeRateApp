#pragma once
#include <iostream>

#include "ChooseExTypeWidget.h"

class InsertExAmountWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InsertExAmountWidget(QWidget* parent = nullptr);

public slots:
    void setText(const QString& text);
    void getCountedText(const QString& text);

signals:
    void changedCurrentText(const QString& text);
    void sendCountedText(const QString& text);
};
