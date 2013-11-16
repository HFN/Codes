// SGU 174 Walls
#include <iostream>
#include <map>
#define x first
#define y second
using namespace std;
const int MAX = 400005;
int par[MAX];
int find(int v)
{
	return (par[v] == v ? v : par[v] = find(par[v]));
}
void merge(int u, int v)
{
	par[find(u)] = find(v);
}
map<pair<int, int>, int> m;
int main()
{
	ios::sync_with_stdio(false);
	for (int i = 0; i < MAX; i++)
		par[i] = i;
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		pair<int, int> s, t;
		cin >> s.x >> s.y >> t.x >> t.y;
		if (!m.count(s))
			m[s] = cnt++;
		if (!m.count(t))
			m[t] = cnt++;
		s.x = m[s];
		t.x = m[t];
		if (find(s.x) == find(t.x))
		{
			cout << i + 1;
			return 0;
		}
		merge(s.x, t.x);
	}
	cout << 0;
	return 0;
}
