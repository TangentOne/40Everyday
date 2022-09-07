#include<iostream>
#pragma warning(disable:4996)
using namespace std;

const int maxn = 1000000;
int a[maxn + 10];
int n, m;

int work(int l, int r, int num)
{
	if (l >= r) 
	{
		if (a[l] == num) return l;
		if (a[r] == num) return r;
		return -1;
	}
	int mid = l + (r - l) / 2;
	if (a[mid] >= num) return work(l, mid, num);
	if (a[mid] < num) return work(mid+1, r, num);

}

void in()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
	}
	while (m--)
	{
		int k;
		scanf("%d", &k);
		printf("%d ", work(1, n, k));
	}
}

int main()
{
	in();
}