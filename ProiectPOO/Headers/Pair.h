#pragma once

#include "PCH.h"
#include "FiniteSet.h"

class Pair
{
	public:
		explicit Pair(int _a = 0, int _b = 0) : a(_a), b(_b) { }
		Pair(Pair const& source) : a(source.a), b(source.b) { }
		~Pair() { }

		Pair& operator=(Pair const& source);

		friend std::ostream& operator<<(std::ostream& os, Pair const& pair);
		friend std::ofstream& operator<<(std::ofstream& ofs, Pair const& pair);
		friend std::istream& operator>>(std::istream& is, Pair& pair);
		friend std::ifstream& operator>>(std::ifstream& ifs, Pair& pair);

		bool operator==(Pair const& pair) const { return (this->a == pair.a && this->b == pair.b); }
		bool operator!=(Pair const& pair) const { return !(*this == pair); }

		friend class FiniteSetPairs;

	private:
		int a, b;
};

