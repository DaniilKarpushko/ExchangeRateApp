#pragma once
#include <QComboBox>

class ListWidget : public QComboBox
{
    Q_OBJECT
public:
    explicit ListWidget(QWidget* parent = nullptr) : QComboBox(parent) {};
};
