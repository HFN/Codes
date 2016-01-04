#include <algorithm>
#include <iostream>
using namespace std;
struct fract
{
	int num, den;
	void make_good()
	{
		int gcd = __gcd(abs(num), abs(den));
		num /= gcd;
		den /= gcd;
		if (den < 0)
		{
			num *= -1;
			den *= -1;
		}
	}
	fract(int _num = 0, int _den = 1)
	{
		num = _num;
		den = _den;
		make_good();
	}
	fract& operator = (fract b)
	{
		num = b.num;
		den = b.den;
		return *this;
	}
	bool operator == (fract b)
	{
		return (num * b.den == b.num * den);
	}
	bool operator != (fract b)
	{
		return (num * b.den != b.num * den);
	}
	bool operator < (fract b)
	{
		return (num * b.den < b.num * den);
	}
	bool operator > (fract b)
	{
		return (num * b.den > b.num * den);
	}
	bool operator <= (fract b)
	{
		return (num * b.den <= b.num * den);
	}
	bool operator >= (fract b)
	{
		return (num * b.den >= b.num * den);
	}
	fract operator + (fract b)
	{
		fract ans(num * b.den + b.num * den, den * b.den);
		ans.make_good();
		return ans;
	}
	fract operator - (fract b)
	{
		fract ans(num * b.den - b.num * den, den * b.den);
		ans.make_good();
		return ans;
	}
	fract operator * (fract b)
	{
		fract ans(num * b.num, den * b.den);
		ans.make_good();
		return ans;
	}
	fract operator / (fract b)
	{
		fract ans(num * b.den, den * b.num);
		ans.make_good();
		return ans;
	}
	fract operator += (fract b)
	{
		return *this = *this + b;
	}
	fract operator -= (fract b)
	{
		return *this = *this - b;
	}
	fract operator *= (fract b)
	{
		return *this = *this * b;
	}
	fract operator /= (fract b)
	{
		return *this = *this / b;
	}
};
ostream& operator << (ostream &out, fract b)
{
	out << b.num;
	if (b.den != 1)
		out << "/" << b.den;
	return out;
}
istream& operator >> (istream &in, fract &b)
{
	string s;
	in >> s;
	b.num = b.den = 0;
	int i, n = s.size();
	for (i = 0; i < n && s[i] != '/'; i++)
		b.num = b.num * 10 + s[i] - '0';
	if (s[i] == '/')
		i++;
	if (i == n)
		b.den = 1;
	else
	{
		for (; i < n; i++)
			b.den = b.den * 10 + s[i] - '0';
	}
	b.make_good();
	return in;
}
