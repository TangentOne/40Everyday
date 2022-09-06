#ifndef HAA_H
#define HAA_H

//High Accuracy Algorithm
#include <algorithm> // max
#include <cassert>   // assert
#include <cstdio>    // printf,sprintf
#include <cstring>   // strlen
#include <iostream>  // cin,cout
#include <string>    // string类
#include <vector>    // vector类
using namespace std;

struct BigInteger {
	typedef unsigned long long LL;

	static const int BASE = 100000000;
	static const int WIDTH = 8;
	vector<int> s;

	void _swap(BigInteger& a, BigInteger& b)
	{
		BigInteger c;
		c = a;
		a = b;
		b = c;
		return;
	}

	BigInteger& clean() { while (!s.back() && s.size() > 1)s.pop_back(); return *this; }
	BigInteger(LL num = 0) { *this = num; }
	BigInteger(string s) { *this = s; }
	BigInteger& operator = (long long num) {
		s.clear();
		do {
			s.push_back(num % BASE);
			num /= BASE;
		} while (num > 0);
		return *this;
	}
	BigInteger& operator = (const string& str) {
		s.clear();
		int x, len = (str.length() - 1) / WIDTH + 1;
		for (int i = 0; i < len; i++) {
			int end = str.length() - i * WIDTH;
			int start = max(0, end - WIDTH);
			sscanf_s(str.substr(start, end - start).c_str(), "%d", &x);
			s.push_back(x);
		}
		return (*this).clean();
	}

	BigInteger operator + (const BigInteger& b) const {
		BigInteger c; c.s.clear();
		for (int i = 0, g = 0; ; i++) {
			if (g == 0 && i >= s.size() && i >= b.s.size()) break;
			int x = g;
			if (i < s.size()) x += s[i];
			if (i < b.s.size()) x += b.s[i];
			c.s.push_back(x % BASE);
			g = x / BASE;
		}
		return c;
	}
	BigInteger operator - (const BigInteger& b) const {

		assert(b <= *this); // 减数不能大于被减数
		BigInteger c; c.s.clear();
		for (int i = 0, g = 0; ; i++) {
			if (g == 0 && i >= s.size() && i >= b.s.size()) break;
			int x = s[i] + g;
			if (i < b.s.size()) x -= b.s[i];
			if (x < 0) { g = -1; x += BASE; }
			else g = 0;
			c.s.push_back(x);
		}
		return c.clean();
	}
	BigInteger operator * (const BigInteger& b) const {
		int i, j; LL g;
		vector<LL> v(s.size() + b.s.size(), 0);
		BigInteger c; c.s.clear();
		for (i = 0; i < s.size(); i++) for (j = 0; j < b.s.size(); j++) v[i + j] += LL(s[i]) * b.s[j];
		for (i = 0, g = 0; ; i++) {
			if (g == 0 && i >= v.size()) break;
			LL x = v[i] + g;
			c.s.push_back(x % BASE);
			g = x / BASE;
		}
		return c.clean();
	}
	BigInteger operator / (const BigInteger& b) const {
		assert(b > 0);  // 除数必须大于0
		BigInteger c = *this;       // 商:主要是让c.s和(*this).s的vector一样大
		BigInteger m;               // 余数:初始化为0
		for (int i = s.size() - 1; i >= 0; i--) {
			m = m * BASE + s[i];
			c.s[i] = bsearch(b, m);
			m -= b * c.s[i];
		}
		return c.clean();
	}
	BigInteger operator % (const BigInteger& b) const { //方法与除法相同
		BigInteger c = *this;
		BigInteger m;
		for (int i = s.size() - 1; i >= 0; i--) {
			m = m * BASE + s[i];
			c.s[i] = bsearch(b, m);
			m -= b * c.s[i];
		}
		return m;
	}
	// 二分法找出满足bx<=m的最大的x
	int bsearch(const BigInteger& b, const BigInteger& m) const {
		int L = 0, R = BASE - 1, x;
		while (1) {
			x = (L + R) >> 1;
			if (b * static_cast<LL>(x) <= m) { if (b * (static_cast<LL>(x) + 1) > m) return x; else L = x; }
			else R = x;
		}
	}
	BigInteger& operator += (const BigInteger& b) { *this = *this + b; return *this; }
	BigInteger& operator -= (const BigInteger& b) { *this = *this - b; return *this; }
	BigInteger& operator *= (const BigInteger& b) { *this = *this * b; return *this; }
	BigInteger& operator /= (const BigInteger& b) { *this = *this / b; return *this; }
	BigInteger& operator %= (const BigInteger& b) { *this = *this % b; return *this; }

