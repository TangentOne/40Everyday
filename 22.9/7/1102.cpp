#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int n, m;
int maxa;
const int maxn = 1e6;
int a[maxn + 10];

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

bool check(int x)
{
    int tot = 0;
    for (int i = n; i >=1; --i)
    {
        tot += max(0, a[i] - x);
        if (tot >= m) return 1;
    }
    return 0;
}

int search(int l, int r)
{
    if (l >= r)
    {
        if (check(r)) return r;
        if (check(l)) return l;
    }
    int mid = (l+r+1) / 2;
    if (check(mid)) return search(mid, r);
    else return search(l,mid-1);
}

void in()
{
    n = read(); m = read();
    maxa = 0;
    for (int i = 1; i <= n; ++i) { a[i] = read(); }
    sort(a + 1, a + n + 1);
    maxa = a[n];
}

void work()
{
    cout << search(1, maxa);
}

int main()
{
    in();
    work();
}
