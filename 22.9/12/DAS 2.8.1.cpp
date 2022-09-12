#include<iostream>
#include<Windows.h>
#include <ctime>
#include <cstdlib>
using namespace std;
#define N 6400000
int randInt(int i, int j)
{
	return rand() % (j - i);
}
int a[N] = { 0 };
int ran[N] = { 0 };

int main()
{
    srand(time(0));
	int i = 0;
	double start = clock();
	while (a[i] == 0)
	{
		int tem = randInt(0, N)+1;
		int BOOL = 1;
		for (int j = 0; j <= i; j++)
		{
			if (tem == a[j])
			{
				BOOL = 0;
				break;
			}
		}

		if (BOOL)
		{
			a[i] = tem;
			i++;
		}
		if (i >= N)
			break;

	}
	double end = clock();
	cout << "当N=" << N << "时," << "运行时间为" << end - start << "ms" << endl;


}
