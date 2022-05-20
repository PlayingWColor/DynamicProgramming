#include "011_SubsetSum.h"

//O(n!) at worst, O(1) at best
bool getIfSubsetSum(const vector<int>& set, int left, int startI)
{
	if (left < 0)
		return false;
	if (left == 0)
		return true;

	for (int i = startI; i < set.size(); i++)
	{
		if (getIfSubsetSum(set, left - set[i], i+1))
			return true;
	}
	return false;
}

void SubsetSum::main()
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
	bool result = getIfSubsetSum(set, n, 0);
	TEnd();

	coutline << (result ? "True" : "False");
}