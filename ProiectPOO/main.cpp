#include "Headers\FiniteSetPairs.h"
#include "Headers\FiniteSet.h"

int main()
{
	std::ifstream f("Inputs/in.in");
	FiniteSet<int> A(f), B(f);
	FiniteSetPairs C;

	std::cout << A << B;
	C.assignCartesianProduct(A, B);
	std::cout << C;

	_getch();
	return 0;
}
