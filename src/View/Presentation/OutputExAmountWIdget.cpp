#include "Presentation/Widget/OutputExAmountWidget.h"


OutputExAmountWidget::OutputExAmountWidget(QWidget* parent)
    : QTextEdit(parent)
{
    setReadOnly(true);
}

void OutputExAmountWidget::updText(const QString& text)
{
    setText(text);
}
