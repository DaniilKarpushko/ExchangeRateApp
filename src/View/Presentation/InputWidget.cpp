#include "../include/Presentation/Widget/InputWidget.h"

#include <qlayout.h>

#include "Presentation/Widget/ChooseExTypeWidget.h"
#include "Presentation/Widget/InsertExAmountWidget.h"


InputWidget::InputWidget(RequestController* controller, QWidget* parent)
    : QWidget(parent), controller_(controller)
{
    auto* choose_widget = new ChooseExTypeWidget();
    auto* insert_widget = new InsertExAmountWidget();
    insert_widget->setFixedSize(insert_widget->size().width(),50);

    connect(insert_widget,&InsertExAmountWidget::changedCurrentText,this,&InputWidget::countNewValue);
    connect(choose_widget,&ChooseExTypeWidget::changedCurrentTextFrom,this,&InputWidget::changedCurrentTextFrom);
    connect(choose_widget,&ChooseExTypeWidget::changedCurrentTextTo,this,&InputWidget::changedCurrentTextTo);

    connect(this,&InputWidget::valueCounted,insert_widget,&InsertExAmountWidget::getCountedText);

    auto* layout = new QVBoxLayout();

    layout->addWidget(choose_widget);
    layout->addWidget(insert_widget);

    setLayout(layout);
}

void InputWidget::countNewValue(const QString& text)
{
    float val = controller_->valueConvertion(current_code_to_, current_code_from_,text.toStdString());
    emit(valueCounted(QString::number(val)));
}

void InputWidget::changedCurrentTextFrom(const QString& text)
{
    current_code_from_ = text.toStdString();
    std::cout << current_code_from_ << '\n';
}

void InputWidget::changedCurrentTextTo(const QString& text)
{
    current_code_to_ = text.toStdString();
    std::cout << current_code_to_ << '\n';
}
