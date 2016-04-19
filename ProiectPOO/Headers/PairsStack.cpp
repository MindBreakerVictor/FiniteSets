#include "PCH.h"
#include "PairsStack.h"

std::istream& operator>>(std::istream& is, PairsStack& pairsStack)
{
	uint32_t size;
	is >> size;
	pairsStack.size = size;

	for (uint32_t i = 0; i < size; i++)
	{
		Pair pair;
		is >> pair;
		pairsStack.list.pushFront(pair);
	}

	return is;
}

std::ifstream& operator>>(std::ifstream& ifs, PairsStack& pairsStack)
{
	uint32_t size;
	ifs >> size;
	pairsStack.size = size;

	for (uint32_t i = 0; i < size; i++)
	{
		Pair pair;
		ifs >> pair;
		pairsStack.list.pushFront(pair);
	}

	return ifs;
}

Pair PairsStack::top() const
{
	if (isEmpty())
		return Pair();

	return list[0];
}

FiniteSetPairs PairsStack::getComplement(FiniteSetPairs const& finitePairs) const
{
	PairsStack stack(*this);
	FiniteSetPairs complement;

	while (!stack.isEmpty())
	{
		Pair pair = stack.top();

		if (!complement.hasPair(pair) && !finitePairs.hasPair(pair))
			complement.pushBack(pair);

		stack.pop();
	}

	return complement;
}

