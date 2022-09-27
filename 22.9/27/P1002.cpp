#include<iostream>
using namespace std;
bool arr[25][25] = {};
long long num[25][25] = {};
long long dp(long long x, long long y)
{
	if (x == 0 && y == 0)
		return 1;
	if (x < 0 || y < 0)
		return 0;
	if (x > 0 && y > 0)
		if (arr[x - 1][y] && arr[x][y - 1])
			return 0;
	if (x > 0)
		if (arr[x - 1][y])
		{
			long long k= dp(x, y - 1);
			num[x][y] = k;
			return k;
		}
	if (y > 0)
		if (arr[x][y - 1])
		{
			long long k= dp(x - 1, y);
			num[x][y] = k;
			return k;
		}
	if (!num[x][y])
	{
		long long r = dp(x - 1, y) + dp(x, y - 1);
		num[x][y] = r;
		return r;
	}
	else return num[x][y];

}

int main()
{
	int endx, endy, mx, my;
	cin >> endx >> endy >> mx >> my;
	const int numx[9] = { 0,1,1,-1,-1,2,2,-2,-2 };
	const int numy[9] = { 0,2,-2,2,-2,1,-1,1,-1 };
	for (int i = 0;i < 9;i++)
	{
		if (mx + numx[i] >= 0 && my + numy[i] >= 0)
			arr[mx + numx[i]][my + numy[i]] = 1;
	}

	cout << dp(endx, endy);



	return 0;
}
