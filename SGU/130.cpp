// SGU 130 Circle
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
const int MAX = 100;
ll c[MAX][MAX];
ll catalan(ll n)
{
	return c[2 * n][n] / (n + 1);
}
int main()
{
	ios::sync_with_stdio(false); 
	c[0][0] = 1;
	for (int n = 1; n < MAX; n++)
	{
		c[n][0] = 1;
		for (int r = 1; r < MAX; r++)
			c[n][r] = c[n - 1][r] + c[n - 1][r - 1];
	}
	ll n;
	cin >> n;
	cout << catalan(n) << " " << n + 1;
	return 0;
}
