#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdlib>
#include <stdexcept>
#include<cstring>
using namespace std;



int main()
{
	int arr[999];
	char a;
	int p = 0, now = 0;
	while ((a = getchar()) != '@')
	{
		if ('0' <= a && a <= '9')
		{
			now *= 10;
			now += a - '0';
		}
		else if (a == '.')
		{
			arr[p] = now;
			p++;
			now = 0;
		}
		else if (a == '+')
		{
			arr[p - 2] = arr[p-2] + arr[p - 1];
			arr[p-1] = 0;
			p --;
		}
		else if (a == '-')
		{
			arr[p - 2] = arr[p - 2] - arr[p - 1];
			arr[p - 1] = 0;
			p--;
		}
		else if (a == '*')
		{
			arr[p - 2] = arr[p - 2] *arr[p - 1];
			arr[p - 1] = 0;
			p--;
		}
		else if (a == '/')
		{
			arr[p - 2] = arr[p - 2] / arr[p - 1];
			arr[p - 1] = 0;
			p--;
		}
		
	}
	cout << arr[0];


	return 0;
}

