// SGU 172 eXam
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
const int MAX = 201;
vector <int> adj[MAX];
bool mat[MAX][MAX];
int d[MAX];
queue <int> q;
void bfs(int n)
{
	q.push(n);
	d[n] = 0;
	while (!q.empty())
	{
		int v = q.front(); 
		q.pop();
		for (int i = 0; i < adj[v].size(); i++)
		{
			int u = adj[v][i];
			if (d[u] == -1)
			{
				d[u] = d[v] + 1;
				q.push(u);
			}
		}
	}
}
vector <int> a, b;
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		mat[a][b] = mat[b][a] = true;
	}
	memset(d, -1, sizeof(d));
	for (int i = 1; i <= n; i++)
		if (d[i] == -1)
			bfs(i);
	for (int i = 1; i <= n; i++)
		d[i] % 2 == 0 ? a.push_back(i) : b.push_back(i);
	bool check = true;
	for (int i = 0; i < a.size(); i++)
	{
		int v = a[i];
		for (int j = i + 1; j < a.size(); j++)
		{
			int u = a[j];
			if (mat[u][v])
				check = false;
		}
	}
	for (int i = 0; i < b.size(); i++)
	{
		int v = b[i];
		for (int j = i + 1; j < b.size(); j++)
		{
			int u = b[j];
			if (mat[u][v])
				check = false;
		}
	}
	if (check)
	{
		cout << "yes" << endl << a.size() << endl;
		for (int i = 0; i < a.size(); i++)
			cout << a[i] << " ";
	}
	else
		cout << "no";
 	return 0;
}
