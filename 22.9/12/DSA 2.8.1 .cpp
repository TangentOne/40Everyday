#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	srand(time(nullptr));
	int a[250*2*2*2];
	int n = 250*2*2*2;
	int temp;
	clock_t start, finish;
	double duration=0;
	a[0] = rand() % n +1;
	for (int b = 0; b < 10; ++b)
	{
		start = clock();
		for (int i = 1; i < n; ++i)
		{
			temp = rand() % n + 1;
			for (int j = 0; j < i;)
			{
				if (temp == a[j])
				{
					temp = rand() % n + 1;
					j = 0;
					continue;
				}
				else
				{
					if (j == i - 1)
					{
						a[i] = temp;
						break;
					}
					++j;
					continue;
				}
			}
		}
		finish = clock();
		cout << "当n=" << n << "时，运行时间为" << finish - start << "ms" << endl;
		duration += finish - start;

	}
	cout << "当n=" << n << "时，运行10次平均运行时间为" << duration/10 << "ms" << endl;
	//for (int i = 0; i < n - 1; ++i)
	//{
	//	for (int j = 0; j < n - i - 1; ++j)
	//	{
	//		if (a[j] > a[j + 1])
	//			swap(a[j], a[j + 1]);
	//	}
	//}
	//for (int k = 0; k < n; ++k)
	//{
	//	cout << a[k]<<"\n";
	//}

}