	bool operator < (const BigInteger& b) const {
		if (s.size() != b.s.size()) return s.size() < b.s.size();
		for (int i = s.size() - 1; i >= 0; i--)
			if (s[i] != b.s[i]) return s[i] < b.s[i];
		return false;
	}
	bool operator >(const BigInteger& b) const { return b < *this; }
	bool operator<=(const BigInteger& b) const { return !(b < *this); }
	bool operator>=(const BigInteger& b) const { return !(*this < b); }
	bool operator!=(const BigInteger& b) const { return b < *this || *this < b; }
	bool operator==(const BigInteger& b) const { return !(b < *this) && !(b > *this); }
};





//使用接口方法对原有的BigInteger类进行拓展
class HugeInteger {
public:
	HugeInteger();
	HugeInteger(string);
	HugeInteger(int);
	HugeInteger(BigInteger x);
	void input(string);
	void input(int x);
	void output()const;
	HugeInteger add(const HugeInteger&)const;
	HugeInteger substract(const HugeInteger&)const;
	HugeInteger multiply(const HugeInteger&)const;
	HugeInteger divide(const HugeInteger&)const;
	HugeInteger modulus(const HugeInteger&)const;
	bool isEqualTo(const HugeInteger&)const;
	bool isNotEqualTo(const HugeInteger&)const;
	bool isGreaterThan(const HugeInteger&)const;
	bool isLessThan(const HugeInteger&)const;
	bool isGreaterThanOrEqualTo(const HugeInteger&)const;
	bool isLessThanOrEqualTo(const HugeInteger&)const;
	bool isZero()const;

	HugeInteger operator=(const string& ss) { input(ss); return*this; }
	HugeInteger operator+(const HugeInteger& rhs) const { return add(rhs); }
	HugeInteger operator-(const HugeInteger& rhs) const { return substract(rhs); }
	HugeInteger operator*(const HugeInteger& rhs) const { return multiply(rhs); }
	HugeInteger operator/(const HugeInteger& rhs) const { return divide(rhs); }
	HugeInteger operator%(const HugeInteger& rhs) const { return modulus(rhs); }

	HugeInteger& operator+=(const HugeInteger& rhs) { *this = add(rhs); return*this; }
	HugeInteger& operator-=(const HugeInteger& rhs) { *this = substract(rhs); return*this; }
	HugeInteger& operator*=(const HugeInteger& rhs) { *this = multiply(rhs); return*this; }
	HugeInteger& operator/=(const HugeInteger& rhs) { *this = divide(rhs); return*this; }
	HugeInteger& operator%=(const HugeInteger& rhs) { *this = modulus(rhs); return*this; }

	bool operator == (const HugeInteger& rhs) const { return isEqualTo(rhs); }
	bool operator != (const HugeInteger& rhs) const { return isNotEqualTo(rhs); }
	bool operator < (const HugeInteger& rhs) const { return isLessThan(rhs); }
	bool operator > (const HugeInteger& rhs) const { return isGreaterThan(rhs); }
	bool operator <= (const HugeInteger& rhs) const { return isLessThanOrEqualTo(rhs); }
	bool operator >= (const HugeInteger& rhs) const { return isGreaterThanOrEqualTo(rhs); }

	friend ostream& operator<<(ostream&, const HugeInteger&);
	friend istream& operator>>(istream&, const HugeInteger&);



private:
	BigInteger num;
	int f;
};









#endif