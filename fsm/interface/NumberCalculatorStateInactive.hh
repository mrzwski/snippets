#pragma once

#include "NumberCalculatorState.hh"

namespace NumberCalculatorStates
{

class Inactive : public NumberCalculatorState
{
public:
    Inactive();
    void enter() override;

    StateId changeState(const StateId &s) override;
    StateId accept(int n) override;
};

}
