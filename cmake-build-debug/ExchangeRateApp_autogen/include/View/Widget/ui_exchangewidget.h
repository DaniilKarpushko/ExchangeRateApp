/********************************************************************************
** Form generated from reading UI file 'exchangewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXCHANGEWIDGET_H
#define UI_EXCHANGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExchangeWidget
{
public:

    void setupUi(QWidget *ExchangeWidget)
    {
        if (ExchangeWidget->objectName().isEmpty())
            ExchangeWidget->setObjectName("ExchangeWidget");
        ExchangeWidget->resize(400, 300);

        retranslateUi(ExchangeWidget);

        QMetaObject::connectSlotsByName(ExchangeWidget);
    } // setupUi

    void retranslateUi(QWidget *ExchangeWidget)
    {
        ExchangeWidget->setWindowTitle(QCoreApplication::translate("ExchangeWidget", "ExchangeWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExchangeWidget: public Ui_ExchangeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXCHANGEWIDGET_H
