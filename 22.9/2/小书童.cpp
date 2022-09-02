#include<iostream>
using namespace std;
const int maxsize = 50+10;

char str[maxsize];
void letters(int n)
{
	for (int i = 0; i <strlen(str); i++)
	{
		int m=(int)str[i]+n%26;
		cout << (char)m;
	}
	
}
int main()
{
	int n;
	cin >> n >> str;
	letters(n);
	return 0;
}
