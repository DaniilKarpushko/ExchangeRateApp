#pragma once
#include <QTextEdit>

class OutputExAmountWidget : public QTextEdit
{
    Q_OBJECT

public:
    explicit OutputExAmountWidget(QWidget* parent = nullptr);

public slots:
    void updText(const QString& text);
};
