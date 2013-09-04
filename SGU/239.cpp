// SGU 239 Minesweeper
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
const int MAX = 1005;
int a[MAX], b[MAX], c[MAX];
int d(int i)
{
	int ans = 0;
	for (int j = i - 1; j <= i + 1; j++)
		if (b[j] == 1)
			ans++;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		c[i] = a[i];
	int ans = 0;
	bool check = true;
	b[0] = 2;
	b[n + 1] = 2;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i - 1; j <= i + 1; j++)
		{
			if (b[j] == 1)
				c[i]--;
			if (b[j] == 0)
			{
				if (c[i] == 0)
					b[j] = 2;
				else
				{
					c[i]--;
					b[j] = 1;
				}
			}
		}
		if (c[i] != 0)
			check = false;
	}
	ans += check;
	if (a[1] != 0)
	{
		check = true;
		memset(b, 0, sizeof(b));
		b[0] = 2;
		b[1] = 2;
		b[n + 1] = 2;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i - 1; j <= i + 1; j++)
			{
				if (b[j] == 1)
					a[i]--;
				if (b[j] == 0)
				{
					if (a[i] == 0)
						b[j] = 2;
					else
					{
						a[i]--;
						b[j] = 1;
					}
				}
			}
			if (a[i] != 0)
				check = false;
		}
		ans += check;
	}
	cout << ans;
 	return 0;
}
