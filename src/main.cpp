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
    auto* rq = new RequestController("5dbe82f3af424cd8b79eecf4aadbf69d",ExchangeDataParser{});
    TimerForUpdates tm{std::chrono::seconds{10},rq};
    std::thread tr(&TimerForUpdates::Start,&tm);
    // std::this_thread::sleep_for(std::chrono::seconds{15});
    auto data = rq->getExchangeData();
    while(data.status_code != 200)
    {
        data = rq->getExchangeData();
    }
    std::cout << "write data" << '\n';
    for(auto el : data.exchange)
       {
            std::cout << el.first << '\n';
       }
         std::cout << "end writing" << '\n';
    tr.join();
    // QApplication app(argc, argv);
    //
    // rq->updateExchangeDate();
    // auto* widget = new InputWidget(rq);
    //
    // widget->setWindowTitle("ExchangeApp");
    // widget->setWindowIcon(QIcon{"images/icon.jpg"});
    // widget->show();
    // return app.exec();
}
