#pragma once

#include "NumberCalculatorInterface.hh"
#include "NumberCalculatorStateInactive.hh"
#include "NumberCalculatorStateActive.hh"

class NumberCalculator : public NumberCalculatorInterface,
                         public StateMachine<NumberCalculatorStates::NumberCalculatorState>
{
public:
	NumberCalculator();
    ~NumberCalculator() override;

    using StateId = NumberCalculatorStates::NumberCalculatorState::StateId;
    void changeState(const StateId &s);
    void accept(int n);

private:
    NumberCalculatorStates::Inactive stateInactive;
    NumberCalculatorStates::Active stateActive;
};
