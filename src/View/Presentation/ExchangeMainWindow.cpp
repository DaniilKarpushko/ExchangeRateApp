#include "../include/Presentation/Widget/ExchangeMainWindow.h"

#include <QPushButton>
#include <QThread>

#include "Presentation/Widget/GraphicBuilderWidget.h"
#include "Presentation/Widget/InputWidget.h"

ExchangeMainWindow::ExchangeMainWindow(ApiController* request_controller, QWidget* parent)
    : QMainWindow(parent), request_controller_(request_controller)
{
    this->resize(720, 360);

    QThread* requset_thread = new QThread;
    request_controller_->moveToThread(requset_thread);
    requset_thread->start();

    switch_button_ = new QPushButton();
    switch_button_->setText("---Build monthly graphic---");

    input_widget_ = new InputWidget(request_controller_, this);

    this->setMenuWidget(switch_button_);
    this->setCentralWidget(input_widget_);
    this->centralWidget()->setFixedSize(720, 100);

    connect(switch_button_, &QPushButton::clicked, this, &ExchangeMainWindow::changeWidget);
    connect(request_controller_,&ApiController::monthlyCurrencyExchangeReady,this,&ExchangeMainWindow::monthlyExchangeUpdated);
}

void ExchangeMainWindow::monthlyExchangeUpdated(const std::vector<std::pair<std::string, float>>& result)
{
    graphic_widget_ = new GraphicBuilderWidget(result);
    setCentralWidget(graphic_widget_);
    switch_button_->setText("---Return to counter---");
}

void ExchangeMainWindow::changeWidget()
{
    if (centralWidget() == input_widget_)
    {
        QMetaObject::invokeMethod(request_controller_, "getMonthlyCurrencyExchange",Qt::QueuedConnection,
                                  Q_ARG(std::string,input_widget_->getCurrencyTo()),
                                  Q_ARG(std::string, input_widget_->getCurrencyFrom()));
    }
    else
    {
        input_widget_ = new InputWidget(request_controller_);
        setCentralWidget(input_widget_);
        centralWidget()->setFixedSize(720, 100);
        switch_button_->setText("---Build monthly graphic---");
    }
}
