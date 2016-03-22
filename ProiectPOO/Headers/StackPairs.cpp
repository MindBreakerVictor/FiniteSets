#include "StackPairs.h"

std::istream& operator>>(std::istream& is, PairsStack& pairsStack)
{
	uint size;
	is >> size;
	pairsStack.size = size;

	for (uint i = 0; i < size; i++)
	{
		Pair pair;
		is >> pair;
		pairsStack.list.pushFront(pair);
	}

	return is;
}

std::ifstream& operator>>(std::ifstream& ifs, PairsStack& pairsStack)
{
	uint size;
	ifs >> size;
	pairsStack.size = size;

	for (uint i = 0; i < size; i++)
	{
		Pair pair;
		ifs >> pair;
		pairsStack.list.pushFront(pair);
	}

	return ifs;
}

Pair PairsStack::top()
{
	if (isEmpty())
		return Pair();

	return list[0];
}
