#include "006_PermutationCoefficient.h"

vector<vector<int>> pcoefs;

//O(2^n) without DP
//O(1) to O(n) with DP
int getPCoeff(int n, int k)
{
	if (n < k)
		return 0;
	if (k == 0)
		return 1;

	if (pcoefs.size() < k)
		pcoefs.resize(k);
	if (pcoefs.at(k - 1).size() < n - k + 1)
		pcoefs.at(k - 1).resize(n - k + 1, -1);

	if (pcoefs.at(k - 1).at(n - k) == -1)
		pcoefs.at(k - 1).at(n - k) = getPCoeff(n - 1, k) + k * getPCoeff(n - 1, k - 1);

	return pcoefs.at(k - 1).at(n - k);
}

void PermutationCoefficient::main()
{
	coutline << "Input N and K to find the Permutation Coefficient." << endl;

	int n;
	coutline << "N: ";
	cin >> n;

	int k;
	coutline << "K: ";
	cin >> k;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	TStart();
	int result = getPCoeff(n, k);
	TEnd();

	coutline << result;
}