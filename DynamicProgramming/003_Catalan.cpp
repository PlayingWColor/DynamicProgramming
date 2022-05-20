#include "003_Catalan.h"
#define UINT64 unsigned long long

//Analytical Implementation

UINT64 FactorialANOM(UINT64 n)
{
	if (n <= 1)
		return n;
	return n * FactorialANOM(n-1);
}

//FactorialA But End at a Number Before Reaching 1
UINT64 FactorialWEndANOM(UINT64 n, UINT64 stop)
{
	if (n <= stop)
		return n;
	return n * FactorialWEndANOM(n - 1, stop);
}

//Brute Force Method
//Goes up to 10
//O(n)
UINT64 getNthCatalanANOM(UINT64 n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;

	//coutline << FactorialANOM(n * 2) << " / (" << FactorialANOM(n + 1) << " * " << FactorialANOM(n) << ")";

	return FactorialANOM(n * 2) / (FactorialANOM(n + 1) * FactorialANOM(n));
}

//Simplified Brute Force Method
//Goes up to 15
//O(n)
UINT64 getNthCatalanSANOM(UINT64 n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;

	//coutline << FactorialWEndANOM(n * 2, n + 2) << " / " << FactorialANOM(n);

	return FactorialWEndANOM(n * 2, n + 2) / FactorialANOM(n);
}

//Memoization
vector<vector<UINT64>> FactorialAs;

UINT64 FactorialA(UINT64 n)
{
	if (n <= 1)
		return n;

	if(FactorialAs.at(0).at(n) == -1)
		FactorialAs.at(0).at(n) = n * FactorialA(n - 1);

	return FactorialAs.at(0).at(n);
}

//FactorialA But End at a Number Before Reaching 1
UINT64 FactorialWEndA(UINT64 n, UINT64 stop)
{
	if (n <= stop)
		return n;

	if (FactorialAs.at(stop - 1).size() < n+1)
		FactorialAs.at(stop - 1).resize(n+1, -1);

	if (FactorialAs.at(stop - 1).at(n) == -1)
		FactorialAs.at(stop - 1).at(n) = n * FactorialWEndA(n - 1, stop);

	return FactorialAs.at(stop - 1).at(n);
}

//DP Method
//Goes up to 10
//O(1) to O(n)
UINT64 getNthCatalanA(UINT64 n)
{

	if (n == 0)
		return 1;
	if (n == 1)
		return 1;

	if (FactorialAs.empty())
		FactorialAs.resize(1);
	if (FactorialAs.at(0).size() < (n*2)+1)
		FactorialAs.at(0).resize((n * 2) + 1, -1);

	//coutline << FactorialA(n * 2) << " / (" << FactorialA(n + 1) << " * " << FactorialA(n) << ")";

	return FactorialA(n * 2) / (FactorialA(n + 1) * FactorialA(n));
}

//Simplified DP Method
//Goes up to 15
//O(1) to O(n)
UINT64 getNthCatalanSA(UINT64 n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;

	if (FactorialAs.size() < n + 2)
		FactorialAs.resize(n + 2);
	if (FactorialAs.at(0).size() < n+1)
		FactorialAs.at(0).resize(n+1,-1);

	//coutline << FactorialWEndA(n * 2, n + 2) << " / " << FactorialA(n);

	return FactorialWEndA(n * 2, n + 2) / FactorialA(n);
}

//True Recursive Implementation
//O(n^2)
UINT64 getNthCatalanNOM(UINT64 n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	
	UINT64 result = 0;
	
	for (unsigned int k = 0; k < n; k++)
	{
		result += getNthCatalanNOM((UINT64)k) *getNthCatalanNOM(n - ((UINT64)k) - 1);
	}

	return result;
}

//Memoization
vector<UINT64> Factorials;

//True Recursive Implementation with DP
//O(1) to O(n)
UINT64 getNthCatalan(UINT64 n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;

	UINT64 result = 0;

	if (Factorials.size() < n - 1)
		Factorials.resize(n - 1, -1);

	if (Factorials[n - 2] == -1)
	{
		for (unsigned int k = 0; k < n; k++)
		{
			result += getNthCatalan((UINT64)k) * getNthCatalan(n - ((UINT64)k) - 1);
		}

		Factorials[n - 2] = result;
	}
	else
	{
		result = Factorials[n - 2];
	}


	return result;
}

void Catalan::main()
{
	UINT64 n;
	coutline << "Nth Catalan Number to Return: ";
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	TStart();
	UINT64 result = getNthCatalan(n);
	TEnd();

	coutline << result;
}