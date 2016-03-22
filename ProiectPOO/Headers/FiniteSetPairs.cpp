#include "FiniteSetPairs.h"
#include "FiniteSet.h"

FiniteSetPairs::FiniteSetPairs(const FiniteSet<int>& A, const FiniteSet<int>& B)
{
	for (uint i = 0; i < A.getCardinal(); i++)
	{
		for (uint j = 0; j < B.getCardinal(); j++)
		{
			Pair pair(A[i], B[j]);
			list.pushBack(pair);
		}
	}
}

void FiniteSetPairs::pushFront(Pair pair)
{
	list.pushFront(pair);
	size++;
}

void FiniteSetPairs::pushBack(Pair pair)
{
	list.pushBack(pair);
	size++;
}

void FiniteSetPairs::popFront()
{
	list.popFront();
	size--;
}

void FiniteSetPairs::popBack()
{
	list.popBack();
	size--;
}

void FiniteSetPairs::assignCartesianProduct(const FiniteSet<int>& A, const FiniteSet<int>& B)
{
	list.~SimpleLinkedList();

	for (uint i = 0; i < A.getCardinal(); i++)
	{
		for (uint j = 0; j < B.getCardinal(); j++)
		{
			Pair pair(A[i], B[j]);
			pushBack(pair);
		}
	}
}

FiniteSetPairs FiniteSetPairs::getComplement(const FiniteSetPairs& finitePairs)
{
	FiniteSetPairs complement;

	for (uint i = 0; i < size; i++)
	{
		Pair pair = (*this)[i];

		if (!complement.hasPair(pair) && !finitePairs.hasPair(pair))
			complement.pushBack(pair);
	}

	return complement;
}

std::ostream& operator<<(std::ostream& os, const FiniteSetPairs& finitePairs)
{
	for (uint i = 0; i < finitePairs.size; i++)
		os << finitePairs[i] << " ";
	os << "\n";
	return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const FiniteSetPairs& finitePairs)
{
	for (uint i = 0; i < finitePairs.size; i++)
		ofs << finitePairs[i] << " ";
	ofs << "\n";
	return ofs;
}

std::istream& operator>>(std::istream& is, FiniteSetPairs& finitePairs)
{
	is >> finitePairs.list;
	finitePairs.size = finitePairs.list.getSize();
	return is;
}

std::ifstream& operator>>(std::ifstream& ifs, FiniteSetPairs& finitePairs)
{
	ifs >> finitePairs.list;
	finitePairs.size = finitePairs.list.getSize();
	return ifs;
}
