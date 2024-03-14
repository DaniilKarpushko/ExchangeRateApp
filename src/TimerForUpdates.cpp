#include "../include/TimerForUpdates.h"

#include <iostream>
#include <thread>


void TimerForUpdates::Start()
{
    while(true)
    {
        std::cout << "time_thread start upd" << '\n';
        controller_->updateExchangeDate();
        std::cout << "time_thread end upd" << '\n';
        std::this_thread::sleep_for(delay);
    }
}
