#include "NumberCalculatorState.hh"
#include <iostream>

namespace NumberCalculatorStates
{

NumberCalculatorState::NumberCalculatorState(const char* newName, StateId newState)
        : BaseState(newName), myState(newState)
{
}

NumberCalculatorState::StateId NumberCalculatorState::changeState(const StateId &s)
{
	return myState;
}

NumberCalculatorState::StateId NumberCalculatorState::accept(int n)
{
	std::cout << "Number calculator: " << n << std::endl;
	return myState;
}
}
