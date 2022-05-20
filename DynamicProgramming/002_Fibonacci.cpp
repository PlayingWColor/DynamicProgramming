#include "002_Fibonacci.h"

//Recursive
//O(n)
long getNthFibonacci(int n, long f0, long f1)
{
	if (n > 1)
		return getNthFibonacci(n-1,f1,f0+f1);
	else
		return f1;
}

//Recursive No Memoization
//O(2^n)
long getNthFibonacciNOM(long n)
{
	if (n == 1)
		return 1;
	if (n == 0)
		return 0;
	return getNthFibonacciNOM(n - 1) + getNthFibonacciNOM(n - 2);
}

vector<long> Fibonnaccis;

//Recursive with Memoization
//O(1) to O(n)
long getNthFibonacci(long n)
{
	if (n == 1)
		return 1;
	if (n == 0)
		return 0;

	if (Fibonnaccis.size() < n + 1)
		Fibonnaccis.resize(n + 1, -1);

	if (Fibonnaccis[n] == -1)
		Fibonnaccis[n] = getNthFibonacci(n - 1) + getNthFibonacci(n - 2);

	return Fibonnaccis[n];
}

//Iterative
//O(n)
long getNthFibonacciI(int n, long f0, long f1)
{
	for (int i = 0; i < n; i++)
	{
		int f2 = f0 + f1;
		f0 = f1;
		f1 = f2;
	}

	return f0;
}

void Fibonacci::main()
{
	int n;
	coutline << "Nth Fibonacci Number to Return: ";
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	TStart();
	long result = getNthFibonacci(n);
	TEnd();

	coutline << result;
}

long Fibonacci::Get(long n)
{
	return getNthFibonacci(n);
}