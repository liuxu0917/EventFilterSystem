//
// Created by liuxu on 2022/1/16.
//

#ifndef EVENTFILTERSYSTEM_BASEPROCESSOR_H
#define EVENTFILTERSYSTEM_BASEPROCESSOR_H

#include <functional>
#include "../Common.h"


class BaseProcessor {
public:
    virtual void run(EventVec &eventVec) const final;
    virtual void setPredicate(const std::function<void(EventVec &)> &pred);

private:
    virtual void process(EventVec &eventVec) const = 0;
    std::function<void(EventVec &)> m_pred;
    bool m_hasPred {false};
};

#endif //EVENTFILTERSYSTEM_BASEPROCESSOR_H
