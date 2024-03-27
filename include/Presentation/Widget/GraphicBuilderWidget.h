#pragma once
#include "ChooseExTypeWidget.h"
#include <QPushButton>

class GraphicBuilderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicBuilderWidget(std::vector<std::pair<std::string, float>> data, QWidget* parent = nullptr);
};
