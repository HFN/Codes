// SGU 151 Construct a triangle
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
#define sqr(x) ((x) * (x))
#define ll long long
#define x first
#define y second
using namespace std;
const ll LONGINF = LLONG_MAX;
const int INF = INT_MAX;
const int MOD = 1000000007;
int main()
{
	ios::sync_with_stdio(false);
	double b, c, m;
	cin >> c >> b >> m;
	if ((b + c < 2 * m) || (b + 2 * m < c) || (c + 2 * m < b))
	{
		cout << "Mission impossible" << endl;
		return 0;
	}
	double cx, cy;
	cx = (sqr(b) - sqr(c) + 4 * sqr(m)) / 4 / m;
	cy = sqrt(sqr(b) - sqr(cx));
	printf("0.00000 0.00000\n");
	printf("%0.5f %0.5f\n", 2 * m - cx, -cy);
	printf("%0.5f %0.5f\n", cx, cy);
	return 0;
}
