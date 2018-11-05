#include "NumberCalculator.hh"

using NumberCalculatorStates::NumberCalculatorState;

NumberCalculator::NumberCalculator():
    StateMachine<NumberCalculatorState>("NUMBER_CALCULATOR_FSM"),
    stateInactive(),
    stateActive()
{
    addState(stateInactive, StateId::inactive);
    addState(stateActive, StateId::active);

    enterInitState(StateId::inactive);
}

NumberCalculator::~NumberCalculator() = default;

void NumberCalculator::changeState(const StateId &s)
{
	transition(currentState->changeState(s));
}

void NumberCalculator::accept(int n)
{
	transition(currentState->accept(n));
}
