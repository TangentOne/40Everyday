#ifndef DUALLIST_H
#define DUALLIST_H
#include<iostream>
using std::cerr;

struct DualNode
{
	DualNode(int x) { data = x; nxt = nullptr; pre = nullptr; }
	DualNode* nxt = nullptr;
	DualNode* pre = nullptr;
	int data;
};


enum InsertionWay
{
	IW_BEFORE, IW_AFTER
};

enum RemoveWay
{
	RW_EXACT, RW_BEFORE, RW_AFTER
};

class DualList
{
public:
	~DualList(){
		DualNode* p, * q;
		p = head;
		for (; p;){q = p;p = p->nxt;delete q;}
	}

	DualList():cnt(0) { head = new DualNode(-1); head->nxt = nullptr; head->pre = nullptr; };
	int getcnt()const { return cnt; }
	void insert(int data, int whereData, InsertionWay way = IW_AFTER);
	void remove(int whereData, RemoveWay way = RW_EXACT);
	void setHead(int data) { head->nxt = new DualNode(data); cnt = 1; }
	DualNode* getHead()const { return head; }

private:

	bool __insertionAfter(int data, DualNode* prev)
	{
		if (prev == nullptr) { cerr << "Empty Node!"; exit(1); }
		if (prev->nxt == nullptr) { prev->nxt = new DualNode(data); return 0; }
		DualNode* newNode = new DualNode(data);
		newNode->pre = prev;
		newNode->nxt = prev->nxt;
		prev->nxt->pre = newNode;
		prev->nxt = newNode;
		cnt++;
		return 1;
	}

	bool __deleteAfter(DualNode* father)
	{
		if (father == nullptr) { /*cerr << "Empty Node!"; exit(1);*/return 0; }
		if (father->nxt == nullptr) { cerr << "Empty Node!"; exit(1); }
		DualNode* deleteNode = father->nxt;
		father->nxt->nxt->pre = father;
		father->nxt = father->nxt->nxt;
		delete deleteNode;
		cnt--;
		return 1;
	}

	DualNode* __findFather(int data);
	DualNode* __findGrandFather(int data);


	DualNode* head;
	int cnt;

};

void DualList::insert(int data, int whereData, InsertionWay way)
{
	if (way == InsertionWay::IW_AFTER)	{ __insertionAfter(data, __findFather(whereData)->nxt); }
	if (way == InsertionWay::IW_BEFORE) { __insertionAfter(data, __findFather(whereData));		}
}

void DualList::remove(int whereData, RemoveWay way)
{
	if (way == RemoveWay::RW_EXACT)		{ __deleteAfter(__findFather(whereData));		}
	if (way == RemoveWay::RW_BEFORE)	{ __deleteAfter(__findGrandFather(whereData));	}
	if (way == RemoveWay::RW_AFTER)		{ __deleteAfter(__findFather(whereData)->nxt);	}

}

DualNode* DualList::__findFather(int data)
{
	DualNode* p = head;
	for (; (p->nxt) && p->nxt->data != data; p = p->nxt) {}
	if (p->nxt) return p;
	else return nullptr;
}

DualNode* DualList::__findGrandFather(int data)
{
	DualNode* p = head;
	for (; p->nxt && p->nxt->nxt && p->nxt->nxt->data != data; p = p->nxt) {}
	if (p->nxt && p->nxt->nxt) return p;
	else return nullptr;

	return p;
}


#endif