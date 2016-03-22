#ifndef _PAIR_H
#define _PAIR_H

#include "PCH.h"
#include "Finite.h"

class Pair
{
	public:
		explicit Pair(int _a = 0, int _b = 0) : a(_a), b(_b) { }
		Pair(const Pair& source) : a(source.a), b(source.b) { }
		~Pair() { }

		Pair& operator=(const Pair& source);

		friend std::ostream& operator<<(std::ostream& os, const Pair& pair);
		friend std::ofstream& operator<<(std::ofstream& ofs, const Pair& pair);
		friend std::istream& operator>>(std::istream& is, Pair& pair);
		friend std::ifstream& operator>>(std::ifstream& ifs, Pair& pair);

		friend bool operator==(const Pair& pairOne, const Pair& pairTwo);
		friend bool operator!=(const Pair& pairOne, const Pair& pairTwo) { return !(pairOne == pairTwo); }

		friend class FinitePairs;

	private:
		int a, b;
};

#endif
