//
// Created by liuxu on 2022/1/16.
//

#include "SensorEventProcessor.h"

void SensorEventProcessor::process(EventVec &eventVec) const {
    LOG_TRACE("::before,eventVec:" << eventVec);
    eventVec.erase(std::remove_if(eventVec.begin(), eventVec.end(), [](const Event &event) {
        return SensorEventIdSet.find(event.id) == SensorEventIdSet.end();
    }), eventVec.end());
    LOG_TRACE("::after,eventVec:" << eventVec);
}
