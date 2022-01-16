//
// Created by liuxu on 2022/1/16.
//

#include "BaseProcessor.h"
#include "EventSortProcessor.h"

void BaseProcessor::run(EventVec &eventVec) const {
    process(eventVec);
    if (m_hasPred) {
        m_pred(eventVec);
    }
}

void BaseProcessor::setPredicate(const std::function<void(EventVec &)> &pred) {
    m_pred = pred;
    m_hasPred = true;
}

