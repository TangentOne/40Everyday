#ifndef TEAMUP_H
#define TEAMUP_H

#include<algorithm>
#include<cstdlib>
#include<iostream>

using std::ofstream;
using std::ifstream;
using std::cout;

////将学号对应的人输出到文件中
//class Translator
//{
//public:
//	Translator() {}
//private:
//	ofstream ofs;
//	ifstream ifs;
//};

class TeamMaker
{
public:
	TeamMaker(int n, int*& ptr) :num(n), p(ptr), check(nullptr) {};
	//~TeamMaker() { if (check) { delete[] check; } }
	void work();
	void show()const { for (int i = 1; i <= num; ++i) cout << p[i] << " "; cout << std::endl; };
private:
	int num;
	int *p;
	bool *check;
};

void TeamMaker::work()
{
	check = new bool[num+2];
	for (int i = 1; i <= num; ++i) check[i] = 0;
	
	int i = 1;
	while(i<=num)
	{
		int x = rand() % num + 1;
		if (!check[x])
		{
			check[x] = 1;
			p[i++] = x;
		}
	}
	delete[] check;
	return;
}



#endif