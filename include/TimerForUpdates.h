#pragma once
#include <chrono>
#include <functional>

#include "Controller/RequestController.h"

class TimerForUpdates
{
    const std::chrono::seconds delay;
    RequestController* controller_;
public:
    explicit TimerForUpdates(const std::chrono::seconds& delay, RequestController* controller)
        : delay(delay), controller_(controller)
    {
    }

    void Start();
};
