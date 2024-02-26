//
// Created by antikill on 26.02.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ExchangeWidget.h" resolved
#include "../include/Presentation/Widget/ExchangeWidget.h"

#include <sys/stat.h>

#include"../include/View/Widget/ui_exchangewidget.h"
#include "../include/ExchangeDataParser/ExchangeDataTranslator.h"

int WLENGTH = 360;
int WWIDTH = 720;

ExchangeWidget::ExchangeWidget(RequestController* request_controller, QWidget* parent)
    : QWidget(parent), ui(new Ui::ExchangeWidget), _lenght(WLENGTH), _width(WWIDTH),
        request_controller_(request_controller)
{
    setObjectName("Exchange Home App");
    setFixedSize(_width,_lenght);

    auto *button = new QPushButton("Нажми меня", this);
    text_edit_ = new QTextEdit(this);
    text_edit_ ->setReadOnly(true); // Установка только для чтения

    // Создание вертикального макета для удобного размещения элементов
    auto *layout = new QVBoxLayout(this);
    layout->addWidget(button);
    layout->addWidget(text_edit_);

    // Подключение сигнала нажатия кнопки к слоту для вывода текста
    connect(button, &QPushButton::clicked, this, &ExchangeWidget::GetExchangeData);

    // Установка макета для виджета
    setLayout(layout);
}

ExchangeWidget::~ExchangeWidget()
{
    delete ui;
}

void ExchangeWidget::GetExchangeData()
{
    auto eData = request_controller_->GetExchangeData();
    auto text = ConfigureText(eData);
    text_edit_->clear();
    text_edit_->append(text);
}

QString ExchangeWidget::ConfigureText(const ExchangeData& data)
{
    QString return_result;
    if(data.status_code == 200)
    {
        return_result += "status code: 200\n";
        return_result += "base: " + dictionary[data.base] + "\n";
        for(const auto& el : data.exchange)
        {
            return_result += dictionary[el.first] + " : " + std::to_string(el.second) + '\n';
        }

        return return_result;
    }
    return_result += "status code: " + std::to_string(data.status_code) + '\n';
    return return_result;
}
