#pragma once

#include <QTextEdit>

class ChooseExTypeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseExTypeWidget(QWidget* parent = nullptr);

public slots:
    void currentTextToUpd(const QString& text);
    void currentTextFromUpd(const QString& text);
signals:
    void changedCurrentTextTo(const QString& text);
    void changedCurrentTextFrom(const QString& text);
};
