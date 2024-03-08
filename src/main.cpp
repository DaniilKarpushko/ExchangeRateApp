#include <iostream>
#include <QApplication>
#include <cpr/cpr.h>

#include "../include/Presentation/Widget/ChooseExTypeWidget.h"
#include "Presentation/Widget/InputWidget.h"
#include "Presentation/Widget/InsertExAmountWidget.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    auto* rq = new RequestController("5dbe82f3af424cd8b79eecf4aadbf69d",ExchangeDataParser{});
    auto* widget = new InputWidget(rq);

    widget->setWindowTitle("Пример с кнопкой и текстовым полем");
    widget->show();
    return app.exec();
}
