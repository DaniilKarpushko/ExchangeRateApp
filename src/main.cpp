#include <iostream>
#include <QApplication>
#include <cpr/cpr.h>

#include "../include/Presentation/Widget/ExchangeWidget.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    auto* rq = new RequestController("5dbe82f3af424cd8b79eecf4aadbf69d",ExchangeDataParser{});
    auto* widget = new ExchangeWidget(rq);

    widget->setWindowTitle("Пример с кнопкой и текстовым полем");
    widget->show();
    return app.exec();
}
