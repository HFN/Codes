// SGU 103 Traffic Lights
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
const ll LONGINF = LLONG_MAX / 10000;
const int INF = INT_MAX;
const int MOD = 1000000007;
const int MAX = 305;
struct node
{
	bool p;
	int r, tb, tp;
	void add(bool pn, int rn, int tbn, int tpn)
	{
		p = pn;
		r = rn;
		tb = tbn;
		tp = tpn;
	}
};
node junc[MAX];
void prepare(ll time, node &n)
{
	if (time < n.r)
	{
		n.r -= time;
		if (n.r == 0)
		{
			if (n.p)
				n.r = n.tb;
			else
				n.r = n.tp;
		}
		return;
	}
	if (time == n.r)
	{
		n.r = 0;
		if (n.r == 0)
		{
			n.p = !n.p;
			if (n.p)
				n.r = n.tb;
			else
				n.r = n.tp;
		}
		return;
	}
	if (time > n.r)
	{
		time = (time - n.r) % (n.tb + n.tp);
		n.p = !n.p;
		if (n.p)
		{
			if (time < n.tb)
			{
				n.r = n.tb - time;
			}
			else
			{
				n.r = n.tp - (time - n.tb);
				n.p = !n.p;
			}
		}
		else
		{
			if (time < n.tp)
			{
				n.r = n.tp - time;
			}
			else
			{
				n.r = n.tb - (time - n.tp);
				n.p = !n.p;
			}
		}
	}
	if (n.r == 0)
	{
		if (n.p)
			n.r = n.tb;
		else
			n.r = n.tp;
	}
}
ll dist(int i, int j, ll time, ll len)
{
	node a = junc[i];
	node b = junc[j];
	prepare(time, a);
	prepare(time, b);
	if (a.p == b.p)
		return len;
	if (a.r != b.r)
		return len + min(a.r, b.r);
	len += a.r;
	a.r = 0;
	b.r = 0;
	a.p = !a.p;
	b.p = !b.p;
	if (a.p)
	{
		if (a.tb != b.tp)
			return len + (min(a.tb, b.tp));
		if (a.tp != b.tb)
			return len + (min(a.tp, b.tb));
	}
	else
	{
		if (a.tp != b.tb)
			return len + (min(a.tp, b.tb));
		if (a.tb != b.tp)
			return len + (min(a.tb, b.tp));
	}
	return LONGINF;
}
vector<int> adj[MAX], w[MAX];
ll prev[MAX], d[MAX];
set<pair<ll, ll> > s;
void dijkstra(int n)
{
	for (int i = 0; i < MAX; i++)
		d[i] = LONGINF;
	s.insert(make_pair(0, n));
	d[n] = 0;
	while(!s.empty())
	{
		ll v = s.begin()->y;
		s.erase(s.begin());
		for (int i = 0; i < adj[v].size(); i++)
		{
			ll u = adj[v][i];
			ll y = dist(v, u, d[v], w[v][i]);
			if (d[u] > d[v] + y)
			{
				prev[u] = v;
				s.erase(make_pair(d[u], u));
				d[u] = d[v] + y;
				s.insert(make_pair(d[u],u));
			}   	
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int start, finish;
	cin >> start >> finish;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		char c;
		int st, t1, t2;
		cin >> c >> st >> t1 >> t2;
		pair<int, int> time = make_pair(t1, t2);
		bool p = (c == 'B');
		junc[i].add(p, st, t1, t2);
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v, len;
		cin >> u >> v >> len;
		adj[u].push_back(v);
		adj[v].push_back(u);
		w[u].push_back(len);
		w[v].push_back(len);
	}
	dijkstra(start);
	if (d[finish] >= LONGINF)
	{
		cout << 0;
		return 0;
	}
	cout << d[finish] << endl;
	vector<int> answer;
	int v = finish;
	while (v != 0)
	{
		answer.push_back(v);
		v = prev[v];
	}
	reverse(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
}
