#pragma once

#include "PCH.h"
#include "simple_linked_list.h"
#include "FiniteSet.h"
#include "Pair.h"

class FiniteSetPairs
{
	public:
		FiniteSetPairs() : size(0), list() { }
		FiniteSetPairs(FiniteSetPairs const& source) : list(source.list), size(source.size) { }
		FiniteSetPairs(SimpleLinkedList<Pair> const& _list) : list(_list), size(_list.getSize()) { }
		FiniteSetPairs(FiniteSet<int> const& A, FiniteSet<int> const& B);
		virtual ~FiniteSetPairs() { }

		uint32_t getCardinal() const { return size; }

		bool isEmpty() const { return (size == 0); }
		bool hasPair(Pair const& pair) const { return list.hasValue(pair); }

		void pushFront(Pair const& pair);
		void pushBack(Pair const& pair);

		void popFront();
		void popBack();

		void assignCartesianProduct(FiniteSet<int> const& A, FiniteSet<int> const& B);

		virtual FiniteSetPairs getComplement(FiniteSetPairs const& finitePairs);

		Pair& operator[](uint32_t const& index) const { return list[index]; }

		friend std::ostream& operator<<(std::ostream& os, FiniteSetPairs const& finitePairs);
		friend std::ofstream& operator<<(std::ofstream& ofs, FiniteSetPairs const& finitePairs);
		friend std::istream& operator>>(std::istream& is, FiniteSetPairs& finitePairs);
		friend std::ifstream& operator>>(std::ifstream& ifs, FiniteSetPairs& finitePairs);

	protected:
		SimpleLinkedList<Pair> list;
		uint32_t size;
};

