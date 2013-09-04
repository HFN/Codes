// SGU 223 Little Kings
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
ll dp[11][101][1024];
int n, k;
ll bt(int r, int t, int mask)
{
	bool b[12], a[12];
	memset(a, false, sizeof(a));
	memset(b, false, sizeof(b));
	bool ad = false;
	for (int i = mask, x = 1; i > 0; i >>= 1, x++)
		b[x] = i & 1; 
	for (int i = 1; i <= n; i++)
		if ((b[i] == b[i - 1]) && (b[i]))
			ad = true;
	if (ad)
		return 0;
	if (r == 0)
	{
		if (__builtin_popcount(mask) != t)
			return 0;
		else
			return 1;
	}
	ll &ret = dp[r][t][mask];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = i, x = 1; j > 0; j >>= 1, x++)
			a[x] = j & 1;
		bool check = true;
		for (int j = 1; j <= n; j++)
			if (b[j])
				if ((a[j - 1]) || (a[j]) || (a[j + 1]))
					check = false;
		if (check)
			ret += bt(r - 1, t - __builtin_popcount(mask), i);
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	cout << bt(n, k, 0);
 	return 0;
}
