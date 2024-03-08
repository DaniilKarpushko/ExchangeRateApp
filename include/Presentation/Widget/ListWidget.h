#pragma once
#include <QComboBox>

namespace ui
{
    class ListWidget;
}

class ListWidget : public QComboBox
{
public:
    explicit ListWidget(QWidget* parent = nullptr) : QComboBox(parent) {};
};
