#include <iostream>
#include <cstring>
#include <set>
using namespace std;
const int MAXN = 3000;
const int MAXE = 6000;
int to[MAXE * 2], cap[MAXE * 2], cost[MAXE * 2], prev[MAXE * 2], head[MAXN], ecnt;
int d[MAXN], par[MAXN];
void add_edge(int u, int v, int cp, int ct)
{
	to[ecnt] = v, cap[ecnt] = cp, cost[ecnt] = ct, prev[ecnt] = head[u]; head[u] = ecnt++;
	to[ecnt] = u, cap[ecnt] = 0, cost[ecnt] = -ct, prev[ecnt] = head[v]; head[v] = ecnt++;
}
set<pair<int, int> > s;
pair<int, int> mcf(int source, int sink, int maxflow = 2147483647)
{
	int mc = 0, mf = 0;
	while (maxflow--)
	{
		memset(d, 63, sizeof(d));
		memset(par, -1, sizeof(par));
		d[source] = 0;
		s.insert(make_pair(d[source], source));
		while (!s.empty())
		{
			int v = s.begin()->second;
			s.erase(s.begin());
			for (int i = head[v]; i != -1; i = prev[i])
				if (cap[i] && d[to[i]] > d[v] + cost[i])
				{
					par[to[i]] = i;
					s.erase(make_pair(d[to[i]], to[i]));
					d[to[i]] = d[v] + cost[i];
					s.insert(make_pair(d[to[i]], to[i]));
				}
		}
		if (par[sink] == -1)
			break;
		mf++;
		int v = sink;
		while (v != source)
		{
			int id = par[v];
			cap[id]--;
			cap[id ^ 1]++;
			mc += cost[id];
			v = to[id ^ 1];
		}
	}
	return make_pair(mc, mf);
}
int main()
{
	ios::sync_with_stdio(false);
	memset(head, -1, sizeof(head));
	
	return 0;
}
