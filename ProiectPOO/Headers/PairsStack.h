#pragma once

#include "PCH.h"
#include "Pair.h"
#include "FiniteSetPairs.h"

class PairsStack : public FiniteSetPairs
{
	public:
		PairsStack() : FiniteSetPairs() { }
		PairsStack(PairsStack const& source) : FiniteSetPairs(source) { }

		void push(Pair const& pair) { pushFront(pair); }
		void pop() { popFront(); }

		Pair top() const;

		FiniteSetPairs getComplement(FiniteSetPairs const& finitePairs) const;

		friend std::istream& operator>>(std::istream& is, PairsStack& pairsStack);
		friend std::ifstream& operator>>(std::ifstream& ifs, PairsStack& pairsStack);

	private:
		FiniteSetPairs::hasPair;
		FiniteSetPairs::assignCartesianProduct;
		FiniteSetPairs::operator[];
		FiniteSetPairs::popBack;
		FiniteSetPairs::popFront;
		FiniteSetPairs::pushBack;
		FiniteSetPairs::pushFront;
};

