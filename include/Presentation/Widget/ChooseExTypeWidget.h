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

private:
    QStringList* list_;

public:
    explicit ChooseExTypeWidget(QWidget* parent = nullptr);
    ~ChooseExTypeWidget() override;

public slots:
    void getExToData(const QString& text);
    void getExFromData(const QString& text);
signals:
    void changedExTo(const QString& text);
    void changedExFrom(const QString& text);
};


#endif //EXCHANGEWIDGET_H
