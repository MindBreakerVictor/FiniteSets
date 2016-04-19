#include "PCH.h"
#include "FiniteSetPairs.h"
#include "FiniteSet.h"

FiniteSetPairs::FiniteSetPairs(FiniteSet<int> const& A, FiniteSet<int> const& B)
{
	for (uint32_t i = 0; i < A.getCardinal(); i++)
	{
		for (uint32_t j = 0; j < B.getCardinal(); j++)
		{
			Pair pair(A[i], B[j]);
			list.pushBack(pair);
		}
	}
}

void FiniteSetPairs::pushFront(Pair const& pair)
{
	list.pushFront(pair);
	size++;
}

void FiniteSetPairs::pushBack(Pair const& pair)
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

void FiniteSetPairs::assignCartesianProduct(FiniteSet<int> const& A, FiniteSet<int> const& B)
{
	list.~SimpleLinkedList();

	for (uint32_t i = 0; i < A.getCardinal(); i++)
	{
		for (uint32_t j = 0; j < B.getCardinal(); j++)
		{
			Pair pair(A[i], B[j]);
			pushBack(pair);
		}
	}
}

FiniteSetPairs FiniteSetPairs::getComplement(FiniteSetPairs const& finitePairs)
{
	FiniteSetPairs complement;

	for (uint32_t i = 0; i < size; i++)
	{
		Pair pair = (*this)[i];

		if (!complement.hasPair(pair) && !finitePairs.hasPair(pair))
			complement.pushBack(pair);
	}

	return complement;
}

std::ostream& operator<<(std::ostream& os, FiniteSetPairs const& finitePairs)
{
	for (uint32_t i = 0; i < finitePairs.size; i++)
		os << finitePairs[i] << " ";
	os << "\n";
	return os;
}

std::ofstream& operator<<(std::ofstream& ofs, FiniteSetPairs const& finitePairs)
{
	for (uint32_t i = 0; i < finitePairs.size; i++)
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

