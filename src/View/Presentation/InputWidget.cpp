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
    auto* layout = new QVBoxLayout();

    layout->addWidget(choose_widget);
    layout->addWidget(insert_widget);

    setLayout(layout);
}