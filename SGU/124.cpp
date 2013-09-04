// SGU 124 Broken line
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
#define point pair<double, double>
#define x first
#define y second
using namespace std;
const ll LONGINF = LLONG_MAX;
const int INF = INT_MAX;
const int MOD = 1000000007;
const int MAX = 10005;
struct line
{
	point a, b;
} l[MAX];
double ccw(point a, point b, point c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) / 2;
}
bool intersect(line l1, line l2) 
{
	double test1 = ccw(l1.a, l1.b, l2.a) * ccw(l1.a, l1.b, l2.b);
	double test2 = ccw(l2.a, l2.b, l1.a) * ccw(l2.a, l2.b, l1.b);
	return ((test1 < 0) && (test2 < 0));
}
bool isonline(line l, point p)
{
	if (p.y > max(l.a.y, l.b.y))
		return false;
	if (p.y < min(l.a.y, l.b.y))
		return false;
	if (p.x > max(l.a.x, l.b.x))
		return false;
	if (p.x < min(l.a.x, l.b.x))
		return false;
	return (ccw(l.a, l.b, p) == 0);
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		point a, b;
		cin >> a.x >> a.y >> b.x >> b.y;
		l[i].a = a;
		l[i].b = b;
	}
	point p;
	cin >> p.x >> p.y;
	for (int i = 0; i < n; i++)
		if (isonline(l[i], p))
		{
			cout << "BORDER";
			return 0;
		}
	point r;
	r.x = -10100;
	r.y = p.y - 1;
	line ray;
	ray.a = r;
	ray.b = p;
	int num = 0;
	for (int i = 0; i < n; i++)
		num += intersect(ray, l[i]);
	cout << (num % 2 == 0 ? "OUTSIDE" : "INSIDE");
	return 0;
}
