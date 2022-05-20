#include "FireTick.h"

int Tick(float fDeltaSeconds, float& fTimeUntilNextAttack, float& fAttackPeriod)
{
	// Fire Mystical Mail every "fAttackPeriod" seconds
	fTimeUntilNextAttack -= fDeltaSeconds;
	int totalAttack = 0;
	while (fTimeUntilNextAttack <= 0)
	{
		totalAttack++;//Fire();
		fTimeUntilNextAttack += fAttackPeriod;
	}

	return totalAttack;
}

void FireTick::main()
{
	float time;

	float attack;
	coutline << "Attack Period: ";
	cin >> attack;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	time = 0;

	float s;
	coutline << "How Many Seconds: ";
	cin >> s;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');


	TStart();
	int result = 0;
	for (int i = 0; i < s; i++)
	{
		result += Tick(1.0f,time,attack);
	}
	TEnd();

	coutline << result;
}