#include <QApplication>
#include <Windows.h>

#include "Presentation/Widget/ExchangeMainWindow.h"
#include <nlohmann/json.hpp>


//api G5RBBUD3MDVB2GQ7
// Z5NM736LDKMFV556
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    auto* request_service = new RequsetService("G5RBBUD3MDVB2GQ7");
    auto* controller = new ApiController(new CurrentExchangeService(request_service));
    auto window = new ExchangeMainWindow(controller);

    window->setWindowTitle("ExchangeApp");
    window->show();

    return app.exec();
}
