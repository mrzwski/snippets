#pragma once

#include <cstdint>
#include <string>

class StateMachineEventReporterInterface
{
public:
    virtual ~StateMachineEventReporterInterface() {}

    virtual void postSwitchState(const std::string &name, std::string current, std::string next) {};
    virtual void postInvalidStateId(const std::string &name, std::string current, unsigned int state_id) {};
};
