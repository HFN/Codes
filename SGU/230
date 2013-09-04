// SGU 230 Weighings
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
const int MAX = 101;
vector <int> adj[MAX];
int n, m, mark[MAX], w[MAX];
bool cycle;
void dfs(int v)
{
	mark[v] = 1;
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (mark[u] == 1)
			cycle = true;
		if (!mark[u])
			dfs(u);
	}
	mark[v] = 2;
}
void makegood(int v)
{
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (w[v] > w[u])
			swap(w[v], w[u]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
	{
		w[i] = i;
		if (!mark[i])
			dfs(i);
	}
	if (cycle)
	{
		cout << "No solution";
		return 0;
	}
	for (int k = 0; k < 100; k++)
		for (int i = 1; i <= n; i++)
			makegood(i);
	for(int i = 1; i <= n; i++)
		cout << w[i] << " ";
 	return 0;
}
