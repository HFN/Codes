// SGU 184 Patties
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
int main()
{
    ios::sync_with_stdio(false);
    int p, m, c, k, r, v, n = 10001;
    cin >> p >> m >> c >> k >> r >> v;
    if (p / k < n)
       n = p / k;
    if (m / r < n)
       n = m / r;
    if (c / v < n)
       n = c / v;
    cout << n;
    return 0;
}
