#ifndef SHELLSORT_H
#define SHELLSORT_H
// from ./22.8.30/SortingArray.h
#include"SortingArray.h"
using std::swap;

template<typename T>
class ShellSort :public SortingMethod<T>
{
public:
	//模板父类的名称在子类中不是直接可见的，我们需要显式让编译器寻找父类
	using SortingMethod<T>::num;
	using SortingMethod<T>::length;
	using SortingMethod<T>::Greater;


	ShellSort() :SortingMethod<T>(){}

	void sort() override
	{
		for (int gap = length / 2; gap > 0; gap /= 2)	//第一个for用于枚举距离gap
			for (int i = gap + 1; i <= length; ++i)		//第二个for用于枚举区间结束位置
			{
				int j = i;
				for (; j > gap && num[j] < num[j - gap]; j -= gap)	//将num[i]移动到合适的位置
				{													//当gap=1时，退化为插入排序
					swap(num[j], num[j - gap]);
				}

			}

		//如果要求降序排列，则交换首尾
		if (!Greater) { for (int i = 1; i <= length / 2; ++i)swap(num[i], num[length + 1 - i]); }

		return;
	};

};



#endif