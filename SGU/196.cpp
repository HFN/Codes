// SGU 196 Matrix Multiplication
#include <iostream>
using namespace std;
const int MAX = 10005;
int degree[MAX];
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		degree[u]++;
		degree[v]++;
	}
	long long ans = 0;
	for (int v = 1; v <= n; v++)
		ans += degree[v] * degree[v];
	cout << ans;
	return 0;
}
