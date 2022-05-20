#include "008_GoldMine.h"

struct pos
{
	pos(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	
	int x; int y;
};

//O(3^n) without DP
//O(n) with DP
int getMostGold(const vector<vector<int>>& mine, vector<vector<int>>& memo, pos p)
{
	if (p.x + 1 == mine[p.y].size())
	{
		return mine[p.y][p.x];
	}

	if (memo[p.y][p.x] == -1)
	{
		int largest = numeric_limits<int>::min();
		int next = getMostGold(mine, memo, pos(p.x + 1, p.y));
		if (next > largest)
			largest = next;

		if (p.y > 0)
		{
			next = getMostGold(mine, memo, pos(p.x + 1, p.y - 1));
			if (next > largest)
				largest = next;
		}

		if (p.y < mine[p.y].size() - 1)
		{
			next = getMostGold(mine, memo, pos(p.x + 1, p.y + 1));
			if (next > largest)
				largest = next;
		}

		memo[p.y][p.x] = largest + mine[p.y][p.x];
	}
	return memo[p.y][p.x];
}

//O(m*3^n) without DP
//O(m*n) with DP
int getMostGold(const vector<vector<int>>& mine, vector<vector<int>>& memo)
{
	int largest = numeric_limits<int>::min();
	
	for (int i = 0; i < mine.size(); i++)
	{
		int next = getMostGold(mine, memo, pos(0,i));
		if (next > largest)
			largest = next;
	}

	return largest;
}

void GoldMine::main()
{
	
	int x;
	coutline << "Width of Mine: ";
	cin >> x;

	int y;
	coutline << "Height of Mine: ";
	cin >> y;

	int max;
	coutline << "Max Gold Per Cell: ";
	cin >> max;

	int min;
	coutline << "Min Gold Per Cell: ";
	cin >> min;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<vector<int>> mine;
	mine.resize(y);

	for (int i = 0; i < y; i++)
	{
		mine.at(i).resize(x);
		for (int j = 0; j < x; j++)
		{
			mine.at(i).at(j) = rand() % (max-min+1) + min;// (max - min) + min;
		}
	}

	vector<vector<int>> memo;
	memo.resize(mine.size());
	for (int i = 0; i < memo.size(); i++)
	{
		memo.at(i).resize(mine[i].size(),-1);
	}

	coutline;
	for (int i = 0; i < mine.size(); i++)
	{
		for (int j = 0; j < mine.at(i).size(); j++)
		{
			cout << mine[i][j] << " ";
		}
		coutline;
	}

	TStart();
	int result = getMostGold(mine, memo);
	TEnd();

	coutline << result;
}