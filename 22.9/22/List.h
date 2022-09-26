#ifndef LIST_H
#define LIST_H
#include<iostream>
using std::cerr;

struct Node
{
	Node(int x) { data = x; nxt = nullptr; }
	Node* nxt = nullptr;
	int data;
};

enum  InsertionWay
{
	IW_BEFORE, IW_AFTER
};

enum RemoveWay
{
	RW_EXACT, RW_BEFORE, RW_AFTER
};

class List
{
public:
	~List() {
		Node* p, * q;
		p = head;
		for (; p;) { q = p; p = p->nxt; delete q; }
	}
	List() :cnt(0) { head = new Node(-1); head->nxt = nullptr; };
	int getcnt()const { return cnt; }
	bool insert(int data, int whereData, InsertionWay way = IW_AFTER);
	bool remove(int whereData, RemoveWay way = RW_EXACT);
	bool push_front(int data);
	Node* getHead()const { return head; }
	void outputAll()const;

private:

	bool __insertionAfter(int data, Node* prev)
	{
		if (prev == nullptr) { cerr << "Empty Node!"; return 0; }
		if (prev->nxt == nullptr) { prev->nxt = new Node(data); cnt++; return 1; }
		Node* newNode = new Node(data);
		newNode->nxt = prev->nxt;
		prev->nxt = newNode;
		cnt++;
		return 1;
	}

	bool __deleteAfter(Node* prev)
	{
		if (prev == nullptr) { /*cerr << "Empty Node!"; exit(1);*/return 0; }
		if (prev->nxt == nullptr) { /*cerr << "Empty Node!";*/ return 0; }
		Node* deleteNode = prev->nxt;
		prev->nxt = prev->nxt->nxt;
		delete deleteNode;
		cnt--;
		return 1;
	}

	Node* __findFather(int data);
	Node* __findGrandFather(int data);


	Node* head;
	int cnt;

};

bool List::insert(int data, int whereData, InsertionWay way)
{
	if (way == InsertionWay::IW_AFTER)	{ return __insertionAfter(data, __findFather(whereData)->nxt);	}
	if (way == InsertionWay::IW_BEFORE) { return __insertionAfter(data, __findFather(whereData));		}
	return false;
}

bool List::remove(int whereData, RemoveWay way)
{
	if (way == RemoveWay::RW_EXACT)		{ return __deleteAfter(__findFather(whereData));		}
	if (way == RemoveWay::RW_BEFORE)	{ return __deleteAfter(__findGrandFather(whereData));	}
	if (way == RemoveWay::RW_AFTER)		{ return __deleteAfter(__findFather(whereData)->nxt);	}
	return false;

}

Node* List::__findFather(int data)
{
	Node* p = head;
	for (; (p->nxt) && p->nxt->data != data; p = p->nxt) {}
	if (p->nxt) return p;
	else return nullptr;
}

Node* List::__findGrandFather(int data)
{
	Node* p = head;
	for (; p->nxt && p->nxt->nxt && p->nxt->nxt->data != data; p = p->nxt) {}
	if (p->nxt && p->nxt->nxt) return p;
	else return nullptr;

	return p;
}

bool List::push_front(int data)
{
	if (head->nxt == nullptr) { head->nxt = new Node(data); cnt++; return true; }
	else {return __insertionAfter(data, head); }
}

void List::outputAll()const
{
	Node* p = head;
	for (Node* p = head->nxt; p; p = p->nxt) { std::cout << p->data << " "; }
}



#endif