#include "NumberCalculatorStateInactive.hh"
#include <iostream>

namespace NumberCalculatorStates
{

Inactive::Inactive()
    : NumberCalculatorState("Inactive", StateId::inactive)
{
}

void Inactive::enter()
{
	std::cout << this->getName() << " entered state inactive" << std::endl;
}

Inactive::StateId Inactive::changeState(const StateId &s)
{
	if (s != myState)
		return StateId(s);

    return myState;
}

Inactive::StateId Inactive::accept(int n)
{
	std::cout << "Number calculator inactive number: " << n << std::endl;
    return myState;
}

}
