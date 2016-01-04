#include <iostream>
using namespace std;
const int MAX = 1000055;
int a[MAX], lg[MAX], rmq[17][MAX / 10], first[MAX / 10], mask[MAX / 10], ans[1 << 10][11][11];
int b[10];
void brute(int pos, int mask)
{
	if (pos == 10)
	{
		for (int l = 0; l < 10; l++)
			ans[mask][l][l + 1] = b[l];
		for (int len = 2; len <= 10; len++)
			for (int l = 0; l + len <= 10; l++)
			{
				int r = l + len;
				ans[mask][l][r] = min(ans[mask][l + 1][r], b[l]);
			}
		return;
	}
	b[pos] = b[pos - 1] + 1;
	brute(pos + 1, mask * 2);
	b[pos] = b[pos - 1] - 1;
	brute(pos + 1, mask * 2 + 1);
}
void init(int n)
{
	for (int i = 0; i < n; i++)
		if (i % 10)
		{
			rmq[0][i / 10] = min(rmq[0][i / 10], a[i]);
			mask[i / 10] *= 2;
			if (a[i] - a[i - 1] == -1)
				mask[i / 10]++;
		}
		else
		{
			first[i / 10] = a[i];
			rmq[0][i / 10] = a[i];
		}
	for (int i = 2; i <= n; i++)
		lg[i] = lg[i / 2] + 1;
	for (int i = 1; i < 17; i++)
		for (int j = 0; j < n; j++)
			rmq[i][j] = (j + (1 << (i - 1)) < n ? min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]) : rmq[i - 1][j]);
}
int rmq_min(int l, int r)
{
	if (l >= r)
		return 2147483647;
	return min(rmq[lg[r - l]][l], rmq[lg[r - l]][r - (1 << lg[r - l])]);
}
int get_min(int l, int r)
{
	if (l / 10 == r / 10)
		return first[l / 10] + ans[mask[l / 10]][l % 10][r % 10 + 1];
	return min(rmq_min(l / 10 + 1, r / 10), min(first[l / 10] + ans[mask[l / 10]][l % 10][10], first[r / 10] + ans[mask[r / 10]][0][r % 10 + 1]));
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	while (n % 10)
	{
		a[n] = a[n - 1] + 1;
		n++;
	}
	brute(1, 0);
	init(n);
	int q;
	cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		cout << get_min(l, r) << endl;
	}
	return 0;
}
