//
// Created by liuxu on 2022/1/16.
//

#ifndef EVENTFILTERSYSTEM_SENSOREVENTPROCESSOR_H
#define EVENTFILTERSYSTEM_SENSOREVENTPROCESSOR_H


#include "BaseProcessor.h"

class SensorEventProcessor : public BaseProcessor {
private:
    virtual void process(EventVec &eventVec) const override;
};


#endif //EVENTFILTERSYSTEM_SENSOREVENTPROCESSOR_H
