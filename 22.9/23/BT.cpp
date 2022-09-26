#include<iostream>
#include<queue>
using namespace std;

struct Node {
	int val, ls, rs, cnt, siz;
}tree[500010];
int nodes;

void add(int x,int index)
{
	if (nodes == 0) { nodes = 1; tree[1].cnt = 1; tree[1].siz = 1; tree[1].val = x; }
	tree[index].siz++;
	if (x == tree[index].val) { tree[index].cnt++; return; }
	if (x < tree[index].val)//×ó×ÓÊ÷
	{
		if (tree[index].ls)	add(x, tree[index].ls);
		else
		{
			nodes++;
			tree[index].ls = nodes;
			tree[nodes].cnt = 1;
			tree[nodes].siz = 1;
			tree[nodes].val = x;
		}
	}
	else//ÓÒ×ÓÊ÷
	{
		if (tree[index].rs)	add(x, tree[index].rs);
		else
		{
			nodes++;
			tree[index].rs = nodes;
			tree[nodes].cnt = 1;
			tree[nodes].siz = 1;
			tree[nodes].val = x;
		}
	}

}

int findLast(int x,int val,int index)
{
	if (tree[index].val > x)
	{
		if (tree[index].ls) findLast(x, val, tree[index].ls);
		else return val;
	}
	else
	{
		if (tree[index].val> val)	val = x;
		if (tree[index].rs) findLast(x, val, tree[index].rs);
		else return val;
	}
}

int findNext(int x,int val,int index)
{
	if (tree[index].val <= x)
	{
		if (tree[index].rs) findNext(x, val, tree[index].rs);
		else return val;
	}
	else
	{
		if (tree[index].val < val)	val = x;
		if (tree[index].ls) findNext(x, val, tree[index].ls);
		else return val;
	}
}

int query(int x,int tot, int index)
{
	if (tot + tree[index].cnt > x) return tree[index].val;
	if (tot + tree[tree[index].ls].siz < x) return query(x, tot + tree[tree[index].ls].siz, tree[index].rs);
	return query(x, tot, tree[index].ls);
}

int getNum(int x, int tot, int index)
{
	if (tree[index].val > x) return tot;
	if (tree[index].ls == 0 && tree[index].rs==0) return tot+tree[index].cnt;
	if (tree[tree[index].rs].val < x) return getNum(x, tot + tree[tree[index].ls].siz + tree[index].cnt, tree[index].rs);
	return getNum(x, tot, tree[index].ls);
}


int q;
int op;
int x;

void in() 
{
	cin >> q;
}

void work() 
{
	while (q--)
	{
		cin >> op >> x;
		if (op == 1) cout<<getNum(x,0,1)<<endl;
		if (op == 2) cout<<query(x, 0, 1)<<endl;
		if (op == 3) cout<<findLast(x, -2147483647,1)<<endl;
		if (op == 4) cout<<findNext(x, -2147483647, 1)<<endl;
		if (op == 5) add(x,1);
	}
}

void output() 
{

}


int main()
{
	in();
	work();
	output();

	return 0;
}


/*





*/