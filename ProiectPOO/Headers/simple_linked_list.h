#pragma once

#include "PCH.h"

template <class _Type> 
class SimpleLinkedList
{
	public:
		SimpleLinkedList() : head(nullptr), tail(nullptr), size(0) { }

		SimpleLinkedList(uint32_t const& n) : size(n)
		{
			for (uint32_t i = 0; i < size; i++)
			{
				_Type value;
				std::cin >> value;
				if (!hasValue(value))
					pushBack(value);
			}
		}

		SimpleLinkedList(uint32_t const& n, std::ifstream& in) : size(n)
		{
			for (uint32_t i = 0; i < size; i++)
			{
				_Type value;
				in >> value;
				if (!hasValue(value))
					pushBack(value);
			}
		}

		SimpleLinkedList(SimpleLinkedList<_Type> const& source) : size(0)
		{
			Node *temp = source.head;
			for (uint32_t i = 0; i < source.getSize(); i++)
			{
				pushBack(temp->value);
				temp = temp->next;
			}
		}

		~SimpleLinkedList()
		{
			size = 0;
			tail = nullptr;

			while (head)
			{
				Node *del = head;
				head = head->next;
				delete del;
			}
		}

		void pushFront(_Type const& value);
		void pushBack(_Type const& value);

		void popValue(_Type const& value);
		void popFront() { popValue(head->value); }
		void popBack() { popValue(tail->value); }

		bool isEmpty() const { return !size; }
		bool hasValue(_Type const& value) const;

		uint32_t getSize() const { return size; }

		_Type& operator[](uint32_t const& index) const;

	private:
		struct Node
		{
			_Type value;
			Node *next;
		};

		Node *head, *tail;
		uint32_t size;
};

template <class _Type>
void SimpleLinkedList<_Type>::pushFront(_Type const& value)
{
	typename SimpleLinkedList<_Type>::Node* elem = new Node;
	elem->value = value;

	elem->next = head;

	head = elem;
	size++;
}

template <class _Type>
void SimpleLinkedList<_Type>::pushBack(_Type const& value)
{
	typename SimpleLinkedList<_Type>::Node* elem = new Node;
	elem->value = value;
	elem->next = nullptr;

	if (isEmpty())
	{
		head = elem;
		tail = elem;
	}
	else
	{
		tail->next = elem;
		tail = elem;
	}

	size++;
}

template <class _Type>
void SimpleLinkedList<_Type>::popValue(_Type const& value)
{
	if (isEmpty())
		return;

	if (head->value == value)
	{
		if (head == tail)
		{
			delete head;
			size = 0;
			head = tail = nullptr;
		}
		else
		{
			typename SimpleLinkedList<_Type>::Node* temp = head;
			head = head->next;
			delete temp;
		}
		return;
	}

	typename SimpleLinkedList<_Type>::Node* temp = head;
	while (temp->next && temp->next->value != value)
		temp = temp->next;

	if (temp->next)
	{
		Node* del = temp->next;
		temp->next = temp->next->next;
		delete del;
		size--;
	}
}

template <class _Type>
bool SimpleLinkedList<_Type>::hasValue(_Type const& value) const
{
	if (isEmpty())
		return false;

	typename SimpleLinkedList<_Type>::Node* temp = head;
	while (temp && temp->value != value)
		temp = temp->next;

	if (!temp)
		return false;
	else
		return true;
}

template <class _Type>
_Type& SimpleLinkedList<_Type>::operator[](uint32_t const& index) const
{
	assert(index < size && index >= 0 && !isEmpty());

	typename SimpleLinkedList<_Type>::Node* temp = head;
	for (uint32_t i = 0; i < index; i++)
		temp = temp->next;

	return temp->value;
}

template <class _Type>
std::ostream& operator<<(std::ostream& os, SimpleLinkedList<_Type> const& list)
{
	if (list.isEmpty())
		return os;

	for (uint32_t i = 0; i < list.getSize(); i++)
		os << list[i] << " ";
	os << "\n";

	return os;
}

template <class _Type>
std::ofstream& operator<<(std::ofstream& ofs, SimpleLinkedList<_Type> const& list)
{
	if (list.isEmpty())
		return ofs;

	for (uint32_t i = 0; i < list.getSize(); i++)
		ofs << list[i] << " ";
	ofs << "\n";

	return ofs;
}

template <class _Type>
std::istream& operator>>(std::istream& is, SimpleLinkedList<_Type>& list)
{
	uint32_t size;
	is >> size;

	for (uint32_t i = 0; i < size; i++)
	{
		_Type value;
		is >> value;
		list.pushBack(value);
	}

	return is;
}

template <class _Type>
std::ifstream& operator>>(std::ifstream& ifs, SimpleLinkedList<_Type>& list)
{
	uint32_t size;
	ifs >> size;

	for (uint32_t i = 0; i < size; i++)
	{
		_Type value;
		ifs >> value;
		list.pushBack(value);
	}

	return ifs;
}

