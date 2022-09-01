//Caesar cipher
#include<iostream>
using namespace std;

int main()
{
	string cipher;//密文
	int n;
	cout << "输入n:";
	cin >> n;
	n %= 26;
	cout << "输入密文:";
	cin >> cipher;
	int len = cipher.length();

	string plaintext;//明文
	plaintext.resize(len);

	for (int j = 0; j < len; ++j)
	{
		if (cipher[j] < 'a' || cipher[j] > 'z')
		{
			cout << "请输入小写字母" << endl;
		}
		else
		{
			if (cipher[j] + n >= 'a' && cipher[j] + n <= 'z')
			{
				plaintext[j] = cipher[j] + n;
			}
			else
			{
				plaintext[j] = 96 + (n - ('z' - cipher[j]));
			}
		}
	}

	cout << "解码后的明文为:" << plaintext;
	return 0;
}
