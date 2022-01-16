//
// Created by liuxu on 2022/1/16.
//

#include "SensorEventFilter.h"
#include "../Processor/SensorEventProcessor.h"

SensorEventFilter::SensorEventFilter() {
    auto processor = std::make_shared<SensorEventProcessor>();
    auto pred = [](EventVec &eventVec) {
        for (auto &event: eventVec) {
            event.id += 1;
        }
    };
    processor->setPredicate(pred);
    addProcessor({processor});
}
