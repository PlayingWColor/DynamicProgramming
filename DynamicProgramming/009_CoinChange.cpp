#include "009_CoinChange.h"

//O(m^n) without DP
//O(nm) with DP
int getNumOfCoins(int n, int startI, const vector<int>& d, vector<vector<int>>& memo)
{
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;

	if (memo.size() < n)
		memo.resize(n);
	if (memo[n - 1].size() < d[startI])
		memo[n - 1].resize(d[startI], -1);

	if (memo[n - 1][d[startI]-1] == -1)
	{
		int total = 0;

		for (int i = startI; i < d.size(); i++)
		{
			total += getNumOfCoins(n - d[i], i, d, memo);
		}
		memo[n - 1][d[startI]-1] = total;
	}
	return memo[n - 1][d[startI]-1];
}

void CoinChange::main()
{
	int n;
	coutline << "Total Value: ";
	cin >> n;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string s;
	coutline << "Input All Denominations then Press Enter: ";
	getline(cin, s);

	vector<int> denom;
	stringstream ss;
	ss << s;

	while (ss.good())
	{
		int next;
		ss >> next;
		denom.push_back(next);
	}

	vector<vector<int>> memo;

	TStart();
	int result = getNumOfCoins(n, 0, denom, memo);
	TEnd();

	coutline << result;

}