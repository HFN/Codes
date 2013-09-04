// SGU 149 Computer Network
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
const int MAX = 10001;
vector <int> adj[MAX];
vector <int> w[MAX];
int n, d1[MAX], d2[MAX];
bool mark[MAX];
void dfs(int v)
{
	mark[v] = true;
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (!mark[u])
		{
			d1[u] = d1[v] + w[v][i];
			dfs(u);
		}
	}
}
void init()
{
	for (int i = 0; i < MAX; i++)
		d2[i] = d1[i];
	memset(d1, 0, sizeof(d1));
	memset(mark, false, sizeof(mark));
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int a = 2; a <= n; a++)
	{
		int b, c;
		cin >> b >> c;
		adj[a].push_back(b);
		adj[b].push_back(a);
		w[a].push_back(c);
		w[b].push_back(c);
	}
	int v, u, mx;
	init();
	dfs(1);
	mx = -1;
	for (int i = 1; i <= n; i++)
		if (mx < d1[i])
		{
			mx = d1[i];
			v = i;
		}
	init();
	dfs(v);
	mx = -1;
	for (int i = 1; i <= n; i++)
		if (mx < d1[i])
		{
			mx = d1[i];
			u = i;
		}
	init();
	dfs(u);
	for (int i = 1; i <= n; i++) 
		cout << max(d1[i], d2[i]) << endl;
 	return 0;
}
