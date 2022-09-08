#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch>'9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
const int maxn = 100000;
int a[maxn + 10];
int b[maxn + 10];
int l, n, k;

void in()
{
    l = read(); n = read(); k = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    sort(a + 1, a + n + 1);
    a[n + 1] = l;
    for (int i = 1; i <= n; ++i) b[i] = a[i+1]-a[i];
    sort(b + 1, b + n + 1);
}

bool check(int x)
{
    int cnt = 0;
    for (int i = n; i >= 1; --i)
    {
        cnt += b[i] / x;
        if (b[i] % x == 0) cnt--;
        if (cnt > k) return 0;
    }
    return 1;
}


int search(int l, int r)
{
    if (l >= r)
    {
        if (check(r)) return r;
        if (check(l)) return l;
    }
    int mid = (l + r) / 2;
    if (check(mid)) return search(l,mid);
    else return search(mid+1,r);

}

void work()
{
    cout << search(1, l);
}


int main()
{
    in();
    work();
	return 0;
}