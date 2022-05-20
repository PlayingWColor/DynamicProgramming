#include "FindIndex.h"

int FindIndex(const std::vector<int>& arr)
{
	int max = std::numeric_limits<int>::min();
	int index = -1;
	int start = 0;

	if (arr[0] == max)
	{
		index = 0;
		start = 1;
	}
	for (int i = start; i < arr.size(); i++)
	{
		if (arr[i] == max)
			index = -1;
		if (arr[i] > max)
		{
			max = arr[i];
			index = i;
		}

	}
	return index;
}

void FindIndexClass::main()
{
	string s;
	coutline << "Input Set of Integers Seperated by Spaces: ";
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
	int result = FindIndex(set);
	TEnd();

	coutline << result;
}