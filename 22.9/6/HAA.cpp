#include "HAA.h"
#include<iostream>
using namespace std;

HugeInteger::HugeInteger() :num(0), f(1) {}
HugeInteger::HugeInteger(string ss) { input(ss); }
HugeInteger::HugeInteger(BigInteger x) : num(x), f(1) {}
HugeInteger::HugeInteger(int x) { input(x); }

void HugeInteger::input(string ss)
{
	if (ss[0] == '-') { f = -1; ss.erase(0, 1); }
	else f = 1;
	num = ss;
	return;
}

void HugeInteger::input(int x)
{
	if (x < 0) { f = -1; x = -x; }
	else f = 1;
	num = x;
}


extern ostream& operator << (ostream& out, const BigInteger& x) {
	out << x.s.back();
	for (int i = x.s.size() - 2; i >= 0; i--) {
		char buf[20];
		sprintf_s(buf, "%08d", x.s[i]);
		for (int j = 0; j < strlen(buf); j++) out << buf[j];
	}
	return out;
}

extern istream& operator >> (istream& in, BigInteger& x) {
	string s;
	if (!(in >> s)) return in;
	x = s;
	return in;
}

void HugeInteger::output()const
{
	if (!(~f))cout << "-";
	cout << num;
}

HugeInteger HugeInteger::add(const HugeInteger& rhs)const
{
	HugeInteger x(0);
	if (rhs.f == f)
	{
		x.f = f;
		x.num = num + rhs.num;
		return x;
	}

	if (~f) {				//代码复用！！！！
		//思路：f!=-1 => rhs.f=-1 a+b=*this-abs(rhs)
		x = x.substract(rhs); //x=abs(rhs.num)
		return substract(x);
	}
	else { return rhs.add(*this); }

}

HugeInteger HugeInteger::substract(const HugeInteger& rhs)const
{
	HugeInteger x(0);
	if (rhs.f != f)
	{
		x.num = num + rhs.num;
		x.f = f;
		return x;
	}
	BigInteger a, b;
	a = num; b = rhs.num;
	if (a < b) { x.f = (f == -1 ? 1 : -1); x.num = b - a; }
	else { x.f = f; x.num = a - b; }
	return x;
}

HugeInteger HugeInteger::multiply(const HugeInteger& rhs)const
{
	HugeInteger x;
	x.f = f * rhs.f;
	x.num = num * rhs.num;
	return x;
}

HugeInteger HugeInteger::divide(const HugeInteger& rhs)const
{
	HugeInteger x;
	x.f = f * rhs.f;
	x.num = num / rhs.num;
	return x;
}

HugeInteger HugeInteger::modulus(const HugeInteger& rhs)const
{
	HugeInteger x;
	x.f = f;
	x.num = num % rhs.num;
	return x;
}

bool HugeInteger::isEqualTo(const HugeInteger& rhs)const
{
	return ((num == 0) && (rhs.num == 0)) || ((*this).f == rhs.f) && ((*this).num == rhs.num);
}

bool HugeInteger::isNotEqualTo(const HugeInteger& rhs)const
{
	return !isEqualTo(rhs);
}

bool HugeInteger::isGreaterThan(const HugeInteger& rhs)const
{
	if (f != rhs.f) return f > rhs.f;
	if (~f) return num > rhs.num;
	else return num < rhs.num;
}

bool HugeInteger::isLessThan(const HugeInteger& rhs)const
{
	if (isEqualTo(rhs)) return 0;
	return !isGreaterThan(rhs);
}

bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger& rhs)const
{
	return !isLessThan(rhs);
}

bool HugeInteger::isLessThanOrEqualTo(const HugeInteger& rhs)const
{
	return !isGreaterThan(rhs);
}

bool HugeInteger::isZero()const
{
	return num == 0;
}


ostream& operator<<(ostream& os, const HugeInteger& x)
{
	if (!(~x.f))os << "-";
	os << x.num;
	return os;
}

