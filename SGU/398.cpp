// SGU 398 Friends of Friends
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
const int MAX = 51;
vector <int> adj[MAX];
queue <int> q;
int d[MAX], n, x;
void bfs()
{
	q.push(x);
	d[x] = 0;
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
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> x;
	for (int a = 1; a <= n; a++)
	{
		int d;
		cin >> d;
		for (int i = 0; i < d; i++)
		{
			int b;
			cin >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}
	memset(d, -1, sizeof(d));
	bfs();
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (d[i] == 2)
			ans++;
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
		if (d[i] == 2)
			cout << i << " ";
	return 0;
}
