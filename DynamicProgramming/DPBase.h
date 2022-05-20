#pragma once
#include "c++std.h"

using namespace std;

class DPBase
{
public:
	DPBase();
	
	void init();

	virtual void main();

protected:
	//Start Timer
	void TStart();
	//End Timer
	void TEnd();

private:
	chrono::steady_clock::time_point begin;
	chrono::steady_clock::time_point end;
	bool endSet = false;
};