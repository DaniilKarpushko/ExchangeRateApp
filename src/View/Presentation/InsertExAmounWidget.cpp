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

    connect(text_editor_from,&NumericExTextWidget::textChangedUpd,this,&InsertExAmountWidget::applyNewText);
    connect(this,&InsertExAmountWidget::updateNewText,text_editor_to,&OutputExAmountWidget::updText);

    auto* layout = new QHBoxLayout();
    layout->addWidget(text_editor_from);
    layout->addWidget(text_editor_to);
    setLayout(layout);
}

void InsertExAmountWidget::applyNewText(const QString& text)
{
    emit updateNewText(text);
}

void InsertExAmountWidget::updText(const QString& text)
{
}
