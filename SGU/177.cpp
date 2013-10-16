// SGU 177 Square
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
const int MAX = 5005;
struct query
{
	int x1, y1, x2, y2;
	char c;
} q[MAX];
set<int> s[MAX];
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			s[i].insert(j);
	for (int i = 0; i < m; i++)
	{
		cin >> q[i].x1 >> q[i].y1 >> q[i].x2 >> q[i].y2 >> q[i].c;
		if (q[i].x1 > q[i].x2)
		{
			swap(q[i].x1, q[i].x2);
			swap(q[i].y1, q[i].y2);
		}
	}
	reverse(q, q + m);
	int ans = 0;
	for (int k = 0; k < m; k++)
	{
		for (int i = q[k].x1; i <= q[k].x2; i++)
		{
			set<int>::iterator first, last;
			if (q[k].y1 <= q[k].y2)
			{
				first = s[i].lower_bound(q[k].y1);
				last = s[i].upper_bound(q[k].y2);
			}
			else
			{
				first = s[i].lower_bound(q[k].y2);
				last = s[i].upper_bound(q[k].y1);
			}
			for (set<int>::iterator it = first; it != last; it++)
				ans += (q[k].c == 'b');
			s[i].erase(first, last);
		}
	}
	ans = n * n - ans;
	cout << ans;
	return 0;
}
