#include<iostream>
#include"List.h"
using namespace std;

List list;

int main()
{
	list.push_front(2);
	//2
	list.insert(3,2);
	//2 3
	list.insert(1, 2, InsertionWay::IW_BEFORE);
	//1 2 3
	list.remove(1, RemoveWay::RW_BEFORE);
	//1 2 3		(ret 0)
	list.remove(1, RemoveWay::RW_AFTER);
	//1 3
	list.remove(3, RemoveWay::RW_AFTER);
	//1 3		(ret 0)
	list.outputAll();
	//1 3
	return 0;
}