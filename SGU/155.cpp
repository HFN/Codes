// SGU 155 Cartesian Tree
#include <algorithm>
#include <iostream>
#define bst first
#define heap second
using namespace std;
const int MAX = 100005;
pair<pair<int, int>, int> val[MAX];
int mn[25][MAX], lg[MAX], par[MAX], le[MAX], ri[MAX];
int get_min(int l, int r)
{
	int len = r - l;
	if (val[mn[lg[len]][l]].first.heap < val[mn[lg[len]][r - (1 << lg[len])]].first.heap)
		return mn[lg[len]][l];
	else
		return mn[lg[len]][r - (1 << lg[len])];
}
int solve(int p, int l, int r)
{
	if (r - l <= 0)
		return -1;
	int mid = get_min(l, r);
	par[val[mid].second] = p;
	le[val[mid].second] = solve(val[mid].second, l, mid);
	ri[val[mid].second] = solve(val[mid].second, mid + 1, r);
	return val[mid].second;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> val[i].first.bst >> val[i].first.heap;
		val[i].second = i;
	}
	sort(val, val + n);
	for (int i = 0; i < n; i++)
		mn[0][i] = i;
	for (int i = 2; i < MAX; i++)
		lg[i] = lg[i / 2] + 1;
	for (int i = 1; i < 25; i++)
		for (int j = 0; j < n; j++)
			if (j + (1 << (i - 1)) < n)
			{
				if (val[mn[i - 1][j]].first.heap < val[mn[i - 1][j + (1 << (i - 1))]].first.heap)
					mn[i][j] = mn[i - 1][j];
				else
					mn[i][j] = mn[i - 1][j + (1 << (i - 1))];
			}
			else
				mn[i][j] = mn[i - 1][j];
	solve(-1, 0, n);
	cout << "YES" << endl;
	for (int i = 0; i < n; i++)
		cout << par[i] + 1 << " " << le[i] + 1 << " " << ri[i] + 1 << endl;
	return 0;
}
