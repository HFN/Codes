// SGU 180 Inversions
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
const int MAX = 100000;
ll a[MAX];
ll answer;
void merge(int a1, int b1, int a2, int b2)
{
	vector<int> ans, t1, t2;
	for (int i = a1; i <= b1; i++)
		t1.push_back(a[i]);
	t1.push_back(INF);
	for (int i = a2; i <= b2; i++)
		t2.push_back(a[i]);
	t2.push_back(INF);
	ll i = 0, j = 0, cnt = 0;
	while ((t1[i] != INF) || (t2[j] != INF))
		if (t1[i] <= t2[j])
		{
			ans.push_back(t1[i]);
			i++;
			answer += cnt;
		}
		else
		{
			ans.push_back(t2[j]);
			j++;
			cnt++;
		}
	i = 0;
	int p;
	for (p = a1; p <= b1; p++, i++)
		a[p] = ans[i];
	for (p = a2; p <= b2; p++, i++)
		a[p] = ans[i];
}
void merge_sort(int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	merge_sort(left, mid);
	merge_sort(mid + 1, right);
	merge(left, mid, mid + 1, right);
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	merge_sort(0, n - 1);
	cout << answer;
	return 0;
}
