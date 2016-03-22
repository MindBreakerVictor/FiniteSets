#ifndef _PAIRS_STACK_H
#define _PAIRS_STACK_H

#include "FinitePairs.h"

class PairsStack : public FinitePairs
{
	public:
		PairsStack() : FinitePairs() { }
		PairsStack(const PairsStack& source) : FinitePairs(source) { }
		~PairsStack() { }

		void push(Pair pair) { pushFront(pair); }
		void pop() { popFront(); }
		Pair top();

		friend std::istream& operator>>(std::istream& is, PairsStack& pairsStack);
		friend std::ifstream& operator>>(std::ifstream& ifs, PairsStack& pairsStack);

	private:
		FinitePairs::hasPair;
		FinitePairs::assignCartesianProduct;
		FinitePairs::operator[];
		FinitePairs::popBack;
		FinitePairs::popFront;
		FinitePairs::pushBack;
		FinitePairs::pushFront;
};

#endif