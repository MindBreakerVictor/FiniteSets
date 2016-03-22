#ifndef _SLL_H
#define _SLL_H

#include "PCH.h"

template <class T> 
class SimpleLinkedList
{
	public:
		SimpleLinkedList() : head(nullptr), tail(nullptr), size(0) { }

		SimpleLinkedList(uint n) : size(n)
		{
			for (uint i = 0; i < size; i++)
			{
				T value;
				std::cin >> value;
				if (!hasValue(value))
					pushBack(value);
			}
		}

		SimpleLinkedList(uint n, std::ifstream &in) : size(n)
		{
			for (uint i = 0; i < size; i++)
			{
				T value;
				in >> value;
				if (!hasValue(value))
					pushBack(value);
			}
		}

		SimpleLinkedList(const SimpleLinkedList<T>& source) : size(0)
		{
			Node *temp = source.head;
			for (uint i = 0; i < source.getSize(); i++)
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

		void pushFront(T value);
		void pushBack(T value);

		void popValue(T value);
		void popFront() { popValue(head->value); }
		void popBack() { popValue(tail->value); }

		bool isEmpty() const { return !size; }
		bool hasValue(T value) const;

		uint getSize() const { return size; }

		T& operator[](const uint index) const;

	private:
		struct Node
		{
			T value;
			Node *next;
		};

		Node *head, *tail;
		uint size;
};

template <class T>
void SimpleLinkedList<T>::pushFront(T value)
{
	typename SimpleLinkedList<T>::Node *elem = new Node;
	elem->value = value;

	elem->next = head;

	head = elem;
	size++;
}

template <class T>
void SimpleLinkedList<T>::pushBack(T value)
{
	typename SimpleLinkedList<T>::Node *elem = new Node;
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

template <class T>
void SimpleLinkedList<T>::popValue(T value)
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
			typename SimpleLinkedList<T>::Node *temp = head;
			head = head->next;
			delete temp;
		}
		return;
	}

	typename SimpleLinkedList<T>::Node *temp = head;
	while (temp->next && temp->next->value != value)
		temp = temp->next;

	if (temp->next)
	{
		Node *del = temp->next;
		temp->next = temp->next->next;
		delete del;
		size--;
	}
}

template <class T>
bool SimpleLinkedList<T>::hasValue(T value) const
{
	if (isEmpty())
		return false;

	typename SimpleLinkedList<T>::Node *temp = head;
	while (temp && temp->value != value)
		temp = temp->next;

	if (!temp)
		return false;
	else
		return true;
}

template <class T>
T& SimpleLinkedList<T>::operator[](const uint index) const
{
	assert(index < size && index >= 0 && !isEmpty());

	typename SimpleLinkedList<T>::Node *temp = head;
	for (uint i = 0; i < index; i++)
		temp = temp->next;

	return temp->value;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const SimpleLinkedList<T>& list)
{
	if (list.isEmpty())
		return os;

	for (uint i = 0; i < list.getSize(); i++)
		os << list[i] << " ";
	os << "\n";

	return os;
}

template <class T>
std::ofstream& operator<<(std::ofstream& ofs, const SimpleLinkedList<T>& list)
{
	if (list.isEmpty())
		return ofs;

	for (uint i = 0; i < list.getSize(); i++)
		ofs << list[i] << " ";
	ofs << "\n";

	return ofs;
}

template <class T>
std::istream& operator>>(std::istream& is, SimpleLinkedList<T>& list)
{
	uint size;
	is >> size;

	for (uint i = 0; i < size; i++)
	{
		T value;
		is >> value;
		list.pushBack(value);
	}

	return is;
}

template <class T>
std::ifstream& operator>>(std::ifstream& ifs, SimpleLinkedList<T>& list)
{
	uint size;
	ifs >> size;

	for (uint i = 0; i < size; i++)
	{
		T value;
		ifs >> value;
		list.pushBack(value);
	}

	return ifs;
}

#endif
