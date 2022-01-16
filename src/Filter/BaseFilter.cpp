//
// Created by liuxu on 2022/1/16.
//

#include "BaseFilter.h"

const EventTypeSet &BaseFilter::getRegisteredEventTypeSet() const {
    return m_eventTypeSet;
}

const EventIdSet &BaseFilter::getRegisteredEventIdSet() const {
    return m_eventIdSet;
}

void BaseFilter::addProcessor(const std::list<std::shared_ptr<BaseProcessor>> &processorList) {
    m_processorList.insert(m_processorList.end(), processorList.begin(), processorList.end());
}

void BaseFilter::setNextFilter(std::unique_ptr<BaseFilter> filter) {
    m_nextFilter.reset(filter.release());
}

void BaseFilter::filter(EventVec &eventVec) const {
    for (const auto processor: m_processorList) {
        if(processor != nullptr) {
            processor->run(eventVec);
        }
    }
    if(m_nextFilter != nullptr) {
        m_nextFilter->filter(eventVec);
    }
}

