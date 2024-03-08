#pragma once
#include <QTextEdit>

class NumericExTextWidget : public QTextEdit
{
public:
    explicit NumericExTextWidget(QWidget* parent = nullptr);
protected:
    void focusInEvent(QFocusEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
};