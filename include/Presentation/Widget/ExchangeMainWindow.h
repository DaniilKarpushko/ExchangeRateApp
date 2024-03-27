#pragma once
#include <QMainWindow>

#include "GraphicBuilderWidget.h"
#include "InputWidget.h"
#include "Controller/ApiController.h"


class ExchangeMainWindow : public QMainWindow
{
    Q_OBJECT

    ApiController* request_controller_;
    InputWidget* input_widget_;
    GraphicBuilderWidget* graphic_widget_;
    QPushButton* switch_button_;

public:
    explicit ExchangeMainWindow(ApiController* request_controller, QWidget* parent = nullptr);

public slots:
    void monthlyExchangeUpdated(const std::vector<std::pair<std::string, float>>& result);
    void changeWidget();
};
