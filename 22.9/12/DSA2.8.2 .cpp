#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int a[25000*2*2*2*2*2];
int used[25000*2*2*2*2*2+1];
int main()
{
	srand(time(nullptr));
	int n = 25000*2*2*2*2*2;
	int temp;
	clock_t start, finish;
	double duration=0;
	for (int b = 0; b < 10; ++b)
	{
		start = clock();
		for (int i = 0; i < n; ++i)
		{
			temp = rand() % n + 1;//生成随机数
			while (used[temp] == 1)//如果该随机数已使用
			{
				temp = rand() % n + 1;//重新生成随机数
				continue;//继续循环检测
			}
			a[i] = temp;//生成未使用的随机数后循环结束，赋值
		}
		finish = clock();
		cout << "当n=" << n << "时,第"<<b+1<<"次运行时间为" << finish - start << "ms" << endl;
		duration += finish - start;

	}
	cout << "当n=" << n << "时，运行10次平均运行时间为" << duration/10 << "ms" << endl;
	/*for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}//冒泡排序

	for (int k = 0; k < n; ++k)//展示
	{
		cout << a[k]<<"\n";
	}*/

}
