// SGU 507 Treediff
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
const int MAX = 50500;
vector<int> adj[MAX];
vector<pair<int, int> > q;
multiset<int> s[MAX];
int d[MAX], upd[MAX], answer[MAX], size[MAX];
int n, m;
void dfs(int p, int v)
{
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (u == p)
			continue;
		d[u] = d[v] + 1;
		dfs(v, u);
	}
}
void solve()
{
	for (int i = 1; i <= n; i++)
		q.push_back(make_pair(d[i], i));
	sort(q.begin(), q.end(), greater<pair<int, int> >());
	for (int i = 0; i < q.size(); i++)
	{
		int v = q[i].y;
		if (v >= n - m + 1)
		{
			s[v].insert(answer[v]);
			answer[v] = INF;
			upd[v] = v;
			size[v] = 1;
			continue;
		}
		for (int j = 0; j < adj[v].size(); j++)
		{
			int u = adj[v][j];
			if (d[u] < d[v])
				continue;
			answer[v] = min(answer[v], answer[u]);
			if (size[v] < size[u])
			{
				size[v] = size[u];
				upd[v] = upd[u];
			}
		}
		for (int j = 0; j < adj[v].size(); j++)
		{
			int u = adj[v][j];
			if (d[u] < d[v])
				continue;
			if (upd[u] == upd[v])
				continue;
			s[upd[v]].insert(s[upd[u]].begin(), s[upd[u]].end());
			size[v] += size[u];
		}
		if ((adj[v].size() == 2) && (v != 1))
			continue;
		if (answer[v] == 0)
			continue;
		int prev, now;
		for (multiset<int>::iterator it = s[upd[v]].begin(); it != s[upd[v]].end(); it++)
		{
			if (it == s[upd[v]].begin())
			{
				prev = *it;
				continue;
			}
			now = *it;
			answer[v] = min(answer[v], now - prev);
			prev = now;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	for (int i = 0; i < MAX; i++)
		answer[i] = INF;
	cin >> n >> m;
	for (int a = 2; a <= n; a++)
	{
		int b;
		cin >> b;
		adj[b].push_back(a);
		adj[a].push_back(b);
	}
	for (int i = n - m + 1; i <= n; i++)
		cin >> answer[i];
	dfs(-1, 1);
	solve();
	for (int i = 1; i <= n - m; i++)
		cout << answer[i] << " ";
	return 0;
}
