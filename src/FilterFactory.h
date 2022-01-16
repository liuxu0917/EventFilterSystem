//
// Created by liuxu on 2022/1/16.
//

#ifndef EVENTFILTERSYSTEM_FILTERFACTORY_H
#define EVENTFILTERSYSTEM_FILTERFACTORY_H

#include "Filter/BaseFilter.h"

class FilterFactory {
public:
    static std::unique_ptr<BaseFilter> getFilter(const std::string &filterName);
};


#endif //EVENTFILTERSYSTEM_FILTERFACTORY_H
