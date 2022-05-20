#pragma once
#include "DPBase.h"

class BellNumbers : public DPBase
{
private:
	virtual void main();
public:
	static int Get(int n);

	static int GetBell(int n, int k);

};