#include "005_BinomialCoefficient.h"

vector<vector<int>> bicoefs;

//O(2^n) without DP
//O(1) to O(n) with DP
int getBinomialCoefficient(int n, int k)
{
	if (n < k)
		return 0;
	if (k == 0 || k == n)
		return 1;

	if (bicoefs.size() < k)
		bicoefs.resize(k);
	if (bicoefs.at(k - 1).size() < n - k)
		bicoefs.at(k - 1).resize(n - k, -1);

	if (bicoefs.at(k - 1).at(n - k - 1) == -1)
		bicoefs.at(k - 1).at(n - k - 1) = getBinomialCoefficient(n - 1, k) + getBinomialCoefficient(n - 1, k - 1);

	return bicoefs.at(k - 1).at(n - k - 1);
}

void BinomialCoefficient::main()
{
	coutline << "Input N and K to find the Binomial Coefficient." << endl;
	
	int n;
	coutline << "N: ";
	cin >> n;

	int k;
	coutline << "K: ";
	cin >> k;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	TStart();
	int result = getBinomialCoefficient(n,k);
	TEnd();

	coutline << result;
}