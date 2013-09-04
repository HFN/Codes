// SGU 114 Telecasting station
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
    float ans = 0;
    int n, x, p, po = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> p;
        ans += x * p;
        po += p;
    }
    ans /= po;
    cout << ans;
    return 0;
}
