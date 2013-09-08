// SGU 152 Making round
#include <iostream>
#include <cmath>
#define eps 0.000001
using namespace std;
const int MAX = 10000;
int a[MAX];
bool isint[MAX];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0; i < n; i++)
	{
		double x = ((double)a[i] * 100.0) / (double)sum;
		if (fabs(x - ceil(x)) < eps)
			isint[i] = true;
		a[i] = (int)x;
	}
	sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	for (int i = 0; sum < 100; i++)
		if (!isint[i])
		{
			a[i]++;
			sum++;
		}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
