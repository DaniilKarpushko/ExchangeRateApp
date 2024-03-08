#include "../include/Presentation/Widget/ChooseExTypeWidget.h"

#include <QVBoxLayout>
#include <QLineEdit>

#include"../include/View/Widget/ui_exchangewidget.h"
#include "../include/ExchangeDataParser/ExchangeDataTranslator.h"
#include "Presentation/Widget/ListWidget.h"
#include "Presentation/Widget/ListWidget.h"

int WLENGTH = 360;
int WWIDTH = 720;

ChooseExTypeWidget::ChooseExTypeWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::ExchangeWidget)
{
    for (auto val : dictionary)
    {
        list_.append(QString{val.second.c_str()});
    }

    auto* list_to = new ListWidget();
    auto* list_from = new ListWidget();
    list_to->addItems(list_);
    list_from->addItems(list_);

    auto* layout = new QHBoxLayout(this);

    layout->addWidget(list_to);
    layout->addWidget(list_from);

    setLayout(layout);
}

ChooseExTypeWidget::~ChooseExTypeWidget()
{
    delete ui;
}
