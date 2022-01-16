//
// Created by liuxu on 2022/1/16.
//

#include <thread>
#include <iostream>
#include "EventFilterSystem.h"


EventFilterSystem::EventFilterSystem() {

}

void EventFilterSystem::setFilter(std::unique_ptr<BaseFilter> filter) {
    LOG_TRACE("setFilter");
    m_filter.reset(filter.release());
}

void EventFilterSystem::setNextFilterSystem(std::shared_ptr<EventFilterSystem> filterSystem) {
    m_nextFilterSystem = filterSystem;
}

void EventFilterSystem::start() {
    std::thread processThread(&EventFilterSystem::process, this);
    processThread.detach();
}

void EventFilterSystem::injectEvents(const EventVec &eventVec) {
    LOG_TRACE("injectEvents");
    std::unique_lock<std::mutex> lock(m_mutex);
    m_bufferEventVec.insert(m_bufferEventVec.end(), eventVec.begin(), eventVec.end());
    data_cond.notify_one();
}

void EventFilterSystem::process() {
    LOG_TRACE("process start");
    while (true) {
        std::unique_lock<std::mutex> lock(m_mutex);
        data_cond.wait(lock, [&bufferEventVec = m_bufferEventVec]() { return !bufferEventVec.empty(); });
        EventVec eventVec;
        eventVec.swap(m_bufferEventVec);
        lock.unlock();
        processEvents(eventVec);
    }
}

void EventFilterSystem::processEvents(EventVec &eventVec) {
    LOG_TRACE(m_systemName << "::before,eventVec:" << eventVec);
    sleep(2);
    if (m_filter != nullptr) {
        m_filter->filter(eventVec);
    }
    LOG_TRACE(m_systemName << "::after,eventVec:" << eventVec);
    auto filterSystemPtr = m_nextFilterSystem.lock();
    if (filterSystemPtr != nullptr) {
        filterSystemPtr->injectEvents(eventVec);
    }
}

std::map<EventId, EventType> EventFilterSystem::getEventIdToEventTypeMap() {
    std::map<EventId, EventType> eventIdToEventTypeMap;
    for (const auto &pair: EventTypeToIdSetMap) {
        for (const auto &eventId: pair.second) {
            eventIdToEventTypeMap[eventId] = pair.first;
        }
    }
    return eventIdToEventTypeMap;
}

void EventFilterSystem::setSystemName(const std::string &name) {
    m_systemName = name;
}


