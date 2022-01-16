//
// Created by liuxu on 2022/1/16.
//

#ifndef EVENTFILTERSYSTEM_EVENTFILTERSYSTEM_H
#define EVENTFILTERSYSTEM_EVENTFILTERSYSTEM_H

#include <list>
#include <map>
#include <mutex>
#include <condition_variable>
#include "Common.h"
#include "Filter/BaseFilter.h"

class EventFilterSystem {
public:
    EventFilterSystem();
    void setFilter(std::unique_ptr<BaseFilter> filter);
    void setNextFilterSystem(std::shared_ptr<EventFilterSystem> filterSystem);
    void start();

    void injectEvents(const EventVec &eventVec);

    void setSystemName(const std::string &name);
private:
    void process();
    void processEvents(EventVec &eventVec);
private:
    static std::map<EventId, EventType> getEventIdToEventTypeMap();
    std::mutex m_mutex;
    EventVec m_bufferEventVec;
    std::condition_variable data_cond;
    std::unique_ptr<BaseFilter> m_filter;
    std::weak_ptr<EventFilterSystem> m_nextFilterSystem;
    std::string m_systemName;


};


#endif //EVENTFILTERSYSTEM_EVENTFILTERSYSTEM_H
