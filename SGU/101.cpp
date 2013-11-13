// SGU 101 Domino
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 100005;
struct edge
{
	int u, v, index;
	edge(int _u, int _v, int _index)
	{
		u = _u;
		v = _v;
		index = _index;
	}
};
vector<edge> adj[MAX];
vector<int> ans;
bool mark[MAX];
void dfs(int v)
{
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i].u + adj[v][i].v - v, id = adj[v][i].index;
		if (mark[id])
			continue;
		mark[id] = true;
		dfs(u);
	}
	ans.push_back(v);
}
int main()
{
	ios::sync_with_stdio(false);
	int m;
	cin >> m;
	int t1 = 0;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(edge(u, v, i));
		adj[v].push_back(edge(u, v, i));
		t1 = u;
	}
	int t2 = -1;
	for (int i = 0; i < 7; i++)
		if (adj[i].size() % 2 == 1)
			t2 = i;
	if (t2 == -1)
		dfs(t1);
	else
		dfs(t2);
	memset(mark, false, sizeof(mark));
	vector<int> answer;
	string dir = "";
	for (int i = 1; i < ans.size(); i++)
	{
		int v = ans[i - 1], u = ans[i];
		for (int j = 0; j < adj[v].size(); j++)
		{
			int w = adj[v][j].u + adj[v][j].v - v, id = adj[v][j].index;
			if (mark[id])
				continue;
			if (w != u)
				continue;
			mark[id] = true;
			answer.push_back(id + 1);
			dir += (adj[v][j].v == u ? '+' : '-');
			break;
		}
	}
	if (answer.size() != m)
	{
		cout << "No solution";
		return 0;
	}
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " " << dir[i] << endl;
	return 0;
}
