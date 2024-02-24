#include <iostream>
#include <cpr/cpr.h>

#include "Controller/RequestController.h"


int main(int argc, char* argv[])
{
    // QApplication a(argc, argv);
    // QPushButton button("Hello world!", nullptr);
    // button.resize(200, 100);
    // button.show();
    // return QApplication::exec();

    RequestController rq("5dbe82f3af424cd8b79eecf4aadbf69d",ExchangeDataParser{});
    rq.Get();
}
