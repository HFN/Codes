// SGU 462 Electrician
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
const int MAX = 30010;
struct edge
{
	int a, b, r, p, index;
	void add(int aa, int ba, int ra, int pa, int indexa)
	{
		a = aa;
		b = ba;
		r = ra;
		p = pa;
		index = indexa;
	}
};
vector<edge> q;
map<int, int> m;
int size[MAX], parent[MAX];
int find(int v)
{
	if (parent[v] == v)
		return v;
	parent[v] = find(parent[v]); 
	return parent[v];
}
void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if (size[u] > size[v])
		swap(u, v);
	parent[u] = v;
	size[v] += size[u];
}
void init()
{
	for (int i = 0; i < MAX; i++)
	{
		size[i] = 1;
		parent[i] = i;
	}
}
bool comp(edge a, edge b)
{
	if (a.r != b.r)
		return (a.r > b.r);
	return (a.p > b.p);
}
bool comp2(edge a, edge b)
{
	if (a.r != b.r)
		return (a.r > b.r);
	return (a.p < b.p);
}
vector<int> answer;
ll ans;
int main()
{
	ios::sync_with_stdio(false);
	init();
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b, r, p, index = i + 1;
		cin >> a >> b >> r >> p;
		if (!m.count(a))
		{
			m[a] = cnt;
			cnt++;
		}
		if (!m.count(b))
		{
			m[b] = cnt;
			cnt++;
		}
		a = m[a];
		b = m[b];
		edge e;
		e.add(a, b, r, p, index);
		q.push_back(e);
	}
	sort(q.begin(), q.end(), comp);
 	for (int i = 0; i < q.size(); i++)
 	{
 		int u = q[i].a;
 		int v = q[i].b;
 		if (find(u) == find(v))
 			continue;
 		merge(u, v);
 		ans += (ll)q[i].p;
 	}
 	sort(q.begin(), q.end(), comp2);
 	cout << ans << endl;
 	for (int i = 0; i < q.size(); i++)
 		cout << q[i].index << " ";
	return 0;
}
