#include <iostream>
#include <QApplication>
#include <cpr/cpr.h>

#include "TimerForUpdates.h"
#include "../include/Presentation/Widget/ChooseExTypeWidget.h"
#include "Presentation/Widget/InputWidget.h"
#include "Presentation/Widget/InsertExAmountWidget.h"
void func()
{
    std::cout << "Uwu" << '\n';
}


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    auto* request_controller = new RequestController("5dbe82f3af424cd8b79eecf4aadbf69d",ExchangeDataParser{});
    auto* timer = new TimerForUpdates(std::chrono::hours{1},request_controller);

    std::thread timer_thread(&TimerForUpdates::Start,timer);
    timer_thread.detach();

    auto* widget = new InputWidget(request_controller);

    widget->setWindowTitle("ExchangeApp");
    widget->setWindowIcon(QIcon{"images/icon.jpg"});
    widget->show();
    return app.exec();
}
