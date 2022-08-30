#ifndef SortingArray_H
#define SortingArray_H

#include<iostream>
using std::cerr;
using std::string;

//执行排序的外包类
template<typename T>
class SortingMethod
{
public:
	//构造函数
	SortingMethod():num(nullptr),length(0),Greater(0) {}

	//用于初始化，仅用于与其对应的SortingArray绑定。绑定后，num指向的数组就是SortingArray中的data，length等于data的长度
	void setData(T* a, int b) { num = a, length = b; }
	
	void setGreater(bool isGreater) { Greater = isGreater; }


	//仅用于调试，用于获得num数组的首位置
	T* _getDataLoc() { return num; }
	
	//仅用于调试，用于获得num数组的长度
	int _getLength() { return length; }


	//虚函数sort根据子类不同进行填充,执行SortingMethod类的主要逻辑
	virtual void sort() {};

	
protected:
	//指向与之对应的SortingArray内data储存的地址，SortingMethod类可以通过num指针修改SortingArray.data的值
	T* num;
	int length;
	bool Greater;
};

//用于储存需要排序的值,通过绑定一个SortingMethod实现排序功能,下标从1开始
template<typename T>
class SortingArray
{
public:
	SortingArray() = delete;

	//将一个无序的数组复制到SortingArray中，该数组下标从1开始，到n结束
	SortingArray(const T const* a, const int& n):_method(nullptr)
	{
		length = n;
		data = new T[n];
		for (int i = 1; i <= n; ++i) { data[i] = a[i]; }
		methodSet = 0;
	}

	~SortingArray() { delete[] data; }

	//该函数用于绑定一个SortingMethod，传入要绑定的SortingMethod和排序方式（默认递增）,sm将获得data的地址，并通过这个地址直接访问/修改data
	void setMethod(SortingMethod<T>* sm, bool isGreater = 1) { if (!sm) { cerr << "Not legal"; return; } _method = sm; _method->setData(data, length); methodSet = 1; _method->setGreater(isGreater); }

	//执行sorting
	void sorting()
	{
		if (!methodSet) { cerr << "MethodNotSet"; return; }
		_method->sort();
	}

	//debug use only
	void _show() const
	{
		std::cout << length << std::endl;
		for (int i = 1; i <= length; ++i) std::cout << data[i] << " ";
	}
	bool _getMethodSet()const { return methodSet; }
	void _getSortingMethodType()const
	{
		std::cout << typeid(*_method).name();
	}
	T* getData()const { return data; }
	SortingMethod<T>* _getSortingMethod() { return _method; }

private:
	T* data;
	int length;
	SortingMethod<T>* _method;
	bool methodSet;//1 if the sorting method is set.
	
};



#endif // !SortingArray
