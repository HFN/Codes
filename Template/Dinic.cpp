#include <iostream>
#include <cstring>
#define prev def1
using namespace std;
const int MAXN = 2005;
const int MAXE = 505 * 505;
int to[MAXE * 2], cap[MAXE * 2], prev[MAXE * 2], ptr[MAXN], d[MAXN], q[MAXN], head[MAXN], ecnt;
void add_edge(int u, int v, int uv, int vu = 0)
{
	to[ecnt] = v, cap[ecnt] = uv, prev[ecnt] = head[u]; head[u] = ecnt++;
	to[ecnt] = u, cap[ecnt] = vu, prev[ecnt] = head[v]; head[v] = ecnt++;
}
bool bfs(int source, int sink)
{
	memset(d, 63, sizeof(d));
	int h = 0, t = 0;
	d[sink] = 0;
	q[t++] = sink;
	while (h < t)
	{
		int v = q[h++];
		for (int i = head[v]; i != -1; i = prev[i])
			if (cap[i ^ 1] > 0 && d[to[i]] > d[v] + 1)
			{
				d[to[i]] = d[v] + 1;
				q[t++] = to[i];
			}
	}
	return (d[source] < MAXN);
}
int dfs(int v, int sink, int flow = 2147483647)
{
	if (v == sink)
		return flow;
	int ans = 0;
	for (; ptr[v] != -1; ptr[v] = prev[ptr[v]])
		if (cap[ptr[v]] && d[v] == d[to[ptr[v]]] + 1)
		{
			int x = dfs(to[ptr[v]], sink, min(flow, cap[ptr[v]]));
			flow -= x;
			ans += x;
			cap[ptr[v]] -= x;
			cap[ptr[v] ^ 1] += x;
			if (flow == 0)
				break;
		}
	return ans;
}
int max_flow(int source, int sink)
{
	int ans = 0;
	while (bfs(source, sink))
	{
		memcpy(ptr, head, sizeof(head));
		ans += dfs(source, sink);
	}
	return ans;
}
void clear_flow()
{
	memset(head, -1, sizeof(head));
	ecnt = 0;
}
int main()
{
	ios::sync_with_stdio(false);
	clear_flow();
	
	return 0;
}
