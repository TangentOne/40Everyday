// P1015 [NOIP1999 普及组] 回文数
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n;
string m;
int num[100005];
int temp[100005];

void add(int* arr0, int& len, int jinzhi) {
	for (int i = 0; i < len; i++)
		temp[i] = arr0[i];
	for (int i = 0; i < len / 2; i++) {
		arr0[i] = arr0[i] + arr0[len - i - 1];
		arr0[len - i - 1] = arr0[i];
	}
	if (len % 2 != 0) arr0[len / 2] *= 2;
	int now_pos = 0;
	while (now_pos < len || arr0[now_pos]>0) {
		arr0[now_pos + 1] += (arr0[now_pos] / jinzhi);
		arr0[now_pos] = arr0[now_pos] % jinzhi;
		now_pos++;
	}
	if (now_pos >= len) len = now_pos;
	return;
}

bool check_huiwen(int* arr0, int& len) {
	for (int i = 0; i < len; i++) {
		if (arr0[i] != arr0[len - 1 - i])
			return false;
	}
	return true;
}


int main() {
	cin >> n >> m;
	memset(num, 0, sizeof(num));
	memset(temp, 0, sizeof(temp));
	int len = m.size();
	for (int i = 0; i < m.size(); i++) {
		if ('0' <= m[len - 1 - i] && '9' >= m[len - 1 - i])
			num[i] = m[len - 1 - i] - '0';
		else if (m[len-1-i]>='a')
			num[i] = m[len - 1 - i] - 'a' + 10;
		else
			num[i] = m[len - 1 - i] - 'A' + 10;
		temp[i] = num[i];
	}
	int xiugai_time = 0;
	while (xiugai_time<30) {
		if (check_huiwen(num, len)) {
			cout << "STEP=" << xiugai_time << endl;
			return 0;
		}
		add(num, len, n);
		xiugai_time++;
		if (check_huiwen(num, len)) {
			cout << "STEP=" << xiugai_time << endl;
			return 0;
		}
	}
	cout << "Impossible!\n";
	return 0;
}
