#pragma once

#include "PCH.h"
#include "simple_linked_list.h"
#include "Pair.h"

template <class _Type>
class FiniteSet;

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
		FiniteSet(FiniteSet const& source) : list(source.list), finite(source.finite), size(source.size) { }
		FiniteSet(SimpleLinkedList<_Type> const& _list) : list(_list), finite(false), size(_list.getSize()) { }

		~FiniteSet();

		uint32_t getCardinal() const { return size; }

		bool isEmpty() const { return (size == 0); }
		bool isFinite() const { return finite; }
		bool hasValue(_Type const& value) const { return list.hasValue(value); }

		void toFinite();

		void pushFront(_Type const& x);
		void pushBack(_Type const& x);

		void popFront();
		void popBack();

		_Type& operator[](uint32_t const& index) const { return list[index]; }

		FiniteSet operator+(FiniteSet const& set);
		FiniteSet operator-(FiniteSet const& set);
		FiniteSet operator*(FiniteSet const& set);

		friend std::ostream& operator<< <_Type>(std::ostream& os, FiniteSet const& f);
		friend std::ofstream& operator<< <_Type>(std::ofstream& ofs, FiniteSet const& f);
		friend std::istream& operator>> <_Type>(std::istream& is, FiniteSet& f);
		friend std::ifstream& operator>> <_Type>(std::ifstream& ifs, FiniteSet& f);

	private:
		SimpleLinkedList<_Type> list;
		uint32_t size;
		bool finite;
};

template <class _Type>
FiniteSet<_Type>::FiniteSet(std::ifstream& input) : finite(false)
{
	uint32_t n;
	input >> n;

	for (uint32_t i = 0; i < n; i++)
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
void FiniteSet<_Type>::pushFront(_Type const& x)
{
	list.pushFront(x);
	finite = false;
	size++;
}

template <class _Type>
void FiniteSet<_Type>::pushBack(_Type const& x)
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

	for (uint32_t i = 0; i < temp.getSize(); i++)
	{
		_Type value = temp[i];

		if (!list.hasValue(value))
			list.pushBack(value);
	}

	finite = true;
}

template <class _Type>
FiniteSet<_Type> FiniteSet<_Type>::operator+(FiniteSet<_Type> const& set)
{
	FiniteSet<_Type> sum = *this;

	for (uint32_t i = 0; i < termTwo.getCardinal(); i++)
		sum.pushBack(termTwo[i]);

	sum.toFinite();
	return sum;
}

template <class _Type>
FiniteSet<_Type> FiniteSet<_Type>::operator-(FiniteSet<_Type> const& set)
{
	FiniteSet<_Type> difference;

	for (uint32_t i = 0; i < getCardinal(); i++)
	{
		_Type value = this->operator[](i);

		if (!difference.hasValue(value) && !set.hasValue(value))
			difference.pushBack(value);
	}

	difference.finite = true;
	return difference;
}

template <class _Type>
FiniteSet<_Type> FiniteSet<_Type>::operator*(FiniteSet<_Type> const& set)
{
	FiniteSet<_Type> intersection;

	for (uint32_t i = 0; i < getCardinal(); i++)
	{
		_Type value = this->operator[][i];

		if (!intersection.hasValue(value) && set.hasValue(value))
			intersection.pushBack(value);
	}

	intersection.finite = true;
	return intersection;
}

template <class _Type>
std::ostream& operator<<(std::ostream& os, FiniteSet<_Type> const& f)
{
	os << f.list;
	return os;
}

template <class _Type>
std::ofstream& operator<<(std::ofstream& ofs, FiniteSet<_Type> const& f)
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

