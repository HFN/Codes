// SGU 178 Golden chain
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
int main()
{
	ios::sync_with_stdio(false);
	ll n, now = 1, ans = 0;
	cin >> n;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	if (n == 2)
	{
		cout << 1;
		return 0;
	}
	while (n > now)
	{
		ans++;
		now = ((now + 1) / ans) * 2 * (ans + 1) - 1;
	}
	cout << ans;
	return 0;
}
