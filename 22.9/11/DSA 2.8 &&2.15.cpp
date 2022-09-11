//2.8 算法2
#include<iostream>
#include<Windows.h>
#include <ctime>
#include <cstdlib>
using namespace std;
#define N 800000
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
	double start =clock();
	while (a[i] == 0) 
	{
		int tem = randInt(0, N)+1;
		if (!ran[tem])
			ran[tem] = 1;
		if (ran[tem])
		{
			a[i] = tem;
			i++;
		}
	}
	double end = clock();
	cout << "当N=" << N << "时," << "运行时间为" << end - start << "ms"<<endl;
}

//2.15 二分查找
bool search(vector<int>& nums, int target)
    {
        int top = 0;
        int end = nums.size() - 1;
        int mid = (top + end) / 2;
        while (top <= end)
        {
            if (nums[mid]==mid)
                return mid;
            else if (nums[mid]>mid)
                end = mid - 1;
            else top = mid + 1;
            mid = (top + end) / 2;
        }
        return -1;
}
