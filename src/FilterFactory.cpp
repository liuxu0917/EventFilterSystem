//
// Created by liuxu on 2022/1/16.
//

#include "FilterFactory.h"
#include "Filter/SensorEventFilter.h"
#include "Filter/CommonEventFilter.h"

std::unique_ptr<BaseFilter> FilterFactory::getFilter(const std::string &filterName)
{
    if(filterName == "SensorEventFilter") {
        return std::make_unique<SensorEventFilter>();
    } else if(filterName == "CommonEventFilter") {
        return std::make_unique<CommonEventFilter>();
    }
    return nullptr;
}