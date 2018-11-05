#pragma once

#include <map>
#include <string>
#include "StateMachineEventReporterInterface.hh"
#include "StateMachineEventReporter.hh"

#ifndef UTEST_FRIENDS
#define UTEST_FRIENDS
#endif

class BaseState
{
public:
    // This is default type for state ids. If you want, you can override it
    // in your state interface as enum class to get strongly typed state ids.
    using StateId = unsigned int;

    BaseState(const char* newName) : name(newName) { }

    virtual ~BaseState() { }

    virtual void enter() = 0;
    virtual void exit() = 0;

    const std::string& getName() const { return name; }

private:
    std::string name;
};

template<typename StateImp>
class StateMachine
{
UTEST_FRIENDS

    using StateIdType = typename StateImp::StateId;

protected:
    StateMachine(const char* newName) :
        currentState(0),
        name(newName),
        eventReporter(StateMachineEventReporter::get())
    { }

    ~StateMachine()
    { }

    // BaseState is used on purpose in order to force states to derive from BaseState class.
    void addState(BaseState& newState, const StateIdType stateId)
    {
        states[stateId] = dynamic_cast<StateImp*>(&newState);
    }

    void enterInitState(const StateIdType initStateId)
    {
        verifyStateId(initStateId);
        currentState = states[initStateId];
        currentState->enter();
    }

    void transition(const StateIdType newStateId)
    {
        verifyStateId(newStateId);
        StateImp* newState = states[newStateId];

        if(newState != currentState)
        {
            switchState(newState);
        }
    }

    StateImp* currentState;

private:
    void switchState(StateImp* newState)
    {
        eventReporter.postSwitchState(name, currentState->getName(), newState->getName());
        currentState->exit();
        currentState = newState;
        currentState->enter();
    }

    void verifyStateId(const StateIdType stateId)
    {
        if(states.find(stateId) == states.end())
        {
            eventReporter.postInvalidStateId(name, currentState->getName(), static_cast<unsigned int>(stateId));
        }
    }

    std::map<StateIdType, StateImp*> states;
    std::string name;
    StateMachineEventReporterInterface& eventReporter;
};
