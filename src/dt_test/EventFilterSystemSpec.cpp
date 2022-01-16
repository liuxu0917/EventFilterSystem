//
// Created by liuxu on 2022/1/16.
//

#include <thread>
#include "gtest/gtest.h"
#include "EventFilterSystem.h"
#include "Filter/CommonEventFilter.h"
#include "FilterFactory.h"

TEST(EventFilterSystemSpec, demo) {
    EventFilterSystem firstSystem;
    firstSystem.setSystemName("SYS_ONE");
    auto sensorFilter = FilterFactory::getFilter("SensorEventFilter");
    sensorFilter->setNextFilter(std::make_unique<CommonEventFilter>());
    firstSystem.setFilter(std::move(sensorFilter));
    firstSystem.start();

    auto secondSystem = std::make_shared<EventFilterSystem>();
    secondSystem->setSystemName("SYS_TWO");
    firstSystem.setNextFilterSystem(secondSystem);
    secondSystem->start();
    std::thread t([&firstSystem]() {
        while (true) {
            EventVec eventVec = {{2, 2},
                                 {1, 1},
                                 {4, 1}};
            firstSystem.injectEvents(eventVec);
            sleep(1);
        }
    });
    t.join();

}