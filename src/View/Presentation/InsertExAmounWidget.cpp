#include <qlayout.h>

#include "../include/Presentation/Widget/InsertExAmountWidget.h"
#include <QTextEdit>

#include "Presentation/Widget/NumericExTextWidget.h"
#include "Presentation/Widget/OutputExAmountWidget.h"

InsertExAmountWidget::InsertExAmountWidget(QWidget* parent)
    : QWidget(parent)
{
    auto* text_editor_from = new NumericExTextWidget();
    auto* text_editor_to = new OutputExAmountWidget();
    text_editor_to->setReadOnly(true);

    connect(text_editor_from, &NumericExTextWidget::textChangedUpd, this, &InsertExAmountWidget::setText);
    connect(this, &InsertExAmountWidget::sendCountedText, text_editor_to, &OutputExAmountWidget::setText);

    auto* layout = new QHBoxLayout();
    layout->addWidget(text_editor_from);
    layout->addWidget(text_editor_to);
    setLayout(layout);
}

void InsertExAmountWidget::setText(const QString& text)
{
    emit changedCurrentText(text);
}

void InsertExAmountWidget::getCountedText(const QString& text)
{
    emit sendCountedText(text);
}
