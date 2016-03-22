#include "FinitePairs.h"
#include "Finite.h"

FinitePairs::FinitePairs(const Finite<int>& A, const Finite<int>& B)
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

void FinitePairs::pushFront(Pair pair)
{
	list.pushFront(pair);
	size++;
}

void FinitePairs::pushBack(Pair pair)
{
	list.pushBack(pair);
	size++;
}

void FinitePairs::popFront()
{
	list.popFront();
	size--;
}

void FinitePairs::popBack()
{
	list.popBack();
	size--;
}

void FinitePairs::assignCartesianProduct(const Finite<int>& A, const Finite<int>& B)
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

std::ostream& operator<<(std::ostream& os, const FinitePairs& finitePairs)
{
	for (uint i = 0; i < finitePairs.size; i++)
		os << finitePairs[i] << " ";
	os << "\n";
	return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const FinitePairs& finitePairs)
{
	for (uint i = 0; i < finitePairs.size; i++)
		ofs << finitePairs[i] << " ";
	ofs << "\n";
	return ofs;
}

std::istream& operator>>(std::istream& is, FinitePairs& finitePairs)
{
	is >> finitePairs.list;
	finitePairs.size = finitePairs.list.getSize();
	return is;
}

std::ifstream& operator>>(std::ifstream& ifs, FinitePairs& finitePairs)
{
	ifs >> finitePairs.list;
	finitePairs.size = finitePairs.list.getSize();
	return ifs;
}
