#ifndef BUBBLESORT_H
#define BUBBLESORT_H
// from ./22.8.30/SortingArray.h
#include"SortingArray.h"
using std::swap;

template<typename T>
class Bubblesort :public SortingMethod<T>
{
public:
	//模板父类的名称在子类中不是直接可见的，我们需要显式让编译器寻找父类
	using SortingMethod<T>::num;
	using SortingMethod<T>::length;
	using SortingMethod<T>::Greater;


	Bubblesort() :SortingMethod<T>(){}


	void sort() override
	{
		//冒泡排序，默认升序排列
		for (int i = 1; i <= length; ++i)
		{
			for (int j = i + 1; j <= length; ++j)
			{
				if (num[i] > num[j]) swap(num[i], num[j]);
			}
		}

		//如果要求降序排列，则交换首尾
		if (!Greater) { for (int i = 1; i <= length / 2; ++i)swap(num[i], num[length + 1 - i]); }

		return;
	};

};



#endif