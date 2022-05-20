#pragma once
#include "DPALL.h"

void checkRerun()
{
	char doit;
	coutline << "Hit Enter to Rerun Program";
	cin.get();

	coutline << "Rerunning..." << endl;
}

int main()
{
	while (true)
	{
		DPBase* dp = new FireTick();
		dp->init();

		delete(dp);

		checkRerun();
	}
	string i;
	cin >> i;

	return 0;
}