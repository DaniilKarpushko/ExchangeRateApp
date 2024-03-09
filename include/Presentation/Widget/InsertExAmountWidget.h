#pragma once
#include <iostream>

#include "ChooseExTypeWidget.h"

class InsertExAmountWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InsertExAmountWidget(QWidget* parent = nullptr);

public slots:
    void applyNewText(const QString& text);
    void updText(const QString& text);

signals:
    void updateNewText(const QString& text);
};
