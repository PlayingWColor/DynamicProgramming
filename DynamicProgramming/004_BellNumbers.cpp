#include "004_BellNumbers.h"

vector<vector<int>> bells;

//O(2^n) without DP
//O(1) to O(n) with DP
int Bell(int n, int k)
{
	if (n == 0 || k == 0 || k > n)
		return 0;
	if (n == k || k == 1)
		return 1;

	if (bells.size() < k - 1)
		bells.resize(k - 1);
	if (bells.at(k - 2).size() < n - k)
		bells.at(k - 2).resize(n - k, -1);

	if(bells.at(k - 2).at(n - k - 1) == -1)
		bells.at(k - 2).at(n - k - 1) = k * Bell(n - 1, k) + Bell(n - 1, k - 1);

	return bells.at(k - 2).at(n - k - 1);
}

//O(n 2^n) without DP
//O(n) to O(n^2) with DP
int getNthBellNumber(int n)
{
	int result = 1;
	
	for(int k = 2; k <= n; k++)
		result += Bell(n, k);

	return result;
}



void BellNumbers::main()
{
	int n;
	coutline << "Nth Bell Number to Return: ";
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	TStart();
	int result = getNthBellNumber(n);
	TEnd();

	coutline << result;
}

int BellNumbers::Get(int n)
{
	return getNthBellNumber(n);
}

int BellNumbers::GetBell(int n, int k)
{
	return Bell(n, k);
}