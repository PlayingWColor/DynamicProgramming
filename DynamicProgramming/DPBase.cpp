#include "DPBase.h"
DPBase::DPBase()
{

}


void DPBase::init()
{

	void TStart();

	main();

	if (!endSet)
		TEnd();

	if (chrono::duration_cast<chrono::seconds> (end - begin).count() > 100)
		coutline << endl << "Time elapsed = " << chrono::duration_cast<chrono::seconds>(end - begin).count() << "[s]" << endl;
	if (chrono::duration_cast<chrono::milliseconds> (end - begin).count() > 100)
		coutline << endl << "Time elapsed = " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << endl;
	else if(chrono::duration_cast<chrono::microseconds> (end - begin).count() > 100)
		coutline << endl << "Time elapsed = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "[µs]" << endl;
	else
		coutline << endl << "Time elapsed = " << chrono::duration_cast<chrono::nanoseconds> (end - begin).count() << "[ns]" << endl;
}

void DPBase::TStart()
{
	begin = chrono::steady_clock::now();
}

void DPBase::TEnd()
{
	end = chrono::steady_clock::now();
	endSet = true;
}

void DPBase::main()
{

}