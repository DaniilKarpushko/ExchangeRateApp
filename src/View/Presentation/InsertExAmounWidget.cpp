#include <qlayout.h>

#include "../include/Presentation/Widget/InsertExAmountWidget.h"
#include <QTextEdit>

#include "Presentation/Widget/NumericExTextWidget.h"

InsertExAmountWidget::InsertExAmountWidget(QWidget* parent)
    : QWidget(parent)
{
    auto* text_editor_from = new NumericExTextWidget();
    auto* text_editor_to = new QTextEdit();
    text_editor_to->setReadOnly(true);

    auto* layout = new QHBoxLayout();
    layout->addWidget(text_editor_from);
    layout->addWidget(text_editor_to);
    setLayout(layout);
}
