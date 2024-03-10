#include "../include/Presentation/Widget/ChooseExTypeWidget.h"
#include "Presentation/Widget/ChooseExTypeWidget.h"

#include <iostream>
#include <QVBoxLayout>
#include <QLineEdit>

#include "../include/ExchangeDataParser/ExchangeDataTranslator.h"
#include "Presentation/Widget/ListWidget.h"

int WLENGTH = 360;
int WWIDTH = 720;

ChooseExTypeWidget::ChooseExTypeWidget(QWidget* parent)
    : QWidget(parent)
{
    auto* list_to = new ListWidget();
    auto* list_from = new ListWidget();
    list_to->addItem("");
    list_from->addItem("");
    list_to->addItems(exchange_names);
    list_from->addItems(exchange_names);

    connect(list_from,&QComboBox::currentTextChanged,this,&ChooseExTypeWidget::currentTextFromUpd);
    connect(list_to,&QComboBox::currentTextChanged,this,&ChooseExTypeWidget::currentTextToUpd);

    auto* layout = new QHBoxLayout(this);

    layout->addWidget(list_from);
    layout->addWidget(list_to);

    setLayout(layout);
}
void ChooseExTypeWidget::currentTextToUpd(const QString& text)
{
    emit changedCurrentTextTo(text);
}

void ChooseExTypeWidget::currentTextFromUpd(const QString& text)
{
    emit changedCurrentTextFrom(text);
}
