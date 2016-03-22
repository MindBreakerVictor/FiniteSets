#include "Headers\FinitePairs.h"
#include "Headers\Finite.h"

int main()
{
	std::ifstream f("Inputs/in.in");
	Finite<int> A(f), B(f);
	FinitePairs C;

	std::cout << A << B;
	C.assignCartesianProduct(A, B);
	std::cout << C;

	_getch();
	return 0;
}
