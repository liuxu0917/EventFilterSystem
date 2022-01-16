//
// Created by liuxu on 2022/1/16.
//

#ifndef EVENTFILTERSYSTEM_COMMON_H
#define EVENTFILTERSYSTEM_COMMON_H

#ifdef WIN32
#include <windows.h>
#define sleep(x) Sleep(x*1000);
#else
#include <sys/time.h>
#include <unistd.h>
#endif
#include <vector>
#include <set>
#include <list>
#include <cstdint>
#include <map>
#include <memory>
#include <iostream>
#include <sstream>
#include <algorithm>

#define LOG_TRACE(message) std::cout<<__PRETTY_FUNCTION__<<":"<<message<<std::endl;

using EventId = uint64_t;

struct Event {
    EventId id{0};
    uint32_t timesStamp{0};

    bool operator<(const Event &other) {
        return timesStamp < other.timesStamp;
    }
};

using EventVec = std::vector<Event>;

inline std::ostream &operator<<(std::ostream &os, EventVec &eventVec) {
    std::stringstream stringstream;
    stringstream << "{";
    for (const auto &event: eventVec) {
        stringstream << "{id:" << event.id << ",time:" << event.timesStamp << "}, ";
    }
    stringstream.seekp(-2, std::ios::cur);
    stringstream << "}";
    return os << stringstream.str();
}

enum class EventType {
    SENSOR, MANUAL_CONTROL, AUTO_CONTROL, SYSTEM
};

using EventTypeSet = std::set<EventType>;

using EventIdSet = std::set<EventId>;

const EventIdSet SensorEventIdSet = {1, 2, 3};
const EventIdSet SystemEventIdSet = {7, 8, 9};

const std::map<EventType, EventIdSet> EventTypeToIdSetMap =
        {{EventType::SENSOR, SensorEventIdSet},
         {EventType::SYSTEM, SystemEventIdSet}};

#endif //EVENTFILTERSYSTEM_COMMON_H
