// SGU 127 Telephone directory
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
int c[10];
int main()
{
	ios::sync_with_stdio(false);
	int k, n;
	cin >> k >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		c[x / 1000]++;
	}
	int ans = 2;
	for (int i = 1; i < 10; i++)
		ans += ceil((double)c[i] / (double)k);
	cout << ans;
	return 0;
}
