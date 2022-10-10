//3.2
//a)
//单链表和下一个交换
void SingleList_Swap(node* beforeptr)
{
	node* p = beforeptr->next;
	node* afterptr = p->next;
	p->next = afterptr->next;
	beforeptr->next = afterptr;
	afterptr->next = p;

}
//b)
//双链表和下一个交换
void DoubleList_Swap(node* p)
{
	node* beforeptr;
	node* afterptr;
	beforeptr = p->prior;
	afterptr = p->next;
	p->next = afterptr->next;
	p->prior = afterptr;
	afterptr->next->prior = p;
	afterptr->next = p;
	afterptr->prior = beforeptr;
	beforeptr->next = afterptr;

}

//3.4
#ifndef LIST_H
#define LIST_H

struct node
{
	int data;
	node* next;
	node() :next(nullptr) {};
	
};

class List	
{
	
public:
	List();
	List(node*);
	~List();
	
	void Add_Value(int);//添加一个数
	void Set_Head(node*);//设置头节点
	node* Head();//返回头节点

private:
	node* head;
};
#endif LIST_H


#include"List.h"
#include<iostream>
using namespace std;
List::List(node* ptr)
{
	Set_Head(ptr);
}

List::List()
{
	Set_Head(nullptr);
}

List::~List()
{
	if (head->next == nullptr)
	{
		delete head;
		return;
	}
	node* p = head;
	node* q = p->next;
	while (p)
	{
		delete p;
		p = q;
		q = p->next;
	}
	delete p;
}

//返回头节点
node* List::Head()
{
	return head;
}
//设置头节点
void List::Set_Head(node* ptr)
{
	head = ptr;
}

//添加一个数
void List::Add_Value(int value)
{
	node* p = Head();
	if (!Check_Value(value))
	{
		while (p->next)
		{
			p = p->next;
		}
		p->next = new node;
		p->next->data = value;
		p->next->next = nullptr;
	}
}

#include<iostream>
#include"List.h"

List L1_AND_L2;
List And_Sortedlist(List L1, List L2)
{
	node* l1 = L1.Head();
	node* l2 = L2.Head();
	int value1;
	int value2;
	while (l1 && l2)
	{
		value1 = l1->data;
		value2 = l2->data;
		if (value1 == value2)
		{
			L1_AND_L2.Add_Value(value1);
			l1 = l1->next;
			l2 = l2->next;
		}
		else if (value1 > value2)
		{
			l2 = l2->next;
		}
		else
		{
			l1 = l1->next;
		}
	}
	return L1_AND_L2;
}

3.11
#ifndef LIST_H
#define LIST_H

struct node
{
	int data;
	node* next;
	node() :next(nullptr) {};
	
};

class List	
{
	
public:
	List();
	List(node*);
	~List();
	int	Number_List();//链表的大小
	void Print();//输出链表
	bool Check_Value(int);//判断一个数是否存在
	void Add_Value(int);//添加一个数
	void Remove_Value(int);//删除一个数
	void Set_Head(node*);//设置头节点
	node* Father_Node(int);//父节点
	node* Head();

private:
	node* head;
	int count;
};
#endif LIST_H


#include"List.h"
#include<iostream>
using namespace std;
List::List(node* ptr)
{
	Set_Head(ptr);
}

List::List()
{
	Set_Head(nullptr);
}

List::~List()
{
	if (head->next == nullptr)
	{
		delete head;
		return;
	}
	node* p = head;
	node* q = p->next;
	while (p)
	{
		delete p;
		p = q;
		q = p->next;
	}
	delete p;
}

node* List::Head()
{
	return head;
}

//父节点
node* List::Father_Node(int value)
{
	node* p = head;
	if (p == nullptr) return nullptr;
	while (p->next && p->next->data != value)
	{
		p = p->next;
	}
	if (p->next) return p;
	else return nullptr;

}

//设置头节点
void List::Set_Head(node* ptr)
{
	head = ptr;
}

//链表的大小
int List::Number_List()
{
	count = 0;
	node* p = Head();
	while (p->next)
	{
		count++;
		p = p->next;
	}
	return count;

}

//输出链表
void List::Print()
{
	node* p = Head();
	while (p->next)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
}

//判断一个数是否存在
bool List::Check_Value(int value)
{
	node* p = Head();
	while (p->next && p->data != value)
	{
		p = p->next;
	}
	if (p->next == nullptr) return false;
	return true;
}

//添加一个数
void List::Add_Value(int value)
{
	node* p = Head();
	if (!Check_Value(value))
	{
		while (p->next)
		{
			p = p->next;
		}
		p->next = new node;
		p->next->data = value;
		p->next->next = nullptr;
	}
	
}

//删除一个数
void List::Remove_Value(int value)
{
	node* p = Father_Node(value);
	if (p->next)
	{
		node* q = p->next;
		if (q->next)
		{
			p->next = q->next;
		}
		delete q;
	}
}
