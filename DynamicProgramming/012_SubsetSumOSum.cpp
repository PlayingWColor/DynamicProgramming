#include "012_SubsetSumOSum.h"

//O(nm) time and O(n) space
bool getIfSubsetSumOSum(const vector<int>& set, const int sum)
{
	if (sum == 0)
		return true;

	vector<bool> results;
	results.resize(sum);

	for (int i = 0; i < set.size(); i++)
	{
		if (set[i] == sum)
			return true;
		if (set[i] < sum)
		{
			for (int j = 1; j <= sum; j++)
			{
				if (j - set[i] >= 0)
				{
					if (j - set[i] == 0)
						results[j - 1] = true;

					else if (results[j - set[i] - 1])
						results[j - 1] = true;
				}
			}
		}
	}

	return results[sum-1];
}

void SubsetSumOSum::main()
{
	string s;
	coutline << "Input Set of Non Negatives Seperated by Spaces: ";
	getline(cin, s);

	int n;
	coutline << "Subset Sum To Find: ";
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> set;
	stringstream ss;
	ss << s;

	while (ss.good())
	{
		int next;
		ss >> next;
		set.push_back(next);
	}

	vector<bool> memo;
	memo.resize(set.size(), false);

	TStart();
	bool result = getIfSubsetSumOSum(set, n);
	TEnd();

	coutline << (result ? "True" : "False");
}