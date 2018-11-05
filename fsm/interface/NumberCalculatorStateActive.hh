#pragma once

#include "NumberCalculatorState.hh"

namespace NumberCalculatorStates
{

class Active : public NumberCalculatorState
{
public:
    Active();
    void enter() override;

    StateId changeState(const StateId &s) override;
    StateId accept(int n) override;
};

}
