#include "Pair.h"

Pair& Pair::operator=(const Pair& source)
{
	if (this == &source)
		return *this;

	this->a = source.a;
	this->b = source.b;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Pair& pair)
{
	os << "(" << pair.a << ", " << pair.b << ")";
	return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const Pair& pair)
{
	ofs << "(" << pair.a << ", " << pair.b << ")";
	return ofs;
}

std::istream& operator>>(std::istream& is, Pair& pair)
{
	is >> pair.a >> pair.b;
	return is;
}

std::ifstream& operator>>(std::ifstream& ifs, Pair& pair)
{
	ifs >> pair.a >> pair.b;
	return ifs;
}

bool operator==(const Pair& pairOne, const Pair& pairTwo)
{
	return (pairOne.a == pairTwo.a && pairOne.b == pairTwo.b);
}
