#pragma once
#include <QTextEdit>


class NumericExTextWidget : public QTextEdit
{
    Q_OBJECT

public:
    explicit NumericExTextWidget(QWidget* parent = nullptr);
signals:
    void textChangedUpd(const QString& text);

protected:
    void focusInEvent(QFocusEvent* event) override;

    void keyPressEvent(QKeyEvent* event) override;
private slots:
    void textChanged();
};
