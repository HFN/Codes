// SGU 143 Long Live the Queen
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
const int MAX = 16001;
int w[MAX], size[MAX];
vector <int> adj[MAX];
void dfs(int p, int v)
{
	size[v] = w[v];
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (u != p)
		{
			dfs(v, u); 
			size[v] = max(size[v], size[v] + size[u]);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(-1, 1);
	int ans = -INF;
	for (int i = 1; i <= n; i++)
		ans = max(ans, size[i]);
	cout << ans << endl;
 	return 0;
}
