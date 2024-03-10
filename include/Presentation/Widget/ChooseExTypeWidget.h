//
// Created by antikill on 26.02.2024.
//
#pragma once

#ifndef EXCHANGEWIDGET_H
#define EXCHANGEWIDGET_H

#include <QTextEdit>
#include "Controller/RequestController.h"

class ChooseExTypeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseExTypeWidget(QWidget* parent = nullptr);

public slots:
    void currentTextToUpd(const QString& text);
    void currentTextFromUpd(const QString& text);
signals:
    void changedCurrentTextTo(const QString& text);
    void changedCurrentTextFrom(const QString& text);
};


#endif //EXCHANGEWIDGET_H
