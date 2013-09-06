// SGU 175 Encoding
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
int pos(int n, int q)
{
	if (n == 1)
		return 1;
	int mid = n / 2;
	if (q < mid)
		return pos(mid, mid - q - 1) + n - mid;
	else
		return pos(n - mid, n - q - 1);
}
int main()
{
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	cout << pos(n, q - 1);
	return 0;
}
