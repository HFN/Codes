// SGU 186 The Chain
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
const int MAX = 103;
int l[MAX];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> l[i];
	sort(l, l + n, greater<int>());
	int last = n - 1, ans = 0;
	for (int i = 0; l[i + 1] != 0; i++, ans++)
	{
		l[last]--;
		if (l[last] == 0)
			last--;
	}
	cout << ans;
	return 0;
}
