// SGU 144 Meeting
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
    double x, y, z;
    cin >> x >> y >> z;
    printf("%0.7f", 1 - sqr(abs(x - y) - z / 60) / sqr(x - y));
    return 0;
}
