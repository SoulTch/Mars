#pragma once

#include <map>

enum class Tag {
    titanium,
    
    COUNT
};
const std::map<std::string, Tag> mTag = {
    {"titanium"s, Tag::titanium}
};





enum class Resources {
    megacredit,

    COUNT
};
const std::map<std::string, Resources> mResources = {
    {"megacredit"s, Resources::megacredit}
};





enum class Surface {
    sea,
    oxygen,

    COUNT
};
const std::map<std::string, Surface> mSurface = {
    {"sea"s, Surface::sea},
    {"oxygen"s, Surface::oxygen}
};





enum class Counter {
    science,
    microbe,

    COUNT
};
const std::map<std::string, Counter> mCounter = {
    {"science"s, Counter::science},
    {"microbe"s, Counter::microbe}
};




enum class Expension {
    original,
    venus,

    COUNT
};

enum class ProjectType {
    normal

    COUNT
};