#include "../include/Presentation/Widget/InputWidget.h"

#include <qlayout.h>
#include <thread>

#include "Presentation/Widget/ChooseExTypeWidget.h"
#include "Presentation/Widget/InsertExAmountWidget.h"


InputWidget::InputWidget(ApiController* controller, QWidget* parent)
    : QWidget(parent), controller_(controller)
{
    auto* choose_widget = new ChooseExTypeWidget();
    auto* insert_widget = new InsertExAmountWidget();
    insert_widget->setFixedHeight(50);

    connect(controller_, &ApiController::currencyExchangeReady, this, &InputWidget::currencyCounted);
    connect(insert_widget,&InsertExAmountWidget::changedCurrentText,this,&InputWidget::countNewValue);
    connect(choose_widget,&ChooseExTypeWidget::changedCurrentTextFrom,this,&InputWidget::changedCurrentTextFrom);
    connect(choose_widget,&ChooseExTypeWidget::changedCurrentTextTo,this,&InputWidget::changedCurrentTextTo);

    connect(this,&InputWidget::valueCounted,insert_widget,&InsertExAmountWidget::getCountedText);

    auto* layout = new QVBoxLayout();

    layout->addWidget(choose_widget);
    layout->addWidget(insert_widget);

    setLayout(layout);
}

void InputWidget::currencyCounted(const float val)
{
    emit(valueCounted(QString::number(val)));
}

void InputWidget::countNewValue(const QString& text)
{
    QMetaObject::invokeMethod(controller_, "getCurrencyExchange",Qt::QueuedConnection,
                                  Q_ARG(std::string, current_code_to_),
                                  Q_ARG(std::string, current_code_from_),
                                  Q_ARG(std::string, text.toStdString()));
}

void InputWidget::changedCurrentTextFrom(const QString& text)
{
    current_code_from_ = text.toStdString();
}

void InputWidget::changedCurrentTextTo(const QString& text)
{
    current_code_to_ = text.toStdString();
}
