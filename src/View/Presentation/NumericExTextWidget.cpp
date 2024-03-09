#include "../include/Presentation/Widget/NumericExTextWidget.h"
#include <QKeyEvent>
#include <qlayout.h>

NumericExTextWidget::NumericExTextWidget(QWidget* parent)
    :QTextEdit(parent)
{
    setPlainText("Введите количество");
    connect(this,&QTextEdit::textChanged,this,&NumericExTextWidget::textChanged);
}

void NumericExTextWidget::focusInEvent(QFocusEvent* event)
{
    clear();
    QTextEdit::focusInEvent(event);
}

void NumericExTextWidget::keyPressEvent(QKeyEvent* event)
{
    if(event->key() >= Qt::Key_0 && event->key() <= Qt::Key_9
        || event->key() == Qt::Key_Period
        || event->key() == Qt::Key_Backspace)
    {
        QTextEdit::keyPressEvent(event);
    }
}

void NumericExTextWidget::textChanged()
{
    emit textChangedUpd(toPlainText());
}
