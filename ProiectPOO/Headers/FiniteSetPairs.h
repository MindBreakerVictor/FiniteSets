#ifndef FINITE_PAIRS_H
#define FINITE_PAIRS_H

#include "PCH.h"
#include "simple_linked_list.h"
#include "FiniteSet.h"
#include "Pair.h"

class FiniteSetPairs
{
	public:
		FiniteSetPairs() : size(0), list() { }
		FiniteSetPairs(const FiniteSetPairs& source) : list(source.list), size(source.size) { }
		FiniteSetPairs(const SimpleLinkedList<Pair>& _list) : list(_list), size(_list.getSize()) { }
		FiniteSetPairs(const FiniteSet<int>& A, const FiniteSet<int>& B);
		virtual ~FiniteSetPairs() { }

		uint getCardinal() const { return size; }

		bool isEmpty() const { return (size == 0); }
		bool hasPair(Pair pair) const { return list.hasValue(pair); }

		void pushFront(Pair pair);
		void pushBack(Pair pair);

		void popFront();
		void popBack();

		void assignCartesianProduct(const FiniteSet<int>& A, const FiniteSet<int>& B);

		virtual FiniteSetPairs getComplement(const FiniteSetPairs& finitePairs);

		Pair& operator[](const uint index) const { return list[index]; }

		friend std::ostream& operator<<(std::ostream& os, const FiniteSetPairs& finitePairs);
		friend std::ofstream& operator<<(std::ofstream& ofs, const FiniteSetPairs& finitePairs);
		friend std::istream& operator>>(std::istream& is, FiniteSetPairs& finitePairs);
		friend std::ifstream& operator>>(std::ifstream& ifs, FiniteSetPairs& finitePairs);

	protected:
		SimpleLinkedList<Pair> list;
		uint size;
};

#endif
