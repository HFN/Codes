// SGU 105 Div 3
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
    ll n;
    cin >> n;
    if (n % 3 == 0)
       cout << n * 2 / 3;
    if (n % 3 == 1)
       cout << (n - 1) * 2 / 3;
    if (n % 3 == 2)
       cout << (n - 2) * 2 / 3 + 1;
	return 0;
}
