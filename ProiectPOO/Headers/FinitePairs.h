#ifndef _FINITE_PAIRS_H
#define _FINITE_PAIRS_H

#include "PCH.h"
#include "simple_linked_list.h"
#include "Finite.h"
#include "Pair.h"

class FinitePairs
{
	public:
		FinitePairs() : size(0), list() { }
		FinitePairs(const FinitePairs& source) : list(source.list), size(source.size) { }
		FinitePairs(const SimpleLinkedList<Pair>& _list) : list(_list), size(_list.getSize()) { }
		FinitePairs(const Finite<int>& A, const Finite<int>& B);
		virtual ~FinitePairs() { }

		uint getCardinal() const { return size; }

		bool isEmpty() const { return (size == 0); }
		bool hasPair(Pair pair) { return list.hasValue(pair); }

		void pushFront(Pair pair);
		void pushBack(Pair pair);

		void popFront();
		void popBack();

		void assignCartesianProduct(const Finite<int>& A, const Finite<int>& B);

		Pair& operator[](const uint index) const { return list[index]; }

		friend std::ostream& operator<<(std::ostream& os, const FinitePairs& finitePairs);
		friend std::ofstream& operator<<(std::ofstream& ofs, const FinitePairs& finitePairs);
		friend std::istream& operator>>(std::istream& is, FinitePairs& finitePairs);
		friend std::ifstream& operator>>(std::ifstream& ifs, FinitePairs& finitePairs);

	protected:
		SimpleLinkedList<Pair> list;
		uint size;
};

#endif
