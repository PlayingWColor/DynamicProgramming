#include "010_FriendsPairing.h"

vector<int> bellNums;

//O(2^n) without DP
//O(1) to O(n) with DP
int getBellNumbers(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;

	if (bellNums.size() < n + 1)
		bellNums.resize(n + 1,-1);
	
	if(bellNums[n] == -1)
		bellNums[n] = getBellNumbers(n - 1) + (n - 1) * getBellNumbers(n - 2);
	return bellNums[n];
}

void FriendsPairing::main()
{
	int n;
	coutline << "Number of Friends: ";
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	TStart();
	int result = getBellNumbers(n);
	TEnd();

	coutline << result;
}