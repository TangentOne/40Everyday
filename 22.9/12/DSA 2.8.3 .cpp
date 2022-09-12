#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int a[100000*2*2*2*2*2*2];
int n = 100000*2*2*2*2*2*2;
int main()
{
	srand(time(nullptr));
	clock_t start, finish;
	double duration=0;
	for (int b = 0; b < 10; ++b)
	{
		start = clock();
		for (int i = 0; i < n; ++i)
		{
			a[i] = i + 1;//生成顺序排列
		}
		for (int j = 1; j < n; ++j)
		{
			swap(a[j], a[rand() % (j + 1)]);//随机交换
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
