//
// Created by liuxu on 2022/1/16.
//

#ifndef EVENTFILTERSYSTEM_EVENTSORTPROCESSOR_H
#define EVENTFILTERSYSTEM_EVENTSORTPROCESSOR_H


#include "BaseProcessor.h"

class EventSortProcessor : public BaseProcessor {
private:
    virtual void process(EventVec &eventVec) const override;
};


#endif //EVENTFILTERSYSTEM_EVENTSORTPROCESSOR_H
