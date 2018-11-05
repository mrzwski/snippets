#include "NumberCalculatorStateActive.hh"
#include <iostream>

namespace NumberCalculatorStates
{

Active::Active():
    NumberCalculatorState("Active", StateId::active)
{
}

void Active::enter()
{
	std::cout << this->getName() << " entered state active" << std::endl;
}

Active::StateId Active::changeState(const StateId &s)
{
	if (s != myState)
		return StateId(s);

    return myState;
}

Active::StateId Active::accept(int n)
{
	std::cout << "Number calculator active number: " << n << std::endl;
    return myState;
}

}
