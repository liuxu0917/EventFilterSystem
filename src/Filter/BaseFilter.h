//
// Created by liuxu on 2022/1/16.
//

#ifndef EVENTFILTERSYSTEM_BASEFILTER_H
#define EVENTFILTERSYSTEM_BASEFILTER_H

#include "../Common.h"
#include "../Processor/BaseProcessor.h"

class BaseFilter {
public:
    virtual const EventTypeSet &getRegisteredEventTypeSet() const;
    virtual const EventIdSet &getRegisteredEventIdSet() const;
    virtual void setNextFilter(std::unique_ptr<BaseFilter> filter);
    virtual void addProcessor(const std::list<std::shared_ptr<BaseProcessor>> &processorList);
    virtual void filter(EventVec &eventVec) const;

private:
    EventTypeSet m_eventTypeSet;
    EventIdSet m_eventIdSet;
protected:
    std::unique_ptr<BaseFilter> m_nextFilter;
    std::list<std::shared_ptr<BaseProcessor>> m_processorList;
};

#endif //EVENTFILTERSYSTEM_BASEFILTER_H
