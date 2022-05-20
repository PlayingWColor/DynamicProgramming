#include "MaxValue.h"

int GetMaxValue(vector<int>& memo, const vector<int>& HighScores, int n)
{
	if (n >= HighScores.size())
		return 0;

	if (memo[n] == -1)
	{
		int maxFirst = HighScores[n] + GetMaxValue(memo, HighScores, n + 2);
		int maxSecond = HighScores[n] + GetMaxValue(memo, HighScores, n + 3);
		memo[n] = maxFirst > maxSecond ? maxFirst : maxSecond;
	}
	return memo[n];
}

int GetMaxValue(const vector<int>& HighScores)
{
	if (HighScores.empty())
		return 0;
	vector<int> memo;
	memo.resize(HighScores.size(), -1);
	
	int maxFirst = GetMaxValue(memo, HighScores, 0);
	int maxSecond = GetMaxValue(memo, HighScores, 1);
	
	return maxFirst > maxSecond ? maxFirst : maxSecond;
}


void MaxValue::main()
{
	string s;
	coutline << "Input Set of Non Negatives Seperated by Spaces: ";
	getline(cin, s);

	vector<int> set;
	stringstream ss;
	ss << s;

	while (ss.good())
	{
		int next;
		ss >> next;
		set.push_back(next);
	}

	TStart();
	int result = GetMaxValue(set);
	TEnd();

	coutline << result;
}