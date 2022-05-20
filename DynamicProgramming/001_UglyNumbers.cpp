#include "001_UglyNumbers.h"


//Recursive - No Memoization
void findLowestDivNOM(int& toDiv, int divisor)
{
	while (toDiv % divisor == 0)
	{
		toDiv /= divisor;
	}
}

int getNthUglyNumberNOM(int n, int last)
{
	if (n > 0)
	{
		int lowestDiv = last;

		findLowestDivNOM(lowestDiv, 2);
		findLowestDivNOM(lowestDiv, 3);
		findLowestDivNOM(lowestDiv, 5);

		int result;

		if (lowestDiv == 1)
		{
			if (n == 1)
				return last;

			result = getNthUglyNumberNOM(n - 1, last + 1);
		}
		else
			result = getNthUglyNumberNOM(n, last + 1);

		return result;
	}
	return last;
}





vector<int> lowestDivs;

//O(n)
bool findLowestDiv(int& toDiv, int divisor)
{	
	while (toDiv % divisor == 0)
	{
		toDiv /= divisor;
		if (lowestDivs[toDiv] != -1)
		{
			toDiv = lowestDivs[toDiv];
			return true;
		}
	}

	return false;
}

//Recursive with Memoization
//O(n log n)
int getNthUglyNumber(int n, int last)
{
	if (n > 0)
	{
		if (lowestDivs.size() <= last)
		{
			lowestDivs.resize(last + 1,-1);
		}
		
		int lowestDiv = last;
		bool found = false;
		if (lowestDivs[last] == -1)
		{
			found = findLowestDiv(lowestDiv, 2);

			if(!found)
				found = findLowestDiv(lowestDiv, 3);

			if(!found)
				found = findLowestDiv(lowestDiv, 5);

			if(!found)
				lowestDivs[last] = lowestDiv;
		}
		else
		{
			lowestDiv = lowestDivs[last];
		}

		int result;

		if (lowestDiv == 1)
		{
			if (n == 1)
				return last;

			result = getNthUglyNumber(n - 1, last + 1);
		}
		else
			result = getNthUglyNumber(n, last + 1);

		return result;
	}
	return last;
}

//Iterative
//O (log n)
int getNthUglyNumberI(int n, int ugly)
{
	for (int i = 0; i < n; i++)
	{
		bool isUgly = false;
		while (!isUgly)
		{
			if (lowestDivs.size() <= ugly)
			{
				lowestDivs.resize(ugly + 1, -1);
			}

			int lowestDiv = ugly;
			bool found = false;
			if (lowestDivs[ugly] == -1)
			{
				found = findLowestDiv(lowestDiv, 2);

				if (!found)
					found = findLowestDiv(lowestDiv, 3);

				if (!found)
					found = findLowestDiv(lowestDiv, 5);

				if (!found)
					lowestDivs[ugly] = lowestDiv;
			}
			else
			{
				lowestDiv = lowestDivs[ugly];
			}

			isUgly = lowestDiv == 1;

			ugly++;
		}
	}

	return ugly-1;
}

void UglyNumbers::main()
{
	int n;
	coutline << "Nth Ugly Number to Return: ";
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	TStart();
	int result = getNthUglyNumber(n, 1);
	TEnd();

	coutline << result;
}