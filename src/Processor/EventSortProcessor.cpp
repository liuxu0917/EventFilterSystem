//
// Created by liuxu on 2022/1/16.
//

#include "EventSortProcessor.h"

void EventSortProcessor::process(EventVec &eventVec) const {
    LOG_TRACE("::before,eventVec:" << eventVec);
    std::sort(eventVec.begin(), eventVec.end());
    LOG_TRACE("::after,eventVec:" << eventVec);
}