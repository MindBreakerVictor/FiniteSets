// Shouldn't be included in the project, it's only included by the header file

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
std::ostream& operator<<(std::ostream& os, const SimpleLinkedList<T>& sll)
{
	if (sll.isEmpty())
		return os;

	for (uint i = 0; i < sll.getSize(); i++)
		os << sll[i] << " ";
	os << "\n";

	return os;
}

template <class T>
std::ofstream& operator<<(std::ofstream& ofs, const SimpleLinkedList<T>& sll)
{
	if (sll.isEmpty())
		return ofs;

	for (uint i = 0; i < sll.getSize(); i++)
		ofs << sll[i] << " ";
	ofs << "\n";

	return ofs;
}

template <class T>
std::istream& operator>>(std::istream& is, SimpleLinkedList<T>& sll)
{
	uint size;
	is >> size;

	for (uint i = 0; i < size; i++)
	{
		int value;
		is >> value;
		sll.pushBack(value);
	}

	return is;
}

template <class T>
std::ifstream& operator>>(std::ifstream& ifs, SimpleLinkedList<T>& sll)
{
	uint size;
	ifs >> size;

	for (uint i = 0; i < size; i++)
	{
		int value;
		ifs >> value;
		sll.pushBack(value);
	}

	return ifs;
}
