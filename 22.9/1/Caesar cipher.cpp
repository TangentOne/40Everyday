//Caesar cipher
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int len;
	cout << "输入密文长度:";
	cin>>len;
	int n;
	cout << "输入n:";
	cin >> n;

	vector<char> cipher(len);//密文
	cout << "输入密文:";
	for (int i = 0; i < len; ++i)
	{
		cin >> cipher[i];
	}

	vector<char> plaintext(len);//明文
	for (int j = 0; j < len; ++j)
	{
		if (cipher[j] < 97 || cipher[j] > 122)
		{
			cout << "请输入小写字母" << endl;
		}
		else
		{
			plaintext[j] = cipher[j] + n;
			if (plaintext[j] > 122)
			{
				plaintext[j] -= 26;
			}
		}
	}

	cout << "解码后的明文为:";
	for (int k = 0; k < len; ++k)
	{
		cout << plaintext[k];
	}
}
