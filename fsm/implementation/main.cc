#include <iostream>
#include <memory>
#include "NumberCalculator.hh"

int main(void)
{
	std::unique_ptr<NumberCalculator> nc(new NumberCalculator);

	nc->accept(1);
	nc->accept(2);

	nc->changeState(NumberCalculator::StateId::active);
	nc->accept(3);

	return 0;
}
