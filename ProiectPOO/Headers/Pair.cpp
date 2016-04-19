#include "PCH.h"
#include "Pair.h"

Pair& Pair::operator=(Pair const& source)
{
	if (this == &source)
		return *this;

	this->a = source.a;
	this->b = source.b;

	return *this;
}

std::ostream& operator<<(std::ostream& os, Pair const& pair)
{
	os << "(" << pair.a << ", " << pair.b << ")";
	return os;
}

std::ofstream& operator<<(std::ofstream& ofs, Pair const& pair)
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

