// SGU 163 Wise King
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
const int MAX = 1010;
int a[MAX];
int main()
{
	ios::sync_with_stdio(false);
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] = pow(a[i], p);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += (a[i] > 0) * a[i];
	cout << ans;
	return 0;
}
