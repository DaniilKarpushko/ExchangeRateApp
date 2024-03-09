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

    connect(insert_widget,&InsertExAmountWidget::updateNewText,this,&InputWidget::updateText);
    connect(choose_widget,&ChooseExTypeWidget::changedExFrom,this,&InputWidget::setCurrentCodeFrom);
    connect(choose_widget,&ChooseExTypeWidget::changedExTo,this,&InputWidget::setCurrentCodeTo);

    // connect(this,&InputWidget::textChanged,insert_widget,&InsertExAmountWidget::updateNewText);
    auto* layout = new QVBoxLayout();

    layout->addWidget(choose_widget);
    layout->addWidget(insert_widget);

    setLayout(layout);
}

void InputWidget::updateText(const QString& text)
{
    std::cout << controller_->valueConvertion(current_code_to_, current_code_from_,text.toStdString()) << " -" << '\n';
}

void InputWidget::setCurrentCodeFrom(const QString& text)
{
    current_code_from_ = text.toStdString();
    std::cout << current_code_from_ << '\n';
}

void InputWidget::setCurrentCodeTo(const QString& text)
{
    current_code_to_ = text.toStdString();
    std::cout << current_code_to_ << '\n';
}
