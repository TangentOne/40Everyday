#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
// from ./22.8.30/SortingArray.h
#include"SortingArray.h"
using std::swap;

template<typename T>
class InsertionSort :public SortingMethod<T>
{
public:
	//模板父类的名称在子类中不是直接可见的，我们需要显式让编译器寻找父类
	using SortingMethod<T>::num;
	using SortingMethod<T>::length;
	using SortingMethod<T>::Greater;


	InsertionSort() :SortingMethod<T>(){}


	void sort() override
	{
		//插入排序，默认升序排列
		for (int i = 1; i < length; ++i)//保证从1到i位置的元素一定单调递增
		{
			int j = i+1;	//处理第i+1个元素
			while (j > 1 && (num[j-1]>num[j]) )	//while循环将这个元素一个个向前移动到第一个比它小的数后
			{
				swap(num[j - 1], num[j]);
				j--;
			}
		}

		//如果要求降序排列，则交换首尾
		if (!Greater) { for (int i = 1; i <= length / 2; ++i) swap(num[i], num[length + 1 - i]); }

		return;
	};

};



#endif