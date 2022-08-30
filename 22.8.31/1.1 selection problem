//1.1 selection problem
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

void bubble_sort(vector<int> array, int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - 1 - i; ++j)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
			}
		}
	}
}

int main()
{
	srand((int)time(NULL));
	clock_t start, finish;
	double  duration;
	for (int N = 2; N < 1500; N+=2)
	{
		vector<int> v;
		int k = N / 2;
		for (int m = 0; m < N; ++m)
		{
			v.push_back(rand());
		}
		int l = v.size();
		start = clock();
		bubble_sort(v, l);
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		cout << "N=" << N << "\tk=" << k 
			<< "\t第"<<k<<"个数为:" << v[k] 
			<<"\t用时:" <<duration<< endl;
	}
}
