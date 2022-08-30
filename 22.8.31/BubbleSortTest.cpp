#include "SortingArray.h"
#include "BubbleSort.h"
#include<iostream>
using namespace std;
int main()
{
	int data[6] = { 0,2,5,1,3,4 };
	SortingArray<int>* saptr = new SortingArray<int>(data, 5);
	SortingMethod<int> *sm=new Bubblesort<int>;
	saptr->setMethod(sm);
	saptr->sorting();
	saptr->_show();

}