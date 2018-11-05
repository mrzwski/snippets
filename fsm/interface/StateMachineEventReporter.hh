#pragma once

#define SS_PREFIX "%-20s|%-15s|%-15s|--|"
#include <stdio.h>
#include "StateMachineEventReporterInterface.hh"
#include "EventReporter.hh"

class StateMachineEventReporterImpl : public StateMachineEventReporterInterface, public EventReporter<StateMachineEventReporterImpl>
{
public:
    StateMachineEventReporterImpl() : stateMachineDebug(false)
    {}

    void postSwitchState(const std::string &name, std::string current, std::string next) override
    {
        if (stateMachineDebug) printf(SS_PREFIX " %s -> %s \n",
            name.c_str(), current.c_str(), "", current.c_str(), next.c_str());
    }

    void postInvalidStateId(const std::string &name, std::string current, unsigned int state_id) override
    {
        if (stateMachineDebug) printf(SS_PREFIX " State ID: %d\n",
            name.c_str(), current.c_str(), "Invalid_ID", state_id);
    }

    bool stateMachineDebug;

private:
    friend class EventReporter<StateMachineEventReporterImpl>;
};

typedef EventReporter<StateMachineEventReporterImpl> StateMachineEventReporter;
