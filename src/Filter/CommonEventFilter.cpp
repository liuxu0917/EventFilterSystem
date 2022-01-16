//
// Created by liuxu on 2022/1/16.
//

#include "CommonEventFilter.h"
#include "../Processor/EventSortProcessor.h"

CommonEventFilter::CommonEventFilter() {
    addProcessor({std::make_shared<EventSortProcessor>()});
}
