#include<iostream>

using namespace std;

class Solution
{
public:
	int getSum(int n)   //1<=n<=1000
	{
		if (n == 1)
			return 1;
		if (n == 2)
			return 3;
		return(getSum(n - 1) + n);
	}
};

int main()
{
	int n;
	cin >>n;
	Solution s;
	cout << s.getSum(n);

}
