#include"teamup.h"
int main()
{
	srand(time(0));
	int num=42;
	int* randnum = new int[42+2];
	TeamMaker tm(num,randnum);
	tm.work();
	tm.show();
	tm.work();
	tm.show();
	delete[] randnum;
}