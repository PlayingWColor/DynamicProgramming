#pragma once
#include "DPBase.h"

class Fibonacci : public DPBase
{
private:
	virtual void main();
public:
	static long Get(long n);
};