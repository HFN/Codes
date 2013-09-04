// SGU 134 Centroid
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
const int MAX = 20000;
int size[MAX], answer[MAX], n;
vector <int> adj[MAX];
void dfs(int p, int v)
{
    size[v] = 1;
    answer[v] = 0;
    for (int i = 0; i < adj[v].size(); i++)
	{
        int u = adj[v][i];
        if (u != p) {
            dfs(v, u);
            size[v] += size[u];
            answer[v] = max(answer[v], size[u]);
        }
    }
    answer[v] = max(answer[v], n - size[v]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
	{
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, 1);
    int ans = INF;
    for (int i = 1; i <= n; i++)
    	ans = min(ans, answer[i]);
	int c = 0;
    for (int i = 1; i <= n; i++)
        if (answer[i] == ans)
            c++;
    cout << ans << " " << c << endl;
	for (int i = 1; i <= n; i++)
	    if (answer[i] == ans)
		cout << i << endl;
    cout << endl;
    return 0;
}
