#include "SortingArray.h"
#include "ShellSort.h"
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* data = new int[n + 2];
	for (int i = 1; i <= n; ++i) cin >> data[i];
	SortingArray<int>* saptr = new SortingArray<int>(data, n);
	SortingMethod<int> *sm=new ShellSort<int>;
	saptr->setMethod(sm);
	saptr->sorting();
	saptr->_show();

}