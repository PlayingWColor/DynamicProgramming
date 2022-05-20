#include "007_TilingProblem.h"

void TilingProblem::main()
{
	int n;
	coutline << "Width of Board: ";
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	TStart();
	int result = Fibonacci::Get(n+1);
	TEnd();

	coutline << result;
}