#include <iostream>
#include <cmath>
using namespace std;
const int LG = 20;
const int MAX = (1 << LG);
struct point
{
	long double real, imag;
	point() { real = imag = 0.0; }
	point(long double real, long double imag): real(real), imag(imag) {}
	point operator + (point b) { return point(real + b.real, imag + b.imag); }
	point operator - (point b) { return point(real - b.real, imag - b.imag); }
	point operator * (point b) { return point(real * b.real - imag * b.imag, real * b.imag + imag * b.real); }
	point operator * (long double b) { return point(real * b, imag * b); }
} a[MAX], b[MAX], c[MAX];
void fft(point *a, bool inv)
{
	for (int mask = 0; mask < MAX; mask++)
	{
		int rev = 0;
		for (int i = 0; i < LG; i++)
			if ((1 << i) & mask)
				rev |= (1 << (LG - i - 1));
		if (mask < rev)
			swap(a[mask], a[rev]);
	}
	for (int len = 2; len <= MAX; len *= 2)
	{
		long double ang = 2.0 * M_PI / len;
		if (inv)
			ang *= -1.0;
		point wn(cos(ang), sin(ang));
		for (int i = 0; i < MAX; i += len)
		{
			point w(1.0, 0.0);
			for (int j = 0; j < len / 2; j++)
			{
				point t1 = a[i + j] + w * a[i + j + len / 2];
				point t2 = a[i + j] - w * a[i + j + len / 2];
				a[i + j] = t1;
				a[i + j + len / 2] = t2;
				w = w * wn;
			}
		}
	}
	if (inv)
		for (int i = 0; i < MAX; i++)
			a[i] = a[i] * (1.0 / MAX);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].real;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> b[i].real;
	fft(a, false);
	fft(b, false);
	for (int i = 0; i < MAX; i++)
		c[i] = a[i] * b[i];
	fft(c, true);
	for (int i = 0; i < n + m - 1; i++)
		cout << c[i].real << " ";
	cout << "\n";
	return 0;
}
