// SGU 125 Shtirlits
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#define ll long long
#define x first
#define y second
using namespace std;
const ll LONGINF = LLONG_MAX;
const int INF = INT_MAX;
const int MOD = 1000000007;
int n;
int a[9];
int b[3][3];
int w[5][5];
int d(int y, int x)
{
	int ans = 0;
	if (w[y][x] < w[y - 1][x])
		ans++;
	if (w[y][x] < w[y + 1][x])
		ans++;
	if (w[y][x] < w[y][x - 1])
		ans++;
	if (w[y][x] < w[y][x + 1])
		ans++;
	return ans;
}
void f(int k)
{
	if (k == n * n)
	{
		for (int i = 0; i < n * n; i++)
			w[i / n + 1][(i % n) + 1] = a[i];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (d(i, j) != b[i - 1][j - 1])
					return;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				cout << w[i][j] << " ";
			cout << endl;
		}
		exit(0);
	}
	for (int i = 1; i <= 5; i++)
	{
		a[k] = i;
		f(k + 1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			w[i][j] = -1;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> b[i][j];
	f(0);
	cout << "NO SOLUTION";
	return 0;
}
