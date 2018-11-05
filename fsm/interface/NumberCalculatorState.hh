#pragma once

#include "StateMachineInterface.h"

namespace NumberCalculatorStates
{

class NumberCalculatorState : public BaseState
{
public:
    enum class StateId : unsigned int
    {
        inactive,
        active
    };

    void enter() override {};
    void exit() override {};

    virtual NumberCalculatorState::StateId changeState(const StateId &s);
    virtual NumberCalculatorState::StateId accept(int n);

protected:
    NumberCalculatorState(const char* newName, const StateId newState);

    const StateId myState;
};

}
