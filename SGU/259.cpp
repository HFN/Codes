// SGU 259 Printed PR
#include <algorithm>
#include <iostream>
#define l first
#define t second
using namespace std;
const int MAX = 100;
pair<int, int> a[MAX];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].t;
	for (int i = 0; i < n; i++)
		cin >> a[i].l;
	sort(a, a + n, greater<pair<int, int> >());
	int time = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		time += a[i].t;
		ans = max(ans, time + a[i].l);
	}
	cout << ans;
	return 0;
}
