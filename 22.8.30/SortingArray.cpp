#include "SortingArray.h"
#include<iostream>
using namespace std;
int main()
{
	int data[6] = { 0,1,2,3,4,5 };
	SortingArray<int>* saptr = new SortingArray<int>(data, 5);
	SortingMethod<int> *sm=new SortingMethod<int>;
	saptr->setMethod(sm);
	cout << data<<endl;
	cout << saptr->getData()<<endl;
	cout << saptr->_getSortingMethod()->_getDataLoc();

}