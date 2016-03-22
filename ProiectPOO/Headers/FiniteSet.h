#ifndef FINITE_H
#define FINITE_H

#include "PCH.h"
#include "simple_linked_list.h"
#include "Pair.h"

template <class _Type>
class FiniteSet;

template <class _Type>
FiniteSet<_Type> operator+(const FiniteSet<_Type>& leftOperand, const FiniteSet<_Type>& rightOperand);

template <class _Type>
FiniteSet<_Type> operator-(const FiniteSet<_Type>& leftOperand, const FiniteSet<_Type>& rightOperand);

template <class _Type>
FiniteSet<_Type> operator*(const FiniteSet<_Type>& leftOperand, const FiniteSet<_Type>& rightOperand);

template <class _Type>
std::ostream& operator<<(std::ostream& os, const FiniteSet<_Type>& f);

template <class _Type>
std::ofstream& operator<<(std::ofstream& ofs, const FiniteSet<_Type>& f);

template <class _Type>
std::istream& operator>>(std::istream& is, FiniteSet<_Type>& f);

template <class _Type>
std::ifstream& operator>>(std::ifstream& ifs, FiniteSet<_Type>& f);

template <class _Type>
class FiniteSet
{
	public:
		FiniteSet() : list(), finite(true), size(0) { }
		FiniteSet(std::ifstream& input);
		FiniteSet(const FiniteSet& source) : list(source.list), finite(source.finite), size(source.size) { }
		FiniteSet(const SimpleLinkedList<_Type>& _list) : list(_list), finite(false), size(_list.getSize()) { }

		~FiniteSet();

		uint getCardinal() const { return size; }

		bool isEmpty() const { return (size == 0); }
		bool isFinite() const { return finite; }
		bool hasValue(_Type value) const { return list.hasValue(value); }

		void toFinite();

		void pushFront(_Type x);
		void pushBack(_Type x);

		void popFront();
		void popBack();

		_Type& operator[](const uint index) const { return list[index]; }

		friend FiniteSet operator+<_Type>(const FiniteSet& leftOperand, const FiniteSet& rightOperand);
		friend FiniteSet operator-<_Type>(const FiniteSet& leftOperand, const FiniteSet& rightOperand);
		friend FiniteSet operator*<_Type>(const FiniteSet& leftOperand, const FiniteSet& rightOperand);

		friend std::ostream& operator<< <_Type>(std::ostream& os, const FiniteSet& f);
		friend std::ofstream& operator<< <_Type>(std::ofstream& ofs, const FiniteSet& f);
		friend std::istream& operator>> <_Type>(std::istream& is, FiniteSet& f);
		friend std::ifstream& operator>> <_Type>(std::ifstream& ifs, FiniteSet& f);

	private:
		SimpleLinkedList<_Type> list;
		uint size;
		bool finite;
};

template <class _Type>
FiniteSet<_Type>::FiniteSet(std::ifstream& input) : finite(false)
{
	uint n;
	input >> n;

	for (uint i = 0; i < n; i++)
	{
		int x;
		input >> x;
		pushBack(x);
	}
}

template <class _Type>
FiniteSet<_Type>::~FiniteSet()
{
	finite = true;
	size = 0;
}

template <class _Type>
void FiniteSet<_Type>::pushFront(_Type x)
{
	list.pushFront(x);
	finite = false;
	size++;
}

template <class _Type>
void FiniteSet<_Type>::pushBack(_Type x)
{
	list.pushBack(x);
	finite = false;
	size++;
}

template <class _Type>
void FiniteSet<_Type>::popFront()
{
	list.popFront();
	size--;
}

template <class _Type>
void FiniteSet<_Type>::popBack()
{
	list.popBack();
	size--;
}

template <class _Type>
void FiniteSet<_Type>::toFinite()
{
	if (finite || isEmpty())
		return;

	SimpleLinkedList<_Type> temp = list;
	list.~SimpleLinkedList();

	for (uint i = 0; i < temp.getSize(); i++)
	{
		_Type value = temp[i];

		if (!list.hasValue(value))
			list.pushBack(value);
	}

	finite = true;
}

template <class _Type>
FiniteSet<_Type> operator+(const FiniteSet<_Type>& termOne, const FiniteSet<_Type>& termTwo)
{
	FiniteSet<_Type> sum = termOne;

	for (uint i = 0; i < termTwo.getCardinal(); i++)
		sum.pushBack(termTwo[i]);

	sum.toFinite();
	return sum;
}

template <class _Type>
FiniteSet<_Type> operator-(const FiniteSet<_Type>& termOne, const FiniteSet<_Type>& termTwo)
{
	FiniteSet<_Type> difference;

	for (uint i = 0; i < termOne.getCardinal(); i++)
	{
		int value = termOne[i];

		if (!difference.hasValue(value) && !termTwo.hasValue(value))
			difference.pushBack(value);
	}

	difference.finite = true;
	return difference;
}

template <class _Type>
FiniteSet<_Type> operator*(const FiniteSet<_Type>& termOne, const FiniteSet<_Type>& termTwo)
{
	FiniteSet<_Type> intersection;

	for (uint i = 0; i < termOne.getCardinal(); i++)
	{
		int value = termOne[i];

		if (!intersection.hasValue(value) && termTwo.hasValue(value))
			intersection.pushBack(value);
	}

	intersection.finite = true;
	return intersection;
}

template <class _Type>
std::ostream& operator<<(std::ostream& os, const FiniteSet<_Type>& f)
{
	os << f.list;
	return os;
}

template <class _Type>
std::ofstream& operator<<(std::ofstream& ofs, const FiniteSet<_Type>& f)
{
	ofs << f.list;
	return ofs;
}

template <class _Type>
std::istream& operator>>(std::istream& is, FiniteSet<_Type>& f)
{
	is >> f.list;
	f.finite = false;
	f.size = f.list.getSize();
	return is;
}

template <class _Type>
std::ifstream& operator>>(std::ifstream& ifs, FiniteSet<_Type>& f)
{
	ifs >> f.list;
	f.finite = false;
	f.size = f.list.getSize();
	return ifs;
}

#endif
