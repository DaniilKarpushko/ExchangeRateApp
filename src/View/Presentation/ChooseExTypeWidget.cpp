#include "../include/Presentation/Widget/ChooseExTypeWidget.h"
#include "Presentation/Widget/ChooseExTypeWidget.h"

#include <iostream>
#include <QVBoxLayout>
#include <QLineEdit>

#include"../include/View/Widget/ui_exchangewidget.h"
#include "../include/ExchangeDataParser/ExchangeDataTranslator.h"
#include "Presentation/Widget/ListWidget.h"

int WLENGTH = 360;
int WWIDTH = 720;

ChooseExTypeWidget::ChooseExTypeWidget(QWidget* parent)
    : QWidget(parent)
{
    list_ = new QList<QString>;
    for (auto val : dictionary)
    {
        list_->append(QString{val.second.c_str()});
    }

    auto* list_to = new ListWidget();
    auto* list_from = new ListWidget();
    list_to->addItem("");
    list_from->addItem("");
    list_to->addItems(*list_);
    list_from->addItems(*list_);

    connect(list_from,&QComboBox::currentTextChanged,this,&ChooseExTypeWidget::getExFromData);
    connect(list_to,&QComboBox::currentTextChanged,this,&ChooseExTypeWidget::getExToData);

    auto* layout = new QHBoxLayout(this);

    layout->addWidget(list_from);
    layout->addWidget(list_to);

    setLayout(layout);
}

ChooseExTypeWidget::~ChooseExTypeWidget()
{
    delete(list_);
}

void ChooseExTypeWidget::getExToData(const QString& text)
{
    emit changedExTo(text);
}

void ChooseExTypeWidget::getExFromData(const QString& text)
{
    emit changedExFrom(text);
}
