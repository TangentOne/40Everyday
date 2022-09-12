#include<iostream>
#include<ctime>
using namespace std;

int n;
const int maxn = 200000;
int A[maxn] = {0,-6,-4,-3,-2,-1,0,2,3,6,7,10,12,13,15};

int check(int index) { return A[index] - index; }

int search(int l, int r)
{
	if (l >= r)
	{
		if (check(l) != 0 && check(r) != 0) return -1;
		if (check(l) == 0)return l;
		if (check(r) == 0)return r;
	}

	int mid = (r - l) / 2 + l;
	if (check(mid) >= 0) return search(l,mid);
	else return search(mid+1,r);

}

void work()
{
	cout<<search(1, n)<<endl;
}

int main()
{
	n=14;
	//cin >> n;
	//for (int i = 1; i <= n; ++i) cin >> A[i];
	time_t begin, end;
	begin = clock();
	work();
	end = clock();
	cout << end - begin;

	

	
	return 0;
}