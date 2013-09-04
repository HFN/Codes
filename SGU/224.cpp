// SGU 224 Little Queens
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
bool row[15], col[15], dil[25], dir[25];
int n, k, ans;
void bt(int t, int x, int y)
{
	if (t == k)
	{
		ans++;
		return;
	}
	for (int i = y; i < n; i++)
		for (int j = 0; j < n; j++)
			if ((!row[i]) && (!col[j]) && (!dil[i + (n - j)]) && (!dir[i + j]))
			{
				row[i] = true;
				col[j] = true;
				dil[i + (n - j)] = true;
				dir[i + j] = true;
				bt(t + 1, j, i);
				row[i] = false;
				col[j] = false;
				dil[i + (n - j)] = false;
				dir[i + j] = false;
			}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	bt(0, 0, 0);
	cout << ans;
 	return 0;
}
